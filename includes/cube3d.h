#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_coord
{
	long long	xx;
	long long	yy;
}			t_coord;

typedef struct s_vars
{
	char	*name;
	void	*mlx;
	void	*win;
	t_data	img;
	double	shiftx;
	double	shifty;
	double	zoom;
	long	iter;
	t_coord	coord;
}			t_vars;

#endif
