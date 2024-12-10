#include "./../includes/cube3d.h"



char	**fill_empty_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	while (*k < m->dim[0])
	{
		m->my_map[m->i][*k] = '0';
		*k += 1;
	}
	return (m->my_map);
}

char	**fill_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	*k = 0;
	m->j = 0;
	m->line = get_next_line(m->fd);
	while (*k < ft_strlen(m->line))
	{
		m->my_map[m->i][*k] = m->line[*k];
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W' || m->line[*k] == 'E') && m->flag)
			return (NULL);
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W' || m->line[*k] == 'E') && !m->flag)
			m->flag = 1;
		*k += 1;
	}
	ft_putchar_fd('\n', 1);								//* printer
	return (m->my_map);
}

char	**create_map(t_map_creation **map)
{
	int				k;
	t_map_creation	*m;

	m = *map;
	m->flag = 0;
	m->i = 0;
	ft_putstr_fd("first loop\n", 1);										//* printer
	while (m->i < m->dim[1])
	{
		ft_putstr_fd("fill_map test?\n", 1);							//* printer
		if (!fill_map(&m, &k))
			return (shield_malloc_2(m->my_map, m->dim[0]));
		if (k != m->dim[1])
			if (!fill_empty_map(&m, &k))
				return (shield_malloc_2(m->my_map, m->dim[0]));
		free(m->line);									//*check if it is correct
		m->line = NULL;
		m->i += 1;
		k = 0;
		ft_putstr_fd("fill_next OK\n", 1);							//* printer
	}
	return (m->my_map);
}

int	ft_initialise_map(t_map_creation **map)
{
	t_map_creation	*m;

	m = *map;
	m->fd = ft_handle_map(m->file);
	if (m->fd == -1)
		return (1);
	ft_putstr_fd("enter to create map OK\n", 1);				//* printer
	m->my_map = create_map(&m);
	close(m->fd);
	if (!m->my_map)
		return (1);
	return (0);
}

t_map_creation	*ft_map(t_map_creation **map, char **av)
{
	int	i;
	t_map_creation	*m;

	m = *map;
	m->dim = ft_calloc(2, sizeof(int));
	map_dim(&i, m->file, len_y);
	m->dim[0] = i;
	map_dim(&i, m->file, len_x);
	m->dim[1] = i;
	i = 0;
	m->my_map = ft_calloc(m->dim[0] + 1 , sizeof(char *));
	if (!m->my_map)
		return (shield_malloc(m->my_map));
	while (i < m->dim[0])
	{
		m->my_map[i] = ft_calloc(m->dim[1] + 1, sizeof(char));
		if (!m->my_map)
			return (shield_malloc_2(m->my_map, m->dim[0]));
		i++;
	}
	i = ft_initialise_map(&m);
	if (i)
	{
			printf("KO for MAP\n");
			i == 1;
	}
	if (!i)
	{
		int j = 0;
		while (i < m->dim[0]-1)
			{

				while (j < m->dim[1] - 1)
				{

					ft_putchar_fd(m->my_map[i][j], 1);
					ft_putchar_fd(' ', 1);
					j++;
				}
				ft_putchar_fd('\n', 1);
				i++;
				j = 0;
			}
	}
	return (m);
}
