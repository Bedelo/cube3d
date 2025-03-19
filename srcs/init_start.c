/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:51 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/19 15:50:52 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

t_infos	*init_player(t_infos **i)
{
	t_infos	*infos;
	int		x;
	int		y;

	infos = *i;
	infos->player = ft_calloc(1, sizeof(t_player));
	if (!infos->player)
		return (err(ERROR), err("Error occurs when player creation!\n"), NULL);
	*infos->player = (t_player){0};
	infos->player->px = infos->map->pos[0];
	infos->player->py = infos->map->pos[1];
	infos->player->move = 1;
	return (infos);
}

t_raycast	*init_raycast(t_launcher *launcher)
{
	t_raycast	*raycast;

	raycast = ft_calloc(1, sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->axis = init_axis(launcher, raycast);
	if (!raycast->axis)
		return (err(ERROR), err("Init axis error!\n"), free(raycast), NULL);
	raycast->no = launcher->i->header->no;
	raycast->so = launcher->i->header->so;
	raycast->we = launcher->i->header->we;
	raycast->ea = launcher->i->header->ea;
	raycast->f_color = to_color_rc(launcher->i->header->f);
	if (raycast->f_color == -1)
		return (err(ERROR), err("Color floor issue!\n"), free(raycast), NULL);
	raycast->c_color = to_color_rc(launcher->i->header->c);
	if (raycast->c_color == -1)
		return (err(ERROR), err("Color ceiling issue!\n"), free(raycast), NULL);
	return (raycast);
}

t_infos	*init_infos(char **av, t_infos **i)
{
	t_infos				*infos;

	infos = *i;
	infos = ft_calloc(1, sizeof(t_infos));
	if (!infos)
		return (NULL);
	*infos = (t_infos){0};
	infos->header = header_creation(av[1]);
	if (!infos->header)
		return (free(infos), NULL);
	infos->map = map_init(infos->map, av);
	if (!infos->map)
		return (clean_header(infos->header), free(infos), NULL);
	infos = init_player(&infos);
	if (!infos)
		return (free(infos->player), clean_header(infos->header),
			clean_map(infos->map), free(infos), NULL);
	return (infos);
}

void	init_draw(t_launcher **launcher)
{
	t_launcher	*c;

	c = (*launcher);
	c->mlx = mlx_init();
	if (!c->mlx)
		return (error_init(), free(c));
	c->mlx_win = mlx_new_window(c->mlx, SCR_HEIGHT, SCR_WIDTH, "Cube3d");
	if (!c->mlx_win)
		return (error_window(c), free(c));
	c->img.img = mlx_new_image(c->mlx, SCR_HEIGHT, SCR_WIDTH);
	if (!c->img.img)
		return (error_image(c), free(c));
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixel,
			&c->img.line_length,
			&c->img.endian);
	return ;
}

int	render(t_launcher *ptr)
{
	ptr->i->map->map_h = ptr->i->map->dim[1];
	ptr->i->map->map_w = ptr->i->map->dim[0];
	// printf("ptr->i->map->map_h = [%d]\tptr->i->map->map_w = [%d]\n", ptr->i->map->map_h, ptr->i->map->map_w);
	init_draw(&ptr);
	init_textures(ptr);
	handle_event(ptr);
	mlx_loop_hook(ptr->mlx, (void *)draw_cube3d, ptr);
	mlx_loop(ptr->mlx);
	return (OK);
}
