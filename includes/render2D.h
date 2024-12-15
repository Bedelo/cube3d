#ifndef RENDER2D_H
# define RENDER2D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include "mystruct.h"

# define W_WALL 5
# define H_WALL 5



void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_wall(t_container *c, t_infos *infos);
void		handle_event(t_container *container);

#endif
