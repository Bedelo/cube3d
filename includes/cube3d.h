#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
#include <errno.h>
# include "render2D.h"

# define PI 3.14159265358979323846
# define INCORRECT_PLAYER "Error: INCORRECT PLAYER\n"
# define ERROR_INITIALISATION "ERROR: INITIALISATION MLX ERROR OCCURS\n"
# define SCR_WIDTH 720
# define SCR_HEIGHT 720
# define TEXTURE_DIM 1080
# define ERROR "Error:\n"
# define ERROR_MAP "Error: MAP IS WRONG\n"
# define ERROR_HEADER "Error: HEADER IS WRONG\n"
# define KO 1
# define STOP -2
# define OK 0
# define ROT_SPEED 0.15
# define MOVE_SPEED 0.75


int				len_x(int fd, int *header_len);
int				len_y(int fd, int *header_len);
int				ft_handle_map(char *file, char *extension);
int				map_dim(int *dim, char *file, int (*f) (int, int*), int *h);

void			ft_freenstr(int n, void *str, ...);
unsigned int	to_color_rc(char *str);
int				rgbToHex(int r, int g, int b);

int				*player_position(t_map_creation **map);
void			ajust_angle(t_infos *infos);
int				*init_axis(t_launcher *launcher, t_raycast *rc);

void			free_all(t_launcher *launcher);
void			*shield_malloc(void *ptr);
void			*shield_malloc_2(char **ptr, int y);
void			clean_map(t_map_creation *m);
void			clean_header(t_header *header);

t_map_creation	*map_init(t_map_creation *m, char **av);
t_map_creation	*ft_map(t_map_creation **m, char **av);
void			display_map(t_map_creation *m);
int				check_enclosure_map(t_map_creation **map);
int				check_map(t_map_creation **map);


char			**header_label(char *header[7]);
t_header		*header_creation(char *file);
int				header_format(t_header *header);

void			error_init(void);
void			error_window(t_launcher *container);
void			error_image(t_launcher *container);

void			err(char *str);

int				check_is_header(char **line, int fd);
int				is_header(char *line, int fd);
int				check_is_map(char *file, int *header_len);


int				events_window(int keysym, t_launcher **launcher);
int				close_window_x(t_launcher *c);

t_infos			*init_player(t_infos **i);
t_raycast		*init_raycast(t_launcher *launcher);
t_infos			*init_infos(char **av, t_infos **i);
void			init_draw(t_launcher **launcher);
int				render(t_launcher *launcher);
#endif
