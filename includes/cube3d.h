#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include "render2D.h"

# define PI 3.14159265358979323846
# define INCORRECT_PLAYER "Error: INCORRECT PLAYER\n"
# define ERROR_INITIALISATION "ERROR: INITIALISATION MLX ERROR OCCURS\n"
# define SCR_WIDTH 720
# define SCR_HEIGHT 720
# define ERROR "Error\n"
# define ERROR_MAP "Error: MAP IS WRONG\n"
# define ERROR_HEADER "Error: HEADER IS WRONG\n"
# define KO 1
# define OK 0

int				len_x(int fd, int *header_len);
int				len_y(int fd, int *header_len);
int				ft_handle_map(char *file);
int				map_dim(int *dim, char *file, int (*f) (int, int*), int *h);

int				*player_position(t_map_creation **map);

void			*shield_malloc(void *ptr);
void			*shield_malloc_2(char **ptr, int y);
void			free_2(char **split);
void			clean_map(t_map_creation *m);
void			clean_header(t_header *header);

t_map_creation	*map_init(t_map_creation *m, char **av);
t_map_creation	*ft_map(t_map_creation **m, char **av);
void			display_map(t_map_creation *m);
int				check_enclosure_map(t_map_creation **map);
int				check_map(t_map_creation **map);


char			**header_label(char *header[7]);
t_header		*header_creation(char *file);

void			error_init(void);
void			error_window(t_container *container);
void			error_image(t_container *container);

void			err(char *str);

int				check_is_header(char **line, int fd);
int				is_header(char *line, int fd);
int				check_is_map(char *file, int *header_len);

int				init_draw(t_launcher **launcher);
#endif
