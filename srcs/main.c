#include "./../includes/cube3d.h"

t_infos	*init_player(t_infos **i)
{
	t_infos	*infos;

	infos = *i;
	infos->player = ft_calloc(1, sizeof(t_player));
	if (!infos->player)								//# ADD MESSAGE
		return (NULL);
	infos->player->px = infos->map->pos[0] * H_WALL + H_WALL / 2;
	infos->player->py = infos->map->pos[1] * W_WALL + W_WALL / 2;
	infos->player->angle = 0;		//? ADD RADIAN ANGLE BY HEADER N S E W
	return (infos);
}


t_infos	*init_infos(char **av, t_infos **i)
{
	t_infos				*infos;

	infos = *i;
	infos = ft_calloc(1, sizeof(t_infos));
	if (!infos)
		return (NULL);
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
	render_player(&launcher); //# ADD RENDER PLAYER MINIMAP
	mlx_put_image_to_window(launcher->mlx, launcher->mlx_win, launcher->img.img, 0, 0);
	mlx_loop(launcher->mlx);
	return (OK);
}


int	main(int ac, char **av)
{
	t_launcher	*launcher;

	if (ac != 2)
		return (err("Enter valid map\n"), 1);
	launcher = ft_calloc(1, sizeof(t_launcher));
	if (!launcher)
		return (1);
	(void) ac;
	launcher->i = init_infos(av, &launcher->i);
	if (!launcher->i)
		return (free(launcher), 1);
	render(launcher);
	return (0);
}
