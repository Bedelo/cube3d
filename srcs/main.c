#include "./../includes/cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_infos	*init(char **av, t_infos **i)
{
	t_infos				*infos;

	infos = *i;
	infos = ft_calloc(1, sizeof(t_infos));
	infos->map = map_init(infos->map, av);
	check_enclosure_map(&infos->map);
	// display_map(infos->map);							//* printer
	infos->header = header_creation(av[1]);
	return (infos);
}

void	draw(t_infos *infos)
{
	t_container	*c;
	// t_data	img;

	c = ft_calloc(1, sizeof(t_container));
	c->mlx = mlx_init();
	c->mlx_win = mlx_new_window(c->mlx, 1920, 1080, "Hello world!");
	c->img.img = mlx_new_image(c->mlx, 1920, 1080);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bits_per_pixel,
			&c->img.line_length, &c->img.endian);
	my_mlx_pixel_put(&c->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	mlx_loop(c->mlx);
}

int	main(int ac, char **av)
{
	t_infos	*infos;

	(void) ac;
	infos = init(av, &infos);
	draw(infos);



	clean_header(infos->header);
	clean_map(infos->map);
	free(infos);

	return (0);
}
