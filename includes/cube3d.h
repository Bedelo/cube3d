/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:45:31 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/28 20:01:35 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include "render2D.h"

# define PI 3.14159265358979323846
# define INCORRECT_PLAYER "Error: INCORRECT PLAYER\n"
# define ERROR_INITIALISATION "ERROR: INITIALISATION MLX ERROR OCCURS\n"
# define INCORRECT_CHAR "Error: INCORRECT CHAR\n"
# define SCR_WIDTH 720
# define SCR_HEIGHT 720
# define TEXTURE_DIM 256
# define ERROR "Error\n"
# define ERR_HEADER_1  "Creation header failed!\n"
# define ERR_HEADER_0  "PATH or HEADER issue!\n"
# define ERR_HEADER_2  "Double label in header\n"
# define ERROR_MAP "Error: MAP IS WRONG\n"
# define KO 1
# define STOP -2
# define OK 0
# define EH "Error\nCreation header failed!\n"
# define ROT_SPEED 0.15
# define MOVE_SPEED 0.15
# define FOV 0.66
# define COS_ANGLE 0.9971871872
# define SIN_ANGLE 0.0749297073
# define COS_NEG_ANGLE 0.9971871872
# define SIN_NEG_ANGLE -0.0749297073

int				len_x(int fd, int *header_len);
int				len_y(int fd, int *header_len);
int				ft_handle_map(char *file, char *extension);
int				map_dim(int *dim, char *file, int (*f) (int, int*), int *h);
int				header_issue(char *split_line);
void			ft_freenstr(int n, void *str, ...);
unsigned int	to_color_rc(char *str);
int				rgbToHex(int r, int g, int b);

int				*player_position(t_map_creation **map);
void			ajust_angle(t_infos *infos);
int				*init_axis(t_launcher *launcher, t_raycast *rc);

void			free_all(t_launcher *launcher);
void			*shield_malloc(void *ptr);
void			*shield_malloc_2(char **ptr, int y);
void			free_map(t_map_creation *m);
void			clean_map(t_map_creation *m);
void			clean_header(t_header *header);
void			clean_textures(t_launcher *ptr);

t_map_creation	*map_init(t_map_creation *m, char **av);
t_map_creation	*ft_map(t_map_creation **m);
void			display_map(t_map_creation *m);
int				check_enclosure_map(t_map_creation **map);
int				check_map(t_map_creation **map);

char			**header_label(char *header[7]);
t_header		*header_creation(char *file);
int				header_format(t_header *header, int fd);

int				check_header_no_cardinal(char *file);
int				check_header_cardinal(char *file);

void			error_init(void);
void			error_window(t_launcher *container);
void			error_image(t_launcher *container);

void			err(char *str);

char			**fill_map(t_map_creation **map, int k);

int				check_is_header(char **line, int fd);
int				is_header(char *line, int fd);
int				check_is_map(char *file, int *header_len);

int				events_window(int keysym, t_launcher **launcher);
int				close_window_x(t_launcher *c);

t_infos			*init_player(t_infos **i);
t_raycast		*init_raycast(t_launcher *launcher);
t_infos			*init_infos(char **av, t_infos *i);
void			init_draw(t_launcher **launcher);
int				render(t_launcher *launcher);
/*		events.c				*/
int				event_key(int k_code, t_launcher *ptr);
/*		print_screen.c			*/
void			put_pixel_to_buffer(t_data *ptr, int x, int y, int color);
void			clear_image(t_launcher *launcher);
void			print_pixels(t_launcher *launcher, t_ray *ray, int x);
/*		raycasting.c			*/
void			draw_cube3d(t_launcher *ptr);
void			setup_ray(t_ray *ray, int x, t_launcher *launcher);
/*		raycasting_utils.c		*/
void			dda(t_ray *ray, t_launcher *launcher);
void			line_height(t_ray *ray, t_player *player);
void			draw_floor_ceiling(t_launcher *ptr, int x, int d_s, int d_e);
/*		texture.c				*/
void			init_textures(t_launcher *ptr);
int				events_key(int keycode, t_launcher *launcher);
void			init_player_direction(char direction, t_player *player);

#endif
