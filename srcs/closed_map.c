#include "./../includes/cube3d.h"

void err(char *s)
{
	ft_putstr_fd(s, 1);
}

int is_border(char c)
{
	if (!c || c == ' ')
		return (KO);
	return (OK);
}

int is_boundary_border(t_map_creation *map, int x , int y)
{
	if (x  == 0 && map->my_map[x][y] == '0')
		return (KO);
	if (y == 0 && map->my_map[x][y] == '0')
		return (KO);
	if (x == map->dim[0] - 1 && map->my_map[x][y] == '0')
		return (KO);
	if (y == map->dim[1] - 1 && map->my_map[x][y] == '0')
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
			if (is_boundary_border(*map, i, j) == KO)
				return (err("Error: map not close in boundary\n"), KO);
			if (is_closed(m, i, j) == KO)
				return (err("Error: map not close\n"), KO);
			j++;
		}
		i++;
		j = 0;
	}
	return (OK);
}
