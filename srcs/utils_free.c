#include "./../includes/cube3d.h"


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
			free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
