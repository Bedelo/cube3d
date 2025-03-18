#ifndef MYSTRUCT_H
# define MYSTRUCT_H


// condition if rotate forward backward left or right
// typedef struct s_moving_utils
// {
// 	int		rot_dir;
// 	int		ud_dir;
// 	int		lr_dir;
// }				t_moving_utils;

/*
	VARIABLES AUXILIAIRES POUR LES EVENTS
 */
typedef struct 		s_event_variable
{
	double			old_dirX;
	double			old_planeX;
	double			cos_theta;
	double			sin_theta;
	int				x;
	int				y;
	char			**map;
}					t_event_variable;

// infos about player
typedef struct s_player
{
	double			px;
	double			py;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				move;
	// double			xx;
	// double			yy;
	// double			angle;
	// t_moving_utils	move_utils;
} 					t_player;

typedef struct s_ray
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			d_dist_x;
	double			d_dist_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			step;
	int				side;
	double			dist_perp;
	double			wall;
	double			camera;
	double			line_height;
	int				texture_id;
	double			texture_pos;
	int				tex_x;
	int				tex_y;
	int				draw_start;
	int				draw_end;
	int				color;
}					t_ray;

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
	char	init_dir;
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
	int		*data;
	int				width;
	int				height;
}				t_data;

typedef struct s_raycast
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				dim_texture_x;
	int				dim_texture_y;
	int				*texture[4];
	t_data			img;
	// t_texture		*texture;
	unsigned int	f_color;
	unsigned int	c_color;
	int				*axis;
}					t_raycast;

typedef struct s_launcher
{
	char		*name;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_infos		*i;
	t_raycast	*raycast;
}				t_launcher;

#endif
