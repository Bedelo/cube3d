#include "./../includes/cube3d.h"



char	**fill_empty_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	// printf("before fill K = %d\n", *k);											//* printer
	while (*k < m->dim[1])
	{
		// ft_putstr_fd("COMPLETE LINE \n", 1);										//* printer
		m->my_map[m->i][*k] = '0';
		*k += 1;
	}
	// m->my_map[m->i][*k] = 0;
	return (m->my_map);
}

char	**fill_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	*k = 0;
	// if (m->i == m->dim[0])
	// 	return (m->my_map);
	while (*k <= ft_strlen(m->line))
	{
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W' || m->line[*k] == 'E') && m->flag)
			return (NULL);
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W' || m->line[*k] == 'E') && !m->flag)
		{
			m->my_map[m->i][*k] = m->line[*k];
			m->flag = 1;
		}
		if (m->line[*k] == '1' || m->line[*k] == '0')
			m->my_map[m->i][*k] = m->line[*k];
		if (m->line[*k] == ' ')
			m->my_map[m->i][*k] = '0';
		if (m->line[*k] == 0)
			fill_empty_map(&m, k);
		*k += 1;
	}
	return (m->my_map);
}

char	**create_map(t_map_creation **map)
{
	int				k;
	int				head;
	t_map_creation	*m;

	m = *map;
	m->flag = 0;
	m->i = 0;
	head = 0;
	while (check_is_header(&m->line, m->fd) == OK)
		free(m->line);
	while (m->i < (m->dim[0] ) && m->line)
	{
		printf("%s  MA LINE\n", m->line);									//* printer
		if (!fill_map(&m, &k))
			return (shield_malloc_2(m->my_map, m->dim[0]));
		free(m->line);
		m->line = NULL;
		m->i += 1;
		k = 0;
		m->line = get_next_line(m->fd);
		printf("########## %d/%d\n", m->i, m->dim[0]);									//* printer
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
	// ft_putstr_fd("enter to create map OK\n", 1);				//* printer
	create_map(&m);
	close(m->fd);
	if (!m->my_map)
		return (1);
	return (0);
}

t_map_creation	*ft_map(t_map_creation **map, char **av)
{
	int				i;
	// int				h;
	t_map_creation	*m;

	m = *map;
	m->dim = ft_calloc(2, sizeof(int));
	map_dim(&i, m->file, len_y, &m->header_len);
	m->dim[0] = i;
	map_dim(&i, m->file, len_x, &m->header_len);
	m->dim[1] = i;
	printf("dim0 = %d\n", m->dim[0]);												//* printer
	printf("dim1 = %d\n", m->dim[1]);												//* printer
	printf("header_len = %d\n", m->header_len);										//* printer
	i = 0;
	printf("################## CURSOR ##################\n");							//* printer
	m->my_map = ft_calloc(m->dim[0], sizeof(char *));
	if (!m->my_map)
		return (shield_malloc(m->my_map));
	while (i < m->dim[0])
	{
		m->my_map[i] = ft_calloc(m->dim[1], sizeof(char));
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
	return (m);
}
