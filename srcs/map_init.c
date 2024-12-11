#include "./../includes/cube3d.h"

t_map_creation	*map_init(t_map_creation *m, char **av)
{

	m = ft_calloc(1, sizeof(t_map_creation));
	m->file = av[1];
	m = ft_map(&m, av);
	printf("dim0 %d \ndim1 %d\n\n", m->dim[0], m->dim[1]);
	// display_map(m);				//# TO USE IN FUTURE FOR DISPLAYING MAP ON CONSOLE
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