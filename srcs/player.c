#include "./../includes/cube3d.h"

void	render_player(t_launcher **launcher)
{
	int			k;
	int			j;
	t_infos		*infos;
	t_launcher	*c;

	c = (*launcher);
	infos = (*launcher)->i;
	k = infos->player->px;
	j = infos->player->py;
	my_mlx_pixel_put(&c->img, j, k, 0x00FF0000);
}


int	*player_position(t_map_creation **map)
{
	t_map_creation	*m;
	int				i;
	int				j;

	m = *map;
	i = -1;
	while (++i < m->dim[0])
	{
		j = -1;
		while (++j < m->dim[1] - 1)
		{
			if (m->my_map[i][j] == 'N' || m->my_map[i][j] == 'S'
				|| m->my_map[i][j] == 'W' || m->my_map[i][j] == 'E')
			{
				m->pos[0] = (i);
				m->pos[1] = (j);
				return (m->pos);
			}
		}
	}
	return (NULL);
}

