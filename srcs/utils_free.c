#include "./../includes/cube3d.h"


static void	header_cardinal(t_header * header)
{
	if (header->no)
	{
		free(header->no);
		header->no = NULL;
	}
	if (header->so)
	{
		free(header->so);
		header->so = NULL;
	}
	if (header->we)
	{
		free(header->we);
		header->we = NULL;
	}
	if (header->ea)
	{
		free(header->ea);
		header->ea = NULL;
	}
}

static void header_floor_celling(t_header *header)
{
	if (header->f)
	{
		free(header->f);
		header->f = NULL;
	}
	if (header->c)
	{
		free(header->c);
		header->c = NULL;
	}
}

void	clean_header(t_header *header)
{
	header_cardinal(header);
	header_floor_celling(header);
	free(header);
	header = NULL;
}


void	free_all(t_launcher *launcher)
{
	free(launcher->i->player);
	clean_header(launcher->i->header);
	clean_map(launcher->i->map);
	free(launcher->i);
	free(launcher->raycast->axis);
	free(launcher->raycast->texture);
	free(launcher->raycast);
	free(launcher);
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



