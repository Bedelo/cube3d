/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:51:02 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/25 16:29:50 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	main(int ac, char **av)
{
	t_launcher	launcher;

	if (ac != 2)
		return (err(ERROR), err("Enter valid map\n"), 1);
	launcher = (t_launcher){0};
	(&launcher)->i = init_infos(av, (&launcher)->i);
	if (!(&launcher)->i)
		return (1);
	(&launcher)->raycast = init_raycast(&launcher);
	if (!(&launcher)->raycast)
		return (free_all(&launcher), 1);
	render(&launcher);
	return (0);
}
