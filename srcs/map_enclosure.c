#include "./../includes/cube3d.h"

int	*player_position(t_map_creation **map)
{
	t_map_creation	*m;
	int				i;
	int				j;
	int				*pos;

	m = *map;
	i = -1;
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	while (++i < m->dim[0])
	{
		j = -1;
		while (++j < m->dim[1])
		{
			if (m->my_map[i][j] == 'N' || m->my_map[i][j] == 'S'
				|| m->my_map[i][j] == 'W' || m->my_map[i][j] == 'E')
			{
				pos[0] = (i);
				pos[1] = (j);
				return (pos);
			}
		}
	}
	return (NULL);
}

int	check_line_is_full_walls(t_map_creation **map, int a, int b, char c)
{
	t_map_creation	*m;
	int				i;
	int				j;

	i = 0;
	j = 0;
	m = *map;
	printf("\n");
	while (c == 'w' && j < b - 1)
	{
		if (m->my_map[a][j] != '1')
			return (err("Error: Horizontal error map \n"), KO);
		j++;
	}
	while (c == 'h' && i < a)
	{
		if (m->my_map[i][b] != '1')
			return (err("Error: Vertical error map \n"), KO);
		i++;
	}
	return (OK);
}

int	check_enclosure_map(t_map_creation **map)
{
	t_map_creation	*m;
	int				res;
	int				w;
	int				h;

	m = *map;
	res = OK;
	res += check_line_is_full_walls(&m, 0, m->dim[1], 'w');
	if (res == KO)
		return (res);
	res += check_line_is_full_walls(&m, m->dim[0] - 1, m->dim[1], 'w');
	if (res == KO)
		return (res);
	res += check_line_is_full_walls(&m, m->dim[0] - 1, 0, 'h');
	if (res == KO)
		return (res);
	res += check_line_is_full_walls(&m, m->dim[0] - 1, m->dim[1] - 2, 'h');
	return (res);
}
