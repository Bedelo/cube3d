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


int is_border(char c)
{
	if (!c || c == ' ')
		return (KO);
	return (OK);
}


int	is_closed(char **map, int x, int y)
{
	if (map[x][y] != '1' && map[x][y] != ' ')
	{
		if (is_border(map[x - 1][y + 1]) == KO)
			return (KO);
		if (is_border(map[x][y + 1]) == KO)
			return (KO);
		if (is_border(map[x + 1][y + 1]) == KO)
			return (KO);
		if (is_border(map[x - 1][y]) == KO)
			return (KO);
		if (is_border(map[x + 1][y]) == KO)
			return (KO);
		if (is_border(map[x - 1][y - 1]) == KO)
			return (KO);
		if (is_border(map[x][y - 1]) == KO)
			return (KO);
		if (is_border(map[x + 1][y - 1]) == KO)
			return (KO);
	}
	return (OK);
}

int	check_map(t_map_creation **map)
{
	char	**m;
	int		i;
	int		j;

	i = 0;
	j = 0;
	m = (*map)->my_map;
	while (m[i])
	{
		while (m[i][j])
		{
			if (is_closed(m, i, j) == KO)
				return (err("Error: map not close\n"), KO);
			j++;
		}
		i++;
		j = 0;
	}
	return (OK);
}
