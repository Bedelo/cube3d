/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:19 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/17 14:52:46 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

/*
	DESSINE DANS LE BUFFER
 */
// void	put_pixel_to_buffer(t_data *ptr, int x, int y, int color)
// {
// 	if (x >= 0 && x < SCR_WIDTH && y >= 0 && y < SCR_HEIGHT)
// 		ptr->data[y * ptr->line_length + x * (ptr->bits_per_pixel / 8)] = color;
// }

void	put_pixel_to_buffer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clear_image(t_launcher *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCR_WIDTH)
	{
		x = 0;
		while (x < SCR_HEIGHT)
		{
			put_pixel_to_buffer(&ptr->img, x, y, 0xFFFF00);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img.img, 0, 0);
}

static int	get_tex_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (2); // texture EST
		return (3);     // texture WEST
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (1); // texture SOUTH
		return (0);     // texture NORTH
	}
}

//          a refaire

void	print_pixels(t_launcher *ptr, t_ray *ray, int x)
{
	int	y;
	int	tex_index;

	// on verifie que `ray->wall` est dans le rang correct
	ray->tex_x = (int)(ray->wall * (double)TEX_WIDTH);
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= TEX_WIDTH)
	ray->tex_x = TEX_WIDTH - 1;
	// On corrige l'inversion de la texture
	if ((ray->side == 1 && ray->ray_dir_y < 0) || (ray->side == 0
		&& ray->ray_dir_x > 0))
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
		ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
		ray->texture_pos = (ray->draw_start - TEX_HEIGHT / 2.0 + ray->line_height / 2) * ray->step;
		y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->texture_id = get_tex_id(ray);
		if (ray->draw_end - ray->draw_start > 0)
		ray->tex_y = (int)ray->texture_pos & (TEX_HEIGHT - 1);
		// ray->tex_y = ((y - ray->draw_start) * TEX_HEIGHT) / (ray->draw_end
		// 	- ray->draw_start);
		else
			ray->tex_y = 0;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= TEX_HEIGHT)
			ray->tex_y = TEX_HEIGHT - 1;
		ray->texture_pos += ray->step;
		ray->color = ptr->texture[ray->texture_id][TEX_HEIGHT * ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		// Evitar acceso fuera de memoria en `tex->data`
		// tex_index = ray->tex_y * TEX_WIDTH + ray->tex_x;
		// if (tex_index >= 0 && tex_index < TEX_WIDTH * TEX_HEIGHT)
		// 	ray->color = tex->data[tex_index];
		// else
		// 	ray->color = 0xFFFFFF; // Color de seguridad
		put_pixel_to_buffer(&ptr->img, x, y, ray->color);
		y++;
	}
}

// void	print_pixels(t_launcher *ptr, t_ray *ray, int x)
// {
// 	t_player		*player;
// 	t_texture		*tex;
// 	t_var_texture	var;
// 	int				y;

// 	printf("DENTRO DE PIXELS\n");
// 	/*
// 		choix de la texture par rapport aux valeurs side et ray_dir_x et side_dir_y

//           ↑ (North, 0)
//         ┌───┬───┬───┬───┐
//     W ← │ 3 │   │   │ 2 │ → E
//         ├───┼───┼───┼───┤
//           ↓ (South, 1)
// 		*/
// 	ray->texture_id = get_tex_id(ray);
// 	printf("ray->texture_id = %d\n", ray->texture_id);

// 	/*
// 		Coordonnee de la texture en X:

// 		wall nous indique ou le rayon a frappe
// 		on multiplie par width pour obtenir la coordonne de X de la texture

// Texture (64px de width)
// +----+----+----+----+
// |  0 | 16 | 32 | 48 |  ← Coordonnees X dans la texture
// +----+----+----+----+

// Si `wall_x = 0.75` et `TEX_WIDTH = 64`:
// tex_x = 0.75 * 64 = 48

// 		L'impacte est a  75% de la texture, donc on prends tex_x = 48;
// 		*/
// 	ray->tex_x = (int)(ray->wall * TEX_WIDTH);

// 	printf("ray->tex = %d\n", ray->tex_x);
// /*
// 		Ajustement des murs pour les directions oposees:

// 		on corrige tex_x si le mur frappe est du cote droite ou superieur,
//			sinon les textures vont apparaitres a l'invers dans certains mur

// 		Si le rayon vient de la gauche et hit un mur en X,
//			la texture pourrait rester a l'invers. ceci corrige ce default
//  */
// 	if ((ray->side == 1 && ray->ray_dir_x > 0) ||
// 		(ray->side == 0 && ray->ray_dir_y < 0))
// 		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;

// /*
// 		On calcule la ou ca commance et la ou ca fini dans l'ecran:

// 		line_height nous indique combien de grand est le mur
// 		SRC_HEIGHT / 2 centre le mur dans l'ecran

// 		On se rasure que start et end ne sort pas de la fenetre
//  */
// 	ray->draw_start = -ray->line_height / 2 + SCR_HEIGHT / 2;
// 	if (ray->draw_start < 0)
// 		ray->draw_start = 0;
// 	ray->draw_end = ray->line_height / 2 + SCR_HEIGHT / 2;
// 	if (ray->draw_end >= SCR_HEIGHT)
// 		ray->draw_end = SCR_HEIGHT - 1;
// 	y = ray->draw_start;

// /*
// 		DANS LA BUCLE:

// 		On mets des pixels dans le buffer:

// 		pour tex_y: on converti la position de l'ecran Y pour une coordonnee de la texture (tex_x)
// 		on multiplie par height pour mapper correctement les pixels.

// Si `TEX_HEIGHT = 64` et `y` est dans la moitie:
// tex_y = (32 * 64) / 64 = 32

// on obtient le pixel exacte qu'on doit extraire de la texture

// --------------------------------------------------------------------

// 	color:
// 		on obtient la position exacte du vector de la texture (tex_data)

// Si `tex_x = 48` et `tex_y = 32`, l'index est:
// index = 32 * 64 + 48 = 2080

// c'est la couleur exacte du pixel de la texture

//  */
// 	printf("antes de la bucle\n");
// 	while (y < ray->draw_end)
// 	{
// 		ray->tex_y = ((y * 2 - SCR_HEIGHT + ray->line_height) + TEX_HEIGHT /
// 				(2 * ray->line_height));
// 		ray->color = (int)tex->data[ray->tex_y * TEX_WIDTH + ray->tex_x];
// 		put_pixel_to_buffer(&ptr->img, x, y, ray->color);
// 		y++;
// 	}
// }
