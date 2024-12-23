/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:17:13 by alamini           #+#    #+#             */
/*   Updated: 2024/12/21 19:41:58 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "get_next_line.h"
# include "mlx.h"
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
typedef struct s_game
{
    t_map  map;
    char *north;
    char *south;
    char *west;
    char *east;
    int floor;
    int ceiling;
    char *file;
    int width;
    int height;
} t_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// utils
char	*ex_strjoin(char	*s1, char	*s2);
char	**ft_split(char const *s, char c);
int     count_elements(char **dbl_arr);
int     ft_error(char *errmsg);
int	    ex_strcmp(char *s1, char *s2);
size_t	ex_strlen(const char *s);
char	*ex_strdup(const char *s1);
int     ft_isdigit(int c);
int     is_number(char *number);
int	    ft_atoi(const char *str);

// game

void    init_game(t_game *game);
#endif