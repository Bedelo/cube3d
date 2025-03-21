/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:22:50 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/21 09:47:32 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	header_cardinal(t_header *header)
{
	if (header->no)
	{
		free(header->no);
		header->no = NULL;
	}
	if (header->so)
	{
		free(header->so);
		header->so = NULL;
	}
	if (header->we)
	{
		free(header->we);
		header->we = NULL;
	}
	if (header->ea)
	{
		free(header->ea);
		header->ea = NULL;
	}
}

static void	header_floor_celling(t_header *header)
{
	if (header->f)
	{
		free(header->f);
		header->f = NULL;
	}
	if (header->c)
	{
		free(header->c);
		header->c = NULL;
	}
}

void	clean_header(t_header *header)
{
	header_cardinal(header);
	header_floor_celling(header);
	free(header);
	header = NULL;
}

void	clean_textures(t_launcher *ptr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(ptr->raycast->texture[i]);
		ptr->raycast->texture[i] = NULL;
		i++;
	}
}

void	free_all(t_launcher *launcher)
{
	free(launcher->i->player);
	clean_header(launcher->i->header);
	clean_map(launcher->i->map);
	free(launcher->i);
	free(launcher->raycast->axis);
	clean_textures(launcher);
	free(launcher->raycast);
	free(launcher);
}
