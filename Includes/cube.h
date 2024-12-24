/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:17:13 by alamini           #+#    #+#             */
/*   Updated: 2024/12/24 18:26:40 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "get_next_line.h"
# include "../MLX/.MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_cordinates
{
    int x;
    int y;
} t_cordinates;

typedef struct s_elements
{
    int map;
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;
    int total;
}t_elements;

typedef struct s_map
{
    char **the_map;
    int max_column;
    int max_row;
    int start;
    t_cordinates player;
    int     direction;
}t_map
;
typedef struct s_gdata
{
    t_map  map;
    char *north;
    char *south;
    char *west;
    char *east;
    int floor;
    int ceiling;
    char *file;
} t_gdata;



// 



// libft utils
char	*ex_strjoin(char	*s1, char	*s2);
char	**ft_split(char const *s, char c);
int	    ex_strcmp(char *s1, char *s2);
size_t	ex_strlen(const char *s);
char	*ex_strdup(const char *s1);
int     ft_isdigit(int c);
int     is_number(char *number);
int	    ft_atoi(const char *str);


// special utils
int     get_rgba(int r, int g, int b, int a);
int     count_elements(char **dbl_arr);
void    view_map(t_gdata *game);
int     in_set(char *set, char c);
int     ft_error(char *errmsg);

// Game phases
t_gdata	*parsing(int argc, char **argv);


// parsing utils
// --> textures and colors
int     textures_colors_parse(int fd, t_gdata *game);
void    set_color(char *identifier, int arr[3], t_gdata *game);
void    set_texture(char *identifier, char *path, t_gdata *game);
int     validate_texture_color(char *line, t_elements *elements, t_gdata *game);
// --> map
int map_parse(int fd, t_gdata *game);
int get_map(int fd, t_gdata *game);
int validate_map(t_map map);
int map_borders(t_map map);
int row_length(char *line);


#endif