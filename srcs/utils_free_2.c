/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:22:50 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/24 13:50:07 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	header_cardinal(t_header *header)
{
	if (header->no)
	{
		shield_malloc(header->no);
	}
	if (header->so)
	{
		shield_malloc(header->so);
	}
	if (header->we)
	{
		shield_malloc(header->we);
	}
	if (header->ea)
	{
		shield_malloc(header->ea);
	}
}

static void	header_floor_celling(t_header *header)
{
	if (header->f)
	{
		shield_malloc(header->f);
	}
	if (header->c)
	{
		shield_malloc(header->c);
	}
}

void	clean_header(t_header *header)
{
	header_cardinal(header);
	header_floor_celling(header);
	shield_malloc(header);
}

void	clean_textures(t_launcher *ptr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		shield_malloc(ptr->raycast->texture[i]);
		i++;
	}
}

void	free_all(t_launcher *launcher)
{
	shield_malloc (launcher->i->player);
	clean_header(launcher->i->header);
	clean_map(launcher->i->map);
	shield_malloc(launcher->i);
	shield_malloc(launcher->raycast->axis);
	clean_textures(launcher);
	shield_malloc(launcher->raycast);
	shield_malloc(launcher);
}
