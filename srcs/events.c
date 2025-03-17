/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:51:37 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/16 12:53:19 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	move_player(t_launcher *ptr, double move_x, double move_y)
{
	t_player		*player;
	event_variable	var;

	player = ptr->i->player;
	// var.map = ptr->map;
	var.x = player->px + move_x * MOVE_SPEED;
	var.y = player->py + move_y * MOVE_SPEED;
	if (ptr->map[(int)player->py][(int)var.x] != '1')
		player->px = var.x;
	if (ptr->map[(int)var.y][(int)player->px] != '1')
		player->py = var.y;
	ptr->i->player->move = 1;
}


static void	rotate_player(t_launcher *ptr, int direction)
{
	t_player		*player;
	event_variable	var;

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
	printf("key_code = %d\n", k_code);
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
