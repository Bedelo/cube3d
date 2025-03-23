/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:51:02 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/23 09:33:50 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	main(int ac, char **av)
{
	t_launcher	*launcher;

	if (ac != 2)
		return (err(ERROR), err("Enter valid map\n"), 1);
	launcher = ft_calloc(1, sizeof(t_launcher));
	if (!launcher)
		return (1);
	*launcher = (t_launcher){0};
	launcher->i = init_infos(av, &launcher->i);
	if (!launcher->i)
		return (free(launcher), 1);
	launcher->raycast = init_raycast(launcher);
	if (!launcher->raycast)
		return (free_all(launcher), 1);
	render(launcher);
	return (0);
}
