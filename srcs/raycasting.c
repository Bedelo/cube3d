/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:18:36 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/18 11:15:10 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	setup_ray_2(t_ray *ray, int x, t_player *player)
{
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (ray->step_x == -1)
		ray->side_dist_x = (player->px - ray->map_x) * ray->d_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - player->px) * ray->d_dist_x;
	if (ray->step_y == -1)
		ray->side_dist_y = (player->py - ray->map_y) * ray->d_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - player->py) * ray->d_dist_y;

}

void	setup_ray(t_ray *ray, int x, t_launcher *ptr)
{
	t_player *player;

	player = ptr->i->player;

	ray->camera = ((2.0 * (double)x) / (double)SCR_WIDTH) - 1.0;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera;
	ray->map_x = (int)player->px;
	ray->map_y = (int)player->py;
	if (ray->ray_dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->d_dist_y = 1e30;
	else
		ray->d_dist_y = fabs(1 / ray->ray_dir_y);
	setup_ray_2(ray, x, player);
}

void	draw_cube3d(t_launcher *ptr)
{
	int		x;
	t_ray	ray;

	if (!ptr->i->player->move)
		return ;
	x = 0;
	clear_image(ptr);
	while (x < SCR_WIDTH)
	{
		setup_ray(&ray, x, ptr);
		//printf("SETUP_RAY OK\n");
		dda(&ray, ptr);
		//printf("DDA OK\n");
		line_height(&ray, ptr->i->player);
		//printf("LINE_HEIGHT OK\n");
		print_pixels(ptr, &ray, x);
		//printf("PRINT_PIXELS OK\n");
		draw_floor_ceiling(ptr, x, ray.draw_start, ray.draw_end);
		//printf("FLOOR_CEIL OK\n");
		x++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img.img, 0, 0);
	ptr->i->player->move = 0;
}
