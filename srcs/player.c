#include "./../includes/cube3d.h"

void	render_player(t_launcher **launcher)
{
	int			k;
	int			j;
	t_infos		*infos;
	t_container	*c;

	c = (*launcher)->c;
	infos = (*launcher)->i;
	k = infos->player->px;
	j = infos->player->py;
	my_mlx_pixel_put(&c->img, j, k, 0x00FF0000);
}


