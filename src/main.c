/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamini <alamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:16:39 by alamini           #+#    #+#             */
/*   Updated: 2024/12/05 06:13:10 by alamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cube.h"

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 4)
		return (ft_error("Invalid map name"));
	i--;
	if (file_name[i] != 'b' || file_name[i - 1] != 'u'
		|| file_name[i - 2] != 'c' || file_name[i - 3] != '.')
	{
		return (ft_error("Invalid map name"));
	}
	return (0);
}

int is_a_direction(char *str, t_elements *elements)
{
	if (!ex_strcmp(str, "NO"))
		return (elements->no += 1, 0);
	if (!ex_strcmp(str, "SO"))
		return (elements->so += 1, 0);
	if (!ex_strcmp(str, "WE"))
		return (elements->we += 1, 0);
	if (!ex_strcmp(str, "EA"))
		return (elements->ea += 1, 0);
	return (1);
}

int	check_texture(char *line)
{
	int i;
	char *tmp;
	char *path;

	tmp = line;
	i = 0;
	while (tmp && *tmp == ' ')
		tmp ++;
	tmp += 2;
	while (*tmp != ' ')
		tmp ++;
	// while (*tmp != '\n')
	// 	*path
	path = malloc(ex_strlen(tmp));
	while (tmp[i] != '\n')
	{
		path[i] = tmp[i];
		i ++;
	}
	printf("path = %s\n", path);
	return 0;

}
//
int check_map_content(char *line, t_elements *elements)
{
	int ce;
	char **dbl_ptr;

	dbl_ptr = ft_split(line, ' ');
	ce = count_elements(dbl_ptr);
	if (!ex_strcmp(dbl_ptr[0], "\n"))
		return (0);
	if (ce < 2)
		return (1);
	if (is_a_direction(dbl_ptr[0], elements) == 0)
		return (check_texture(line));
	// if (is_color(dbl_ptr[0], elements)) tal ghda check if ce > 2 || 
	// 	return (check_color(dbl_ptr));
	
	
	
	return (1);
}

void init_elements(t_elements *elements)
{
	elements->map = 0;
	elements->no = 0;
	elements->so = 0;
	elements->we = 0;
	elements->ea = 0;
	elements->f = 0;
	elements->c = 0;
}

int	main(int argc, char **argv)
{
	char	*line;
	t_elements	elements;
	int		fd;

	if (argc != 2)
		return (ft_error("Invalid arguments!!"));
	if (check_file_name(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Invalid map file!!"));
	init_elements(&elements);
	while ((line = get_next_line(fd)))
	{
		if (check_map_content(line, &elements))
			return (ft_error("Invalid map control"));
		free(line);
		
	}
}