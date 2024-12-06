#include "./../includes/cube3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init(t_container *container)
{
	container->mlx = mlx_init();
	ft_putstr_fd("1\n", 1);
	if (!container->mlx)
		error_init();
	container->win = mlx_new_window(container->mlx, SCR_WIDTH, SCR_HEIGHT, container->name);
	ft_putstr_fd("2\n", 1);
	if (!container->win)
		error_window(container);
	container->img.img = mlx_new_image(container->mlx, SCR_WIDTH, SCR_HEIGHT);
	ft_putstr_fd("3\n", 1);
	if (!container->img.img)
		error_image(container);
	container->img.addr = mlx_get_data_addr(container->img.img,
			&container->img.bits_per_pixel,
			&container->img.line_length,
			&container->img.endian);
}

int	main(int ac, char **av)
{
	(void)	ac;
	(void)	av;
	// t_container	container;

	// container.name = "cube3d";
	// init(&container);
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 720, 720, "cube3d");
	mlx_loop(mlx);


}
