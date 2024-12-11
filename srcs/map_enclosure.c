#include "./../includes/cube3d.h"

char	**player_position(t_map_creation **map, int *k);





int	check_enclosure_map(t_map_creation **map)
{
	t_map_creation	*m;
	int				res;
	int				w;
	int				h;

	int i = 0;
	m = *map;
	while (m->my_map[i] != NULL)
	{
		printf("%ld: %s\n", ft_strlen(m->my_map[i]), m->my_map[i]);
		i++;
	}
	return (res);
}
