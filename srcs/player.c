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

void ajust_angle(t_infos *infos)
{
	if (infos->map->my_map[infos->map->pos[0]][infos->map->pos[1]] == 'N')
		infos->player->angle = 0;
	else if (infos->map->my_map[infos->map->pos[0]][infos->map->pos[1]] == 'S')
		infos->player->angle = PI;
	else if (infos->map->my_map[infos->map->pos[0]][infos->map->pos[1]] == 'W')
		infos->player->angle = PI / 2;
	else if (infos->map->my_map[infos->map->pos[0]][infos->map->pos[1]] == 'E')
		infos->player->angle = 3 * PI / 2;
}


int *axis(t_raycast *raycast, char c)
{
	raycast->axis = ft_calloc(2, sizeof(int));
	if (!raycast->axis)
		return (NULL);
	if (c == 'N')
	{
		raycast->axis[0] = 0;
		raycast->axis[1] = 1;
	}
	else if (c == 'S')
	{
		raycast->axis[0] = 0;
		raycast->axis[1] = -1;
	}
	else if (c == 'W')
	{
		raycast->axis[0] = -1;
		raycast->axis[1] = 0;
	}
	else if (c == 'E')
	{
		raycast->axis[0] = 1;
		raycast->axis[1] = 0;
	}
	return (raycast->axis);
}


int *init_axis(t_launcher *launcher, t_raycast *rc)
{
	int	x;
	int	y;
	char	c;

	x = launcher->i->map->pos[0];
	y = launcher->i->map->pos[1];
	c = launcher->i->map->my_map[x][y];
	return (axis(rc, c));
}
