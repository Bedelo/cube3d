#include "./../includes/cube3d.h"

t_map_creation	*map_init(t_map_creation *m, char **av)
{
	m = ft_calloc(1, sizeof(t_map_creation));
	if (!m)
		return (NULL);
	m->file = av[1];
	m = ft_map(&m, av);
	if (!m)
		return (NULL);
	m->pos = malloc(sizeof(int) * 2);
	if (!m->pos)
		return (NULL);
	// m->my_map[m->pos[0]][m->pos[1]] = '0';
	player_position(&m);
	if (check_map(&m) == KO)
		return (NULL);
	// clean_map(m);			//# TO USE IN FUTURE FOR CLEANING MEMORY ALLOCATED
	return (m);
}

void	display_map(t_map_creation *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->dim[0])
	{
		while (j < m->dim[1])
		{
			ft_putchar_fd(m->my_map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
		j = 0;
	}
}
