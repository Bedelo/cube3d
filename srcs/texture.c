/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:33:33 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/17 16:29:09 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	alloc_textures(t_launcher *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		ptr->raycast->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_DIM
					* TEXTURE_DIM));
		if (!ptr->raycast->texture[i])
			printf("Memory allocation failed for texture array");
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEXTURE_DIM * TEXTURE_DIM)
		{
			ptr->raycast->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	set_texture(t_launcher *ptr, int *tex, char *path)
{
	t_data	img_tex;
	int		x;
	int		y;

	img_tex.img = mlx_xpm_file_to_image(ptr->mlx, path, &img_tex.width, &img_tex.height);
	if (!img_tex.img)
		return (0);
	img_tex.data = (int *)mlx_get_data_addr(img_tex.img, &img_tex.bits_per_pixel, &img_tex.line_length, &img_tex.endian);
	if (!img_tex.data)
		return (0);
	while (y < TEXTURE_DIM)
	{
		x = 0;
		while (x < TEXTURE_DIM)
		{
			tex[TEXTURE_DIM * y + x] = img_tex.data[TEXTURE_DIM * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(ptr->mlx, img_tex.img);
	return (1);
}

static void	prepare_textures(t_launcher *ptr)
{
	if (set_texture(ptr, ptr->raycast->texture[0], ptr->i->header->no) == 0)
		printf("ERROR TEXTURE NORD\n");
	if (set_texture(ptr, ptr->raycast->texture[1], ptr->i->header->so) == 0)
		printf("ERROR TEXTURE SOUTH\n");
	if (set_texture(ptr, ptr->raycast->texture[2], ptr->i->header->ea) == 0)
		printf("ERROR TEXTURE EAST\n");
	if (set_texture(ptr, ptr->raycast->texture[3], ptr->i->header->we) == 0)
		printf("ERROR TEXTURE WEST\n");
}

void	init_textures(t_launcher *ptr)
{

	alloc_textures(ptr);
	prepare_textures(ptr);
}
