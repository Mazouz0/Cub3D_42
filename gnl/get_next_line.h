/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:18 by alamini           #+#    #+#             */
/*   Updated: 2024/12/23 20:21:23 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char	*s1, char	*s2);
void	*gnl_strcpy(char *s1, char *s2, char *res);
int		gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strdup(char *s1);
#endif