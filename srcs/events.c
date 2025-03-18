/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:51:37 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/18 12:56:59 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	move_player(t_launcher *ptr, double move_x, double move_y)
{
	t_player		*player;
	t_event_variable	var;
	t_map_creation		*dim;
	int					height;
	int					width;

	player = ptr->i->player;
	var.map = ptr->i->map->my_map;
	dim = ptr->i->map;
	var.x = player->px + move_x * MOVE_SPEED;
	var.y = player->py + move_y * MOVE_SPEED;
	height = dim->dim[0];
	width = dim->dim[1];
	printf("var.x 		= [%d]\t	var.y 		= [%d]\n", var.x, var.y);
	printf("px		= [%f]\tpy		= [%f]\n", player->px, player->py);
	printf("map height	= [%d]\t	map width	= [%d]\n", dim->dim[0], dim->dim[1]);
	if (player->py >= 0 && (int)player->py < height &&
		var.x >= 0 && var.x < width &&
		var.map[var.x][(int)player->py] != '1')
			player->px = var.x;
	else
	{
		printf("out of range en X\n");
		return ;
	}
	if (player->px >= 0 && (int)player->px < width &&
		var.y >= 0 && var.y < height &&
		var.map[var.x][(int)player->py] != '1')
		player->px = var.x;
	else
	{
		printf("out of range en Y\n");
		return ;
	}
	ptr->i->player->move = 1;
}

static void	rotate_player(t_launcher *ptr, int direction)
{
	t_player		*player;
	t_event_variable	var;

	player = ptr->i->player;
	if (direction == -1)
	{
		var.cos_theta = COS_NEG_ANGLE;
		var.sin_theta = SIN_NEG_ANGLE;
	}
	else
	{
		var.cos_theta = COS_ANGLE;
		var.sin_theta = SIN_ANGLE;
	}
	var.old_dirX = player->dir_x;
	var.old_planeX = player->plane_x;
	player->dir_x = player->dir_x * var.cos_theta - player->dir_y * var.sin_theta;
	player->dir_y = var.old_dirX * var.sin_theta + player->dir_y * var.cos_theta;
	player->plane_x = player->plane_x * var.cos_theta - player->plane_y * var.sin_theta;
	player->plane_y = var.old_planeX * var.sin_theta + player->plane_y * var.cos_theta;
	ptr->i->player->move = 1;
}

int	event_key(int k_code, t_launcher *ptr)
{
	//printf("puntero ptr->i->player = [%p]\n", ptr->i->player);
	if (k_code == XK_Escape)
		return (close_window_x(ptr));
	if (k_code == 122)
		move_player(ptr, ptr->i->player->dir_x, ptr->i->player->dir_y);
	if (k_code == XK_s)
		move_player(ptr, ptr->i->player->dir_x, -ptr->i->player->dir_y);
	if (k_code == 113)
		move_player(ptr, ptr->i->player->dir_y, -ptr->i->player->dir_x);
	if (k_code == XK_d)
		move_player(ptr, -ptr->i->player->dir_y, ptr->i->player->dir_x);
	if (k_code == 65361) // fleche left
		rotate_player(ptr, -1);
	if (k_code == 65363) // fleche right
		rotate_player(ptr, 1);
	return (0);
}

int	close_window_x(t_launcher *c)
{
	// rajouter les free pour les textures
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->mlx_win);
	mlx_destroy_display(c->mlx);
	free(c->name);
	free(c->mlx);
	free(c->raycast->axis);
	//free(c->raycast->texture);
	free(c->raycast);
	free(c->i->player);
	clean_map(c->i->map);
	clean_header(c->i->header);
	free(c->i);
	free(c);
	exit(0);
}
