#include "./../includes/cube3d.h"


void	clean_header(t_header *header)
{
	free(header->no);
	free(header->so);
	free(header->we);
	free(header->ea);
	free(header->f);
	free(header->c);
	free(header);
}

void	free_2(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	*shield_malloc(void *ptr)
{
	free(ptr);
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
	if(m->line)
	{
		free(m->line);
		m->line = NULL;
	}
	if(m->pos)
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
