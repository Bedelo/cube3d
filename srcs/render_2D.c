#include "./../includes/cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (OK);
	return (KO);
}

void	draw_square(t_infos *infos, t_container *c, int x, int y, int color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + H_WALL)
	{
		j = y;
		while (j < y + W_WALL)
		{
			my_mlx_pixel_put(&c->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_wall(t_container *c, t_infos *infos)
{
	int	i;
	int	j;

	i = 0;
	while (i < H_WALL * infos->map->dim[0] - 1)
	{
		j = 0;
		while (j < W_WALL * infos->map->dim[1] - 1)
		{
			if (infos->map->my_map[i / H_WALL][j / W_WALL] == '1')
				draw_square(infos, c, j, i, 0x00FFFFFF);
			else if (infos->map->my_map[i % H_WALL][j % W_WALL] != '1')
				draw_square(infos, c, j, i, 0x00000000);
			j += W_WALL;
		}
		i += H_WALL;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
}
