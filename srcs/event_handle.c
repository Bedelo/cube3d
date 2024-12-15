#include "./../includes/cube3d.h"

int	close_window_x(t_container *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->mlx_win);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	exit(0);
}

int	visibility_hook(int event, t_container *c)
{
	if (event == 15)
		;
	return (1);
}

void	handle_event(t_container *c)
{
	mlx_hook(c->mlx_win, 17, 0, close_window_x, c);
}
