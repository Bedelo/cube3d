/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:51:37 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/19 14:56:16 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

/********************MOUVEMENT EN XY ********************/
// Verificamos que la posición futura en XY esté dentro de las filas del mapa
// Obtenemos la longitud real de la fila (por si es irregular)
// Comprobamos que la posición XY actual del jugador sea válida en esa fila
// Esto evita acceder fuera de la memoria si la fila es más corta
static void	move_player(t_launcher *ptr, double move_x, double move_y)
{
	t_player			*player;
	t_event_variable	var;
	t_map_creation		*dim;

	player = ptr->i->player;
	dim = ptr->i->map;
	var.map = dim->my_map;
	var.x = player->px + move_x * MOVE_SPEED;
	var.y = player->py + move_y * MOVE_SPEED;
	if (var.x >= 0 && (int)var.x < dim->map_h && var.map[(int)var.x])
	{
		var.fila_len_x = ft_strlen(var.map[(int)var.x]);
		if ((int)player->py < var.fila_len_x
			&& var.map[(int)var.x][(int)player->py] != '1')
			player->px = var.x;
	}
	if ((int)player->px < dim->map_h && var.map[(int)player->px])
	{
		var.fila_len_y = ft_strlen(var.map[(int)player->px]);
		if (var.y >= 0 && (int)var.y < var.fila_len_y
			&& var.map[(int)player->px][(int)var.y] != '1')
			player->py = var.y;
	}
	player->move = 1;
}

static void	rotate_player(t_launcher *ptr, int direction)
{
	t_player			*player;
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
	player->dir_x = player->dir_x * var.cos_theta - player->dir_y
		* var.sin_theta;
	player->dir_y = var.old_dirX * var.sin_theta + player->dir_y
		* var.cos_theta;
	player->plane_x = player->plane_x * var.cos_theta - player->plane_y
		* var.sin_theta;
	player->plane_y = var.old_planeX * var.sin_theta + player->plane_y
		* var.cos_theta;
	ptr->i->player->move = 1;
}

int	event_key(int k_code, t_launcher *ptr)
{
	t_player	*player;

	player = ptr->i->player;
	if (k_code == XK_Escape)
		return (close_window_x(ptr));
	if (k_code == XK_w || k_code == 122)
		move_player(ptr, player->dir_x, player->dir_y);
	if (k_code == XK_s)
		move_player(ptr, -player->dir_x, -player->dir_y);
	if (k_code == XK_a || k_code == 113)
		move_player(ptr, -player->dir_y, player->dir_x);
	if (k_code == XK_d)
		move_player(ptr, player->dir_y, -player->dir_x);
	if (k_code == 65363)
		rotate_player(ptr, -1);
	if (k_code == 65361)
		rotate_player(ptr, 1);
	return (0);
}

int	close_window_x(t_launcher *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->mlx_win);
	mlx_destroy_display(c->mlx);
	free(c->name);
	free(c->mlx);
	free(c->raycast->axis);
	clean_textures(c);
	free(c->raycast);
	free(c->i->player);
	clean_map(c->i->map);
	clean_header(c->i->header);
	free(c->i);
	free(c);
	exit(0);
}
