/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:14:34 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/17 16:22:39 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

/*
	This fonction draws the floor and ceil
 */
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
	int hit;
	char **m;

	hit = 0;
	m = ptr->i->map->my_map;
	/*
		pour chaque iteration, le rayon avance jusqu'a la suivance celulle de la grille
		Le rayon bouge de gauche a droite jusqu'a trouver un mur
	 */
	while (!hit)
	{
		/*
		On avance en X ou Y par rapport au plus petit
		On compare si side_dit_x et side_dist_y pour determiner quel intersection est la plus proche
		*/

		if (ray->side_dist_x < ray->side_dist_y) // le rayon "hit" en premier une ligne VERTICALE donc on bouge en X
		{
			ray->side_dist_x += ray->d_dist_x; //incremente la distance en X avec delta_dist_x
			ray->map_x += ray->step_x; // on bouge a la case suivante;
			ray->side = 0; // on indique qu'on a touche un mur VERTICALE
			//printf("DENTRO DEL IF DE DDA\n");
		}
		/*
		 Avant:
			map_x = 2, step_x = 1
			|   | P |   | W |

		Apres:
			map_x = 3
			|   |   | P | W |

		 */
		else // le rayon "hit" en premier une ligne HORIZONTALE donc on bouge en Y
		{
			ray->side_dist_y += ray->d_dist_y; //incremente la distance en Y avec delta_dist_y
			ray->map_y += ray->step_y; // on bouge a la case suivante;
			ray->side = 1; // on indique qu'on a touche un mur HORIZONTALE
			//printf("DENTRO DEL ELSE DE DDA\n");
		}
		/*
		Avant:
		map_y = 2, step_y = 1
		+---+
		| P |
		+---+

		Apres:
		map_y = 3
		+---+
		|   |
		+---+
		| P |
		+---+

		*/
		//printf("Valor de la grille [%c]\n", ptr->map[ray->map_x][ray->map_y]);
		if (m[ray->map_x][ray->map_y] == '1') //
		{
				//printf("MURO ENCONTRADO\n");
				hit = 1;
		}
	}
}

void	line_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0) // on a touche un mur VERTICALE: COLISION !
	{
	/*
		Calcul de la distance du player jusqu'au mur trouve: perp_dist
		Map (le player est dans `P`, le mur est dans `W`):

+---+---+---+---+
| W |   |   |   |
+---+---+---+---+
|   | P | → | W |  ← le rayon bouge a droite
+---+---+---+---+

Si `side == 0` (mur verticale en X), on utilise:
(ray.map_x - player.pos_x + (1 - step_x) / 2) / ray.ray_dir_x

	*/
		ray->dist_perp = (ray->map_x - player->px + (1 - ray->step_x) / 2 ) / ray->ray_dir_x; // division par ray_dir_x pour ajoustement


	/*
		Determiner la position exacte de l'impact contre le mur

		on cherche ou exactement a frappe le rayon contre le mur: side == 0 en Y / side == 1 en X
		wall nous donne le point exacte de la texture qu'on doit afficher
	 */
		ray->wall = player->py + ray->dist_perp * ray->ray_dir_y;
	}
	else // on a touche un mur HORIZONTALE: COLISION
	{
		ray->dist_perp = (ray->map_y - player->py + (1 - ray->step_y) / 2 ) / ray->ray_dir_y;
		ray->wall = player->px + ray->dist_perp * ray->ray_dir_x;
	}

		    	/*
		Calcul de la hauteur du mur dans l'ecran

		faut convertir perp_dist dans une valeur qui define la hauteur du mur a l'ecran
		plus il est loin du mur (perp_dist GRAND) plus petit on la verra
		plus il est proche du mur (perp_dist PETIT) plus grand on la verra

		si perp_dist = 1  le mur sera dans presque tout l'ecran
		si perp_dist = 10 le mur est petit
	 */
    ray->line_height = (int)SCR_HEIGHT / ray->dist_perp;
	/*
		Se rasurer que WALL est dans un rang [0, 1]
		pour savoir quel partie de la texture montrer a l'ecran

		si ray->wall = 2.75

			floor(2.75) = 2;
			ray.wall_x = 2.75 - 2 = 0.75;

		cela signifie que l'impacte a lieu a 75% de la texture (pres du bord droite)
	 */
	ray->wall -= floor(ray->wall);

	ray->draw_start = -ray->line_height / 2 + SCR_HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + SCR_HEIGHT / 2;
    if (ray->draw_end >= SCR_HEIGHT)
        ray->draw_end = SCR_HEIGHT - 1;
}
