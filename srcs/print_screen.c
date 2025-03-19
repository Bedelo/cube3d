/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:19 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/19 15:36:42 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

/*
	DESSINE DANS LE BUFFER
 */
void	put_pixel_to_buffer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_tex_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (2);
		return (3);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (1);
		return (0);
	}
}

static void	put_texture_to_buffer(t_launcher *ptr, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->texture_id = get_tex_id(ray);
		if (ray->draw_end - ray->draw_start > 0)
			ray->tex_y = (int)ray->texture_pos & (TEXTURE_DIM - 1);
		else
			ray->tex_y = 0;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= TEXTURE_DIM)
			ray->tex_y = TEXTURE_DIM - 1;
		ray->texture_pos += ray->step;
		ray->color = ptr->raycast->texture[ray->texture_id][TEXTURE_DIM * ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		put_pixel_to_buffer(&ptr->img, x, y, ray->color);
		y++;
	}
}

void	print_pixels(t_launcher *ptr, t_ray *ray, int x)
{
	ray->tex_x = (int)(ray->wall * (double)TEXTURE_DIM);
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= TEXTURE_DIM)
		ray->tex_x = TEXTURE_DIM - 1;
	if ((ray->side == 1 && ray->ray_dir_y < 0) || (ray->side == 0
			&& ray->ray_dir_x > 0))
		ray->tex_x = TEXTURE_DIM - ray->tex_x - 1;
	ray->step = 1.0 * TEXTURE_DIM / ray->line_height;
	ray->texture_pos = (ray->draw_start - TEXTURE_DIM / 2.0 + ray->line_height
			/ 2) * ray->step;
	put_texture_to_buffer(ptr, ray, x);
}
