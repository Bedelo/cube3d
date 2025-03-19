/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:26 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/19 15:50:27 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	handle_event(t_launcher *c)
{
	mlx_hook(c->mlx_win, 2, 1L << 0, event_key, c);
	mlx_hook(c->mlx_win, 17, 0, close_window_x, c);
}
