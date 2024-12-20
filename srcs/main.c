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
	infos->map = map_init(infos->map, av);
	if (!infos->map)
		return (NULL);								//# ADD MESSAGE
	check_enclosure_map(&infos->map);
	infos->header = header_creation(av[1]);
	display_map(infos->map);							//* printer
	init_player(&infos);
	return (infos);
}

void	init_draw(t_launcher **launcher)
{
	t_container	*c;

	c = (*launcher)->c;
	c = ft_calloc(1, sizeof(t_container));
	c->mlx = mlx_init();
	if (!c->mlx)
		error_init();
	c->mlx_win = mlx_new_window(c->mlx, 1920, 1080, "Hello world!");
	if (!c->mlx_win)
		error_window(c);
	c->img.img = mlx_new_image(c->mlx, 1920, 1080);
	if (!c->img.img)
		error_image(c);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixel,
			&c->img.line_length,
			&c->img.endian);
	(*launcher)->c = c;

}

int	render(t_launcher *launcher)
{

	init_draw(&launcher);
	handle_event(&launcher);
	draw_wall(&launcher);
	render_player(&launcher);
	mlx_put_image_to_window(launcher->c->mlx, launcher->c->mlx_win, launcher->c->img.img, 0, 0);
	mlx_loop(launcher->c->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_launcher	*launcher;

	launcher = ft_calloc(1, sizeof(t_launcher));
	if (!launcher)
		return (1);


	(void) ac;
	launcher->i = init_infos(av, &launcher->i);
	if (!launcher->i)
		return (1);
	render(launcher);
	clean_header(launcher->i->header);
	clean_map(launcher->i->map);
	free(launcher->i);
	free(launcher);
	return (0);
}
