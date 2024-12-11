#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../Libft/libft.h"
# include "./../rscs/minilibx-linux/mlx.h"
// # include <X11/X.h>
// # include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define ERROR_INITIALISATION "\n\nINITIALISATION ERROR OCCURS \n\n"
# define SCR_WIDTH 720
# define SCR_HEIGHT 720
# define FAIL (-1)
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

typedef struct s_container
{
	char	*name;
	void	*mlx;
	void	*win;
	t_data	img;
	t_coord	coord;
}			t_container;


typedef struct s_map_creation
{
	char	*file;
	char	**my_map;
	// int		dimX;
	// int		dimY;
	int		*dim;
	int		fd;
	int		i;
	int		header_len;
	char	*line;
	int		flag;
}			t_map_creation;

int				len_x(int fd, int *header_len);
int				len_y(int fd, int *header_len);
int				ft_handle_map(char *file);
int				map_dim(int *dim, char *file, int (*f) (int, int*), int *h);

void			*shield_malloc(void *ptr);
void			*shield_malloc_2(char **ptr, int y);
void			clean_map(t_map_creation *m);

void			display_map(t_map_creation *m, char **av);
t_map_creation	*ft_map(t_map_creation **m, char **av);

void			error_init(void);
void			error_window(t_container *container);
void			error_image(t_container *container);

int				check_is_header(char **line, int fd);
int				is_header(char *line, int fd);
int				check_is_map(char *file, int *header_len);

#endif
