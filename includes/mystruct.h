#ifndef MYSTRUCT_H
# define MYSTRUCT_H

typedef struct s_player
{
	double	px;
	double	py;
	double	xx;
	double	yy;
	double	angle;
} 			t_player;

typedef struct s_header
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			t_header;

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_coord
{
	long long	xx;
	long long	yy;
}			t_coord;

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
	t_player		*player;
}					t_infos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_container
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_container;

typedef struct s_launcher
{
	t_container	*c;
	t_infos		*i;
	t_player	*p;
}				t_launcher;

#endif
