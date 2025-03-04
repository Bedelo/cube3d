#include "./../includes/cube3d.h"

char	**fill_empty_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	while (*k < m->dim[1] - 1)
	{
		m->my_map[m->i][*k] = ' ';
		*k += 1;
	}
	return (m->my_map);
}

char	**fill_map(t_map_creation **map, int *k)
{
	t_map_creation	*m;

	m = *map;
	*k = 0;
	while (*k < ft_strlen(m->line))
	{
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W'
				|| m->line[*k] == 'E') && m->flag)
			return (err(INCORRECT_PLAYER), NULL);
		if ((m->line[*k] == 'N' || m->line[*k] == 'S' || m->line[*k] == 'W'
				|| m->line[*k] == 'E') && !m->flag)
		{
			m->my_map[m->i][*k] = m->line[*k];
			m->flag = 1;
		}
		if (m->line[*k] == '1' || m->line[*k] == '0')
			m->my_map[m->i][*k] = m->line[*k];
		if (m->line[*k] == ' ')
			m->my_map[m->i][*k] = ' ';
		if (m->line[*k] == '\n')
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
	while (m->i < (m->dim[0]) && m->line)
	{
		if (!fill_map(&m, &k))
			// return (free(m->line), shield_malloc_2(m->my_map, m->dim[0]), NULL);
			return (free(m->line), NULL);
		free(m->line);
		m->line = NULL;
		m->i += 1;
		k = 0;
		m->line = get_next_line(m->fd);
	}
	return (m->my_map);
}

int	ft_initialise_map(t_map_creation **map)
{
	t_map_creation	*m;

	m = *map;
	m->fd = ft_handle_map(m->file, ".cub");
	if (m->fd < 0)
		return (KO);
	if (!create_map(&m))
		return (KO);
	close(m->fd);
	if (!m->my_map)
		return (KO);
	return (OK);
}

t_map_creation	*ft_map(t_map_creation **map, char **av)
{
	int				i;
	t_map_creation	*m;

	m = *map;
	m->dim = ft_calloc(2, sizeof(int));
	if (map_dim(&i, m->file, len_y, &m->header_len) == KO)
		return (free(m->dim), free(m), NULL);
	m->dim[0] = i;
	if (map_dim(&i, m->file, len_x, &m->header_len))
		return (free(m->dim), free(m), NULL);
	m->dim[1] = i;
	i = 0;
	m->my_map = ft_calloc((m->dim[0] + 1), sizeof(char *));
	if (!m->my_map)
		return (shield_malloc(m->my_map));
	while (i < m->dim[0])
	{
		m->my_map[i] = ft_calloc(m->dim[1] + 1, sizeof(char));
		if (!m->my_map[i])
			return (shield_malloc_2(m->my_map, m->dim[0]));
		i++;
	}
	if (ft_initialise_map(&m) == KO)
		return (shield_malloc_2(m->my_map, m->dim[0]), free(m->dim), free(m), NULL);
	return (m);
}
