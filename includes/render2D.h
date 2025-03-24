/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:45:39 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/23 14:46:29 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2D_H
# define RENDER2D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include "mystruct.h"

# define W_WALL 10
# define H_WALL 10

void		render_player(t_launcher **launcher);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_wall(t_launcher **launcher);
void		handle_event(t_launcher *c);
void		clear_image(t_launcher *launcher);
#endif
