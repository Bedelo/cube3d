#include "./../includes/cube3d.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


t_infos	*init(char **av, t_infos **i)
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
	return (infos);
}

void	draw(t_container *c, t_infos *infos)
{

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
	draw_wall(c, infos);
	mlx_loop(c->mlx);

}

int	main(int ac, char **av)
{
	t_infos	*infos;
	t_container	*c;
	char position[2];
	(void) ac;

	infos = init(av, &infos);
	if (!infos)
		return (1);
	printf("position y: %d\n", infos->map->pos[1]);
	// draw(c, infos);




	clean_header(infos->header);
	clean_map(infos->map);
	free(infos);

	return (0);
}
