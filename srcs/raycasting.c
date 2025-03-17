/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:18:36 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/17 16:51:06 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	setup_ray_2(t_ray *ray, int x, t_player *player)
{
	/*	determine la direction du step en X et Y
		Define si le rayon avance dans la grille en direction positive ou negative
	*/
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	/*
		calcul de la distance initial en X et Y
		Calcule la distance initial que le rayon doit parcourir avent d'arriver
			a la premiere grille en X et Y

		Si le player est dans (2.3, 3.8):
			Distance jusau'a la prochaine ligne verticale (map_x + 1.1 - player_x):
			(3.0 - 2.3) * delat_dist_x;
			cela nous indique la proximite de la premiere intersection

	 */
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
	/*
		calcule la position du rayon dans le plan de la camera dans un rang de [-1, 1]
	*/
	ray->camera = ((2.0 * (double)x) / (double)SCR_WIDTH) - 1.0;

	/*
		On calcule la direction du rayon en X et Y
		on cree un vecteur de direction pour le rayon par rapport au FOV: ray_dir_x et ray_dir_y

		dir_x et  dir_y indiquent ou regarde le player
		plane_x et plane_x controlent la projection du FOV dans la fenetre

		Le player regarde en face (dir_x = 1, dir_y = 0):
         ^ (Rayon centrale, camera = 0)
        /
       /
<-    O    -> (FOV)
       \
        \
         v (Rayon droite, camera = 1)

	*/
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera;

	/*
		on obtien la position absolut de X et Y
	*/
	ray->map_x = (int)player->px;
	ray->map_y = (int)player->py;

	/*
		calcul des distance entre les intersection X et Y
		On calcul combien de distance parcours le rayon en X et Y quand il bouge d'une grille dans la map

	delta_dist_x = |1 / 2| = 0.5 signifie que le rayon prends 0.5 unites pour atteindre la suivante ligne verticale

	*/

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
	printf("SETUP_RAY 110\n");
	while (x < SCR_WIDTH)
	{
		//init_ray(&ray);//TO DO
		setup_ray(&ray, x, ptr);
		printf("SETUP_RAY OK\n");
		dda(&ray, ptr);
		printf("DDA OK\n");
		line_height(&ray, ptr->i->player);
		printf("LINE_HEIGHT OK\n");
		print_pixels(ptr, &ray, x);
		printf("PRINT_PIXELS OK\n");
		draw_floor_ceiling(ptr, x, ray.draw_start, ray.draw_end);
		x++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img.img, 0, 0);
	ptr->i->player->move = 0;
}
