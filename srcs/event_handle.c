#include "./../includes/cube3d.h"

int	close_window_x(t_container *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->mlx_win);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	exit(0);
}

int	events_window(int keysym, t_launcher **launcher)
{
	t_container	*c;
	t_infos	*infos;

	infos = (*launcher)->i;
	c = (*launcher)->c;
	if (keysym == XK_Escape)
		close_window_x(c);
	if (keysym == XK_A || keysym == XK_a)
		infos->player->px -= 1;
	if (keysym == XK_D || keysym == XK_d)
		infos->player->px += 1;
	if (keysym == XK_W || keysym == XK_w)
		infos->player->py += 1;
	if (keysym == XK_S || keysym == XK_s)
		infos->player->py -= 1;
	if (keysym == XK_Left)
		infos->player->angle -= PI / 18;
	if (keysym == XK_Right)
		infos->player->angle += PI / 18;
	return (0);
}

int	move_player(int keysym, t_launcher **l)
{

	return (0);
}

void	handle_event(t_launcher **launcher)
{
	t_container	*c;

	c = (*launcher)->c;
	mlx_hook(c->mlx_win, 17, 0, close_window_x, c);
	mlx_key_hook(c->mlx_win, events_window, launcher);
	// mlx_key_hook(c->mlx_win, move_player, launcher);
}
