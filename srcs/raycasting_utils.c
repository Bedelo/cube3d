/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:14:34 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/18 09:44:02 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	draw_floor_ceiling(t_launcher *ptr, int x, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	if (draw_end < 0)
		return ;
	while (y < draw_start)
	{
		put_pixel_to_buffer(&ptr->img, x, y, ptr->raycast->c_color);
		y++;
	}
	y = draw_end + 1;
	while (y < SCR_HEIGHT)
	{
		put_pixel_to_buffer(&ptr->img, x, y, ptr->raycast->f_color);
		y++;
	}
}

void	dda(t_ray *ray, t_launcher *ptr)
{
	int		hit;
	char	c;

	// printf("valor de x=[%d]\tvalor de y=[%d]\n", ray->map_x, ray->map_y);
	// printf("valor de step_x=[%d]\tvalor de step_y=[%d]\n", ray->step_x, ray->step_y);

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->d_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->d_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		// printf("valor de x=[%d]\tvalor de y=[%d]\n", ray->map_x, ray->map_y);
		// printf("valor de step_x=[%d]\tvalor de step_y=[%d]\n", ray->step_x, ray->step_y);

		c = ptr->i->map->my_map[ray->map_x][ray->map_y];
		if (c == '1')
			hit = 1;
	}
}

void	line_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
	{
		ray->dist_perp = (ray->map_x - player->px + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
		ray->wall = player->py + ray->dist_perp * ray->ray_dir_y;
	}
	else
	{
		ray->dist_perp = (ray->map_y - player->py + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
		ray->wall = player->px + ray->dist_perp * ray->ray_dir_x;
	}
	ray->line_height = (int)SCR_HEIGHT / ray->dist_perp;
	ray->wall -= floor(ray->wall);
	ray->draw_start = -ray->line_height / 2 + SCR_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCR_HEIGHT / 2;
	if (ray->draw_end >= SCR_HEIGHT)
		ray->draw_end = SCR_HEIGHT - 1;
}
