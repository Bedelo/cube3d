#include "./../includes/cube3d.h"

int	close_window_x(t_launcher *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->mlx_win);
	mlx_destroy_display(c->mlx);
	free(c->name);
	free(c->mlx);
	free(c->i->player);
	clean_map(c->i->map);
	clean_header(c->i->header);
	free(c->i);
	free(c);
	exit(0);
}

void	rotate_move_on(int keysym, t_infos *infos)
{
	if (keysym == XK_e || keysym == XK_E)
	{
		infos->player->move_utils.rot_dir = -1;
		infos->player->angle +=  ROT_SPEED * infos->player->move_utils.rot_dir;
	}
	if (keysym == XK_a|| keysym == XK_A)
	{
		infos->player->move_utils.rot_dir = 1;
		infos->player->angle +=  ROT_SPEED * infos->player->move_utils.rot_dir;
	}
}

void move_on(int keysym, t_infos *infos, t_launcher *c)
{
	if (keysym == XK_s || keysym == XK_S)
	{
		infos->player->move_utils.ud_dir = 1;
		infos->player->px += cos(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
		infos->player->py += sin(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
	}
	// if (keysym == XK_z || keysym == XK_Z)
	// {
	// 	infos->player->move_utils.ud_dir = -1;
	// 	infos->player->px += cos(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
	// 	infos->player->py += sin(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
	// }
	if (keysym == XK_d || keysym == XK_D)
	{
		infos->player->move_utils.lr_dir = -1;
		infos->player->px += cos(infos->player->angle - PI / 2) * MOVE_SPEED * infos->player->move_utils.lr_dir;
		infos->player->py += sin(infos->player->angle - PI / 2) * MOVE_SPEED * infos->player->move_utils.lr_dir;
	}
	if (keysym == XK_q || keysym == XK_Q)
	{
		infos->player->move_utils.lr_dir = 1;
		infos->player->px += cos(infos->player->angle - PI / 2) * MOVE_SPEED * infos->player->move_utils.lr_dir;
		infos->player->py += sin(infos->player->angle - PI / 2) * MOVE_SPEED * infos->player->move_utils.lr_dir;
	}
}

int up(int keysym, t_launcher *launcher)
{
	t_infos *infos;

	infos = (launcher)->i;
	if (keysym == XK_z || keysym == XK_Z)
	{
		infos->player->move_utils.ud_dir = -1;
		infos->player->px += cos(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
		infos->player->py += sin(infos->player->angle) * MOVE_SPEED * infos->player->move_utils.ud_dir;
	}
	draw_wall(&launcher);
	render_player(&launcher);
	mlx_put_image_to_window(launcher->mlx, launcher->mlx_win, launcher->img.img, 0, 0);
	return (0);
}


int down(int keysym, t_launcher *launcher)
{
	t_infos *infos;

	infos = (launcher)->i;
	if (keysym == XK_z || keysym == XK_Z)
		infos->player->move_utils.ud_dir = 0;
	return (0);
}

int	events_window(int keysym, t_launcher **launcher)
{
	t_launcher	*c;
	t_infos	*infos;

	infos = (*launcher)->i;
	c = (*launcher);
	if (keysym == XK_Escape)
		return (close_window_x(c));
	rotate_move_on(keysym, infos);
	move_on(keysym, infos, c);
	// render_player(launcher);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	return (0);
}


void	handle_event(t_launcher **launcher)
{
	t_launcher	*c;

	c = (*launcher);
	mlx_key_hook(c->mlx_win, events_window, launcher);
	mlx_hook(c->mlx_win, 2, 1L << 0, up, c);
	// mlx_hook(c->mlx_win, 3, 1L << 1, down, c);
	mlx_hook(c->mlx_win, 17, 0, close_window_x, c);

}
