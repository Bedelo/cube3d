#include "./../includes/cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init(t_container *container)
{


}

int	main(int ac, char **av)
{
	(void)				ac;
	t_map_creation		*m;


	display_map(m, av);
	return (0);
}
