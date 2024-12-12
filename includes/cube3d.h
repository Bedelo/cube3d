#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define INCORRECT_PLAYER "Error: INCORRECT PLAYER\n"
# define ERROR_INITIALISATION "ERROR: INITIALISATION MLX ERROR OCCURS\n"
# define SCR_WIDTH 720
# define SCR_HEIGHT 720
# define ERROR "Error\n"
# define ERROR_MAP "Error: MAP IS WRONG\n"
# define ERROR_HEADER "Error: HEADER IS WRONG\n"
# define FAIL (-1)										//! Norme
# define KO 1
# define OK 0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coord
{
	long long	xx;
	long long	yy;
}			t_coord;

typedef struct s_header
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			t_header;

typedef struct s_container
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_coord	coord;
}			t_container;


typedef struct s_map_creation
{
	char	*file;
	char	**my_map;
	t_coord	coord;
	int		*dim;
	int		fd;
	int		i;
	int		header_len;
	char	*line;
	int		flag;
	int		*pos;
}			t_map_creation;

typedef struct s_infos
{
	t_map_creation	*map;
	t_header		*header;
}					t_infos;

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

char			**header_label(char *header[7]);
t_header		*header_creation(char *file);

void			error_init(void);
void			error_window(t_container *container);
void			error_image(t_container *container);

void			err(char *str);

int				check_is_header(char **line, int fd);
int				is_header(char *line, int fd);
int				check_is_map(char *file, int *header_len);

#endif
