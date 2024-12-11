#include "./../includes/cube3d.h"

char	**player_position(t_map_creation **map, int *k);



int	check_line_is_full_walls(t_map_creation **map, int a, int b, char c)
{
	t_map_creation	*m;
	int				i;
	int				j;

	i = 0;
	j = 0;
	m = *map;
	// printf("\n%s : line\n", m->my_map[a]);
	printf("\n");
	while (c == 'w' && j < b - 1)
	{
		printf("%c :w%d,%d\n", m->my_map[a][j], a, j);
		if (m->my_map[a][j] != '1')
			return (err("Error: Horizontal error map: "), KO);
		j++;
	}
	while (c == 'h' && i < a)
	{
		printf("%c :w%d,%d\n", m->my_map[i][b], i, b);
		if (m->my_map[i][b] != '1')
			return (err("Error: Vertical error map: "), KO);
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
	int k = 0;
	while (k < m->dim[0])
	{
		printf("%s\n", m->my_map[k]);
		k++;
	}


	printf("dim0 %d \ndim1 %d\n", m->dim[0], m->dim[1]);
	res += check_line_is_full_walls(&m, 0, m->dim[1] , 'w');
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
