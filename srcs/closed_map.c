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

// int	has_looped(char **map, int x, int y, int *origin)
// {
// 	int	i;

// 	i = 0;
// 	printf("x = %d\n", x);
// 	printf("y = %d\n", y);
// 	if (map[x - 1][y] && map[x - 1][y] == 'V')
// 		i++;
// 	if (map[x + 1][y] && map[x + 1][y] == 'V')
// 		i++;
// 	if (map[x][y - 1] && map[x][y - 1] == 'V')
// 		i++;
// 	if (map[x][y + 1] && map[x][y + 1] == 'V')
// 		i++;
// 	if (x == origin[0] && y == origin[1] && i > 2)
// 		return (OK);
// 	return (KO);
// }

// int	verify(char **map, int x, int y, int *origin)
// {
// 	char	**m;
// 	int		top[2];
// 	int verif = 0;

// 	m = map;
// 	if (m[x][y] == '1')
// 		m[x][y] = 'V';
// 	if (m[x + 1][y] == '1')
// 		verif = verify(m, x + 1, y, origin);
// 	if (m[x][y + 1] == '1')
// 		verif = verify(m, x, y + 1, origin);
// 	if (m[x - 1][y] == '1')
// 		verif = verify(m, x - 1, y, origin);
// 	if (m[x][y - 1] == '1')
// 		verif = verify(m, x, y - 1, origin);
// 	if (none_wall(m, x, y) == KO)
// 		verif = KO;
// }

// int	check_map(t_map_creation **map)
// {
// 	char	**m;
// 	int		projection[2];
// 	int		check;

// 	m = (*map)->my_map;
// 	check = KO;
// 	projection[0] = (*map)->pos[0] - 1;
// 	printf("pos[0] = %d\n", (*map)->pos[0]);
// 	projection[1] = (*map)->pos[1];
// 	printf("pos[1] = %d\n", (*map)->pos[1]);
// 	printf("player = %c\n", m[projection[0] + 1][projection[1]]);
// 	while (check != OK && projection[0] >= 0)
// 	{
// 		check = verify(m, projection[0], projection[1], projection);
// 		if (check == OK)
// 			return (OK);
// 		projection[0] = projection[0] - 1;
// 		printf("**\n");
// 	}
// 	return (err("Error: map not close\n"), check);
// }

// int	to_top(int i, char **m, int k)
// {
// 	int	j;
// 	int	closure;

// 	closure = 0;
// 	if (i == -1)
// 		return (0);
// 	j = i - 1;
// 	while (j > -1 && i > -1)
// 	{
// 		if (m[k][j] == '1' && m[k][j + 1] != '1')
// 			closure++;
// 		j--;
// 	}
// 	return (closure);
// }

// int	to_bottom(int height, int j, char **m, int k)
// {
// 	int	i;
// 	int	closure;

// 	closure = 0;
// 	if (j == (height - 1))
// 		return (0);
// 	i = j + 1;
// 	while (i < height)
// 	{
// 		if (m[k][i] == '1' && m[k][i - 1] != '1')
// 			closure++;
// 		i++;
// 	}
// 	return (closure);
// }

// int enclosure(t_map_creation **map, char **m, int k)
// {
// 	int	i;
// 	int	j;

// 	i = (*map)->pos[1];
// 	j = (*map)->pos[1];
// 	while (m[k][i] && m[k][i] != '1')
// 		i--;
// 	while (m[k][i] && m[k][i] == '1')
// 		i--;
// 	while (m[k][j] && m[k][j] != '1')
// 		j++;
// 	while (m[k][j] && m[k][j] != '1')
// 		j++;
// 	if (to_top(i, m, k) % 2 == to_bottom((*map)->dim[1], j, m, k) % 2)
// 		return (OK);
// 	err("Error: map not close\n");
// 	return (KO);
// }

// int	check_map(t_map_creation **map)
// {
// 	char	**m;
// 	int		k;

// 	k = 0;
// 	m = (*map)->my_map;
// 	while (k < (*map)->dim[0])
// 		if (enclosure(map, m, k) == KO)
// 			return (KO);
// 	return (OK);
// }
