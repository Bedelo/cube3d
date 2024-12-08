#include "./../includes/cube3d.h"



void	fill_empty_map(t_map_creation *m, int *k)
{

	while (*k < m->dim[0])
	{
		m->my_map[m->i][*k] = '0';
		*k += 1;
	}
	m->my_map[m->i][*k] = 0;
}

char	**fill_map(t_map_creation *m, int *k)
{
	*k = 0;
	m->j = 0;
	m->line = get_next_line(m->fd);

	while (*k != m->dim[1])
	{
		ft_putchar_fd(m->line[*k], 1);							//* printer
		if (m->line[*k] == '1' || m->line[*k] == '0')
		{
			m->my_map[m->i][*k] = m->line[*k];
			ft_putchar_fd(m->my_map[m->i][*k], 1);
		}
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'E' || m->line[*k] == 'W') && m->flag == 0)
			m->my_map[m->i][*k] = m->line[*k];
		else if (m->line[*k] == ' ')
			m->my_map[m->i][*k] = '0';
		else if (m->line[*k] != '\n')
			m->my_map[m->i][*k] = 0;
		// m->j += 1;
		*k += 1;
		// printf("k = %d\n", *k);									//* printer
	}
	return (m->my_map);
}

char	**create_map(t_map_creation *m)
{
	int		k;

	m->flag = 0;
	m->i = 0;
	ft_putstr_fd("first loop\n", 1);										//* printer
	while (m->i < m->dim[1])
	{
		ft_putstr_fd("fill_map test?\n", 1);							//* printer
		if (!fill_map(m, &k))
			return (NULL);
		ft_putstr_fd("fill_map OK\n", 1);							//* printer
		if (k != m->dim[1])
			fill_empty_map(m, &k);
		else
			m->my_map[m->i][k] = 0;
		free(m->line);									//*check if it is correct
		m->line = NULL;
		m->i += 1;
		ft_putstr_fd("fill_next OK\n", 1);							//* printer
	}
	// m->my_map[m->i] = 0;
	return (m->my_map);
}

int	ft_initialise_map(t_map_creation *m)
{
	int		i;
	int		j;

	m->fd = ft_handle_map(m->file);
	if (m->fd == -1)
		return (1);
	i = 0;
	j = 0;
	ft_putstr_fd("enter to create map OK\n", 1);				//* printer
	create_map(m);
	close(m->fd);
	if (!m->my_map)
		return (1);
	return (0);
}

t_map_creation	*ft_map(t_map_creation *m, char **av)
{
	int	i;

	m = malloc(sizeof(t_map_creation));
	m->file = av[1];

	m->dim = ft_calloc(2, sizeof(int));
	map_dim(&i, m->file, len_y);
	m->dim[0] = i;
	map_dim(&i, m->file, len_x);
	m->dim[1] = i;
	i = 0;
	m->my_map = ft_calloc(m->dim[0] + 1, sizeof(char *));
	if (!m->my_map)
		return (shield_malloc_2(m->my_map, m->dim[0]));
	while (i < m->dim[1])
	{
		m->my_map[i] = ft_calloc(m->dim[1] + 1, sizeof(char));
		if (!m->my_map[i])
			return (shield_malloc_2(m->my_map, m->dim[0]));
		i++;
	}
	i = ft_initialise_map(m);
	printf("initialise map = %d\n", i);						//* printer
	if (i == KO)
	{
		return (shield_malloc_2(m->my_map, m->dim[0]));
	}
	ft_putchar_fd(m->my_map[0][1], 1);
	return (m);
}



