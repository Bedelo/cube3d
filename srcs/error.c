#include "./../includes/cube3d.h"

void	error_init(void)
{
	ft_putstr_fd(ERROR_INITIALISATION, 2);
	exit(1);
}
void	error_window(t_container *container)
{
	mlx_destroy_display(container->mlx);
	free(container->img.img);
	free(container->mlx);
	ft_putstr_fd("error: windows: ", 2);
	error_init();
}
void	error_image(t_container *container)
{
	mlx_destroy_window(container->mlx, container->win);
	mlx_destroy_display(container->mlx);
	free(container->img.img);
	free(container->mlx);
	ft_putstr_fd("error: image: ", 2);
	error_init();
}
void err(char *str)
{
	while(*str)
		write(2, str++, 1);
}
