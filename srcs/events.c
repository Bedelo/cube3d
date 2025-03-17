/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:51:37 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/17 16:15:21 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	move_player(t_launcher *ptr, double move_x, double move_y)
{
	t_player		*player;
	t_event_variable	var;
	char				**m;

	player = ptr->i->player;
	m = ptr->i->map->my_map;
	// var.map = ptr->map;
	var.x = player->px + move_x * MOVE_SPEED;
	var.y = player->py + move_y * MOVE_SPEED;
	if (m[(int)player->py][(int)var.x] != '1')
		player->px = var.x;
	if (m[(int)var.y][(int)player->px] != '1')
		player->py = var.y;
	ptr->i->player->move = 1;
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

static void	rotate_player(t_launcher *ptr, int direction)
{
	t_player		*player;
	t_event_variable	var;

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
