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
	// t_container	container;

	// container.name = "cube3d";
	// init(&container);
	// int a;
	// int d;
	// a = 0;
	// d = map_dim(&a, av[1], len_x);
	// printf("d = %d\n", d);
	// printf("a = %d\n", a);

	t_map_creation	*m;
	// m = ft_calloc(1, sizeof(t_map_creation ));
	// m->file = av[1];

	int i = 0;
	int j = 0;

	if (ft_map(m, av) == NULL)
	{
		ft_putstr_fd("Error main 55\n", 2);
		return (1);
	}
	else
	{
		// ft_putchar_fd(m->my_map[1][2], 1);
		ft_putstr_fd("\n\n\n################## DRAW ###################\n\n\n", 1);

		while (i < m->dim[0])
		{

			while (j < m->dim[1])
			{

				ft_putchar_fd(m->my_map[i][j], 1);
				ft_putchar_fd(' ', 1);
				j++;
			}
			i++;
			j = 0;
		}
	}
	return (0);
}

