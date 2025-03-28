/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:04:02 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/28 15:04:10 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_char_valid(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' ' || c == '\n')
		return (OK);
	return (KO);
}

char	**fill_map(t_map_creation **map, int k)
{
	t_map_creation	*m;

	m = *map;
	while ((size_t)(k) < ft_strlen(m->line))
	{
		if (is_char_valid(m->line[k]) == KO)
			return (err(ERROR), err(INCORRECT_CHAR), NULL);
		if ((m->line[k] == 'N' || m->line[k] == 'S' || m->line[k] == 'W'
				|| m->line[k] == 'E') && m->flag)
			return (err(ERROR), err(INCORRECT_PLAYER), NULL);
		if ((m->line[k] == 'N' || m->line[k] == 'S' || m->line[k] == 'W'
				|| m->line[k] == 'E') && !m->flag)
		{
			m->my_map[m->i][k] = m->line[k];
			m->flag = 1;
		}
		if (m->line[k] == '1' || m->line[k] == '0')
			m->my_map[m->i][k] = m->line[k];
		if (m->line[k] == ' ')
			m->my_map[m->i][k] = ' ';
		if (m->line[k] == '\n')
			fill_empty_map(&m, &k);
		k += 1;
	}
	return (m->my_map);
}
