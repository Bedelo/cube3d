#ifndef MYSTRUCT_H
# define MYSTRUCT_H


typedef struct s_moving_utils
{
	int		rot_dir;
	int		ud_dir;
	int		lr_dir;
}				t_moving_utils;

typedef struct s_player
{
	double			px;
	double			py;
	double			xx;
	double			yy;
	double			angle;
	t_moving_utils	move_utils;
} 					t_player;

typedef struct s_header
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			t_header;

typedef struct s_map_creation
{
	char	*file;
	char	**my_map;
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

// typedef struct s_ray
// {
// 	double		dist;
// 	double		x_origin;
// 	double		y_origin;
// 	double		x_;
// 	double		y_;
// 	double		x_intercept;
// 	double		y_intercept;

// }			t_ray;

typedef struct s_launcher
{
	char		*name;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_infos		*i;
}				t_launcher;

#endif
