/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:17:13 by alamini           #+#    #+#             */
/*   Updated: 2024/12/05 06:14:54 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

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

typedef struct s_game
{
    char **map;
    char *north;
    char *south;
    char *west;
    char *east;
    char *floor;
    char *ceiling;
} t_game;


// utils
char	*ex_strjoin(char	*s1, char	*s2);
char	**ft_split(char const *s, char c);
int     count_elements(char **dbl_arr);
int     ft_error(char *errmsg);
int	    ex_strcmp(char *s1, char *s2);
size_t	ex_strlen(const char *s);
char	*ex_strdup(const char *s1);
#endif