/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:13:42 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/23 14:19:47 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

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

void	init_player_direction(char direction, t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	if (direction == 'N')
	{
		player->dir_x = -1;
		player->plane_y = 0.66;
	}
	if (direction == 'S')
	{
		player->dir_x = 1;
		player->plane_y = -0.66;
	}
	if (direction == 'E')
	{
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	if (direction == 'W')
	{
		player->dir_y = -1;
		player->plane_x = -0.66;
	}
}

int	*axis(t_raycast *raycast, char c)
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

int	*init_axis(t_launcher *launcher, t_raycast *rc)
{
	int		x;
	int		y;
	char	c;

	x = launcher->i->map->pos[0];
	y = launcher->i->map->pos[1];
	c = launcher->i->map->my_map[x][y];
	init_player_direction(c, launcher->i->player);
	return (axis(rc, c));
}
