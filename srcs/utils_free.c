/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:14:11 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/24 11:46:32 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	*shield_malloc(void *ptr)
{
	if(ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	*shield_malloc_2(char **ptr, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
		}
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

void	clean_map(t_map_creation *m)
{
	shield_malloc_2(m->my_map, m->dim[0]);
	if (m->line)
	{
		free(m->line);
		m->line = NULL;
	}
	if (m->pos)
	{
		free(m->pos);
		m->pos = NULL;
	}
	if (m->dim)
	{
		free(m->dim);
		m->dim = NULL;
	}
	free(m);
	m = NULL;
}

void	free_map(t_map_creation *m)
{
	shield_malloc_2(m->my_map, m->dim[0]);
	free(m->dim);
	free(m);
}
