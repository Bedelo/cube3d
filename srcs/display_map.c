#include "./../includes/cube3d.h"

void	display_map(t_map_creation *m, char **av)
{
	int	i;
	int	j;

	m = ft_calloc(1, sizeof(t_map_creation));
	m->file = av[1];
	if (ft_map(&m, av))
	{

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
	// clean_map(m);			//# TO USE IN FUTURE FOR CLEANING MEMORY ALLOCATED
}
