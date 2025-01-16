/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:17:13 by alamini           #+#    #+#             */
/*   Updated: 2025/01/16 19:15:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "get_next_line.h"
# include "../MLX/.MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define WIND_WID 1920
# define WIND_HEI 1080
# define TIL_SIZE 16
# define FOV 60
# define MOV_SPEED 2
# define ROT_SPEED 0.05
# define MAP_SCALE 1
# define WALL_BUFFER 2
# define PLAYER_SIZE 5

typedef struct s_cordinates
{
	int	x;
	int	y;
}	t_cordinates;

typedef struct s_anim_dt {
    uint32_t    width;
    uint32_t    height;
    uint32_t    *pixels;  // Array to store RGBA values
} t_anim_dt;

typedef struct s_elements
{
	int	map;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	total;
}	t_elements;

typedef struct s_map
{
	char			**the_map;
	int				max_column;
	int				max_row;
	int				start;
	t_cordinates	player;
	int				direction;
}	t_map;

typedef struct s_gdata
{
	t_map	map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	char	*file;
}	t_gdata;

//exec start :

typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_texture;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	double	angle_dir;
	double	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
	int		m_x;
	int		m_y;
}	t_player;

typedef struct s_ray
{
	int		index;
	double	r_angle;
	double	horz_x;
	double	horz_y;
	double	vert_x;
	double	vert_y;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_data
{
	char		**map2d;
	int			map_w;
	int			map_h;
	int			f_clr;
	int			c_clr;
	t_texture	*txtr;
}	t_data;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*dt;
	t_player	*ply;
	t_ray		*ray;
	t_anim_dt	**anim;
}	t_game;

typedef struct s_utils
{
	double	top_x;
	double	top_y;
	double	left_x;
	double	left_y;
	double	right_x;
	double	right_y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_utils;

// libft utils
char	*ex_strjoin(char	*s1, char	*s2);
char	**ft_split(char const *s, char c);
int		ex_strcmp(char *s1, char *s2);
size_t	ex_strlen(const char *s);
char	*ex_strdup(const char *s1);
int		ft_isdigit(int c);
int		is_number(char *number);
int		ft_atoi(const char *str);
char	*my_strdup(const char *s1);
char	*ft_itoa(int n);

// special utils
int		get_rgba(int r, int g, int b, int a);
int		count_elements(char **dbl_arr);
void	view_map(t_gdata *game);
int		in_set(char *set, char c);
int		ft_error(char *errmsg);

// Game phases
t_gdata	*parsing(int argc, char **argv);

// parsing utils
// --> textures and colors
int		textures_colors_parse(int fd, t_gdata *game);
void	set_color(char *identifier, int arr[3], t_gdata *game);
void	set_texture(char *identifier, char *path, t_gdata *game);
int		validate_texture_color(char *line, t_elements *elements, t_gdata *game);
int		fill_rgb(t_gdata *game, char **dbl_ptr, char *identifier);
char	*get_line(char *tmp);
// --> map
int		map_parse(int fd, t_gdata *game);
int		get_map(int fd, t_gdata *game);
int		validate_map(t_map map);
int		map_borders(t_map map);
int		row_length(char *line);

// execution functions

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_game	*init_game(t_gdata *pars_data);
void	game_loop(void *param);
void	key_hook(mlx_key_data_t key_data, void *param);
void	draw_map(t_game *game);
void	player_hook(t_game *game, double move_x, double move_y);
void	ray_cast(t_game *game);
double	nor_angle(double angle);
int		unit_circle(float angle, char c);
void	draw_3d(t_game *game, t_ray *ray, int index);
void	put_pixel(mlx_image_t *img, int x, int y, int color);
void	draw_circle(mlx_image_t *mlx, int x, int y, long color);
void	draw_t_line(mlx_image_t *img, t_cordinates c1, t_cordinates c2,
			uint32_t color);
void	draw_rect(t_game *game, int x, int y, int color);
void	ft_clean(t_game *game, char *msg);
void	*ft_malloc(ssize_t size, int flag);
// textures
void	ray_3d(t_game *game, int index, t_ray *ray, double wall_height);
void	draw_animation(t_game *game);
#endif