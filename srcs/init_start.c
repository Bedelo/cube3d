#include "./../includes/cube3d.h"


t_infos	*init_player(t_infos **i)
{
	t_infos	*infos;

	infos = *i;
	infos->player = ft_calloc(1, sizeof(t_player));
	if (!infos->player)								//# ADD MESSAGE
		return (NULL);
	*infos->player = (t_player){0};
	infos->player->px = infos->map->pos[0] * H_WALL + H_WALL / 2;
	infos->player->py = infos->map->pos[1] * W_WALL + W_WALL / 2;
	ajust_angle(infos);
	infos->player->move_utils.rot_dir = 0;
	infos->player->move_utils.ud_dir = 0;
	infos->player->move_utils.lr_dir = 0;
	return (infos);
}

t_raycast	*init_raycast(t_launcher *launcher)
{
	t_raycast	*raycast;

	raycast = ft_calloc(1, sizeof(t_raycast));  //# doublon
	if (!raycast)
		return (NULL);
	*raycast = (t_raycast){0};					//# doublon ??
	raycast->no = launcher->i->header->no;
	raycast->so = launcher->i->header->so;
	raycast->we = launcher->i->header->we;
	raycast->ea = launcher->i->header->ea;
	raycast->f_color = to_color_rc(launcher->i->header->f);
	if (raycast->f_color == -1)
		return (err(ERROR), err("Color floor issue !\n"), free(raycast), NULL);
	// printf("f: %u\n", raycast->f_color);
	raycast->c_color = to_color_rc(launcher->i->header->c);
	if (raycast->c_color == -1)
		return (err(ERROR), err("Color ceiling issue !\n"), free(raycast), NULL);
	raycast->dim_texture = (int){TEXTURE_DIM, TEXTURE_DIM};
	raycast->img = launcher->img;
	raycast->axis = init_axis(launcher);
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
	infos->map = map_init(infos->map, av);
	if (!infos->map)
		return ( free(infos), NULL);
	infos->header = header_creation(av[1]);
	if(!infos->header)
		return (clean_map(infos->map), free(infos), NULL);
	display_map(infos->map);
	infos = init_player(&infos);							//* printer
	if (!infos)
		return (free(infos->player), clean_header(infos->header), clean_map(infos->map), free(infos), NULL);
	return (infos);
}

void	init_draw(t_launcher **launcher)
{
	t_launcher	*c;

	c = (*launcher);
	c->mlx = mlx_init();
	if (!c->mlx)
		return (error_init(), free(c));
	c->mlx_win = mlx_new_window(c->mlx, 1920, 1080, "Cube3d");
	if (!c->mlx_win)
		return (error_window(c), free(c));
	c->img.img = mlx_new_image(c->mlx, 1920, 1080);
	if (!c->img.img)
		return (error_image(c), free(c));
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixel,
			&c->img.line_length,
			&c->img.endian);
	return ;
}

int	render(t_launcher *launcher)
{

	init_draw(&launcher);
	handle_event(&launcher);
	draw_wall(&launcher); //# ADD DRAW WALL MINIMAP
	// render_player(&launcher); //# ADD RENDER PLAYER MINIMAP
	mlx_put_image_to_window(launcher->mlx, launcher->mlx_win, launcher->img.img, 0, 0);
	mlx_loop(launcher->mlx);
	return (OK);
}
