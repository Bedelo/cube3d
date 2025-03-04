#include "./../includes/cube3d.h"

t_map_creation	*map_init(t_map_creation *m, char **av)
{
	m = ft_calloc(1, sizeof(t_map_creation));
	if (!m)
		return (NULL);
	*m = (t_map_creation){0};
	if (!av[1])
		return (NULL);
	m->file = av[1];
	m = ft_map(&m, av);
	if (!m)
		return (NULL);
	if (check_map(&m) == KO)
		return (clean_map(m), NULL);
	m->pos = malloc(sizeof(int) * 2);
	if (!m->pos)
		return (clean_map(m), NULL);
	if (!player_position(&m))
		return (err(ERROR), err("Player doesn't exist !\n"), clean_map(m), NULL);
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

t_texture	*init_texture(t_launcher *launcher, t_raycast *raycast)
{
	raycast->texture->data = &launcher->img;
	raycast->texture->width = TEXTURE_DIM;
	raycast->texture->height = TEXTURE_DIM;
	return (raycast->texture);
}
