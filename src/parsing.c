/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:16:39 by alamini           #+#    #+#             */
/*   Updated: 2024/12/23 20:31:32 by mohmazou         ###   ########.fr       */
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

void set_texture(char *identifier, char *path, t_gdata *game)
{
	if (!ex_strcmp(identifier, "NO"))
		game->north = path;
	else if (!ex_strcmp(identifier, "SO"))
		game->south = path;
	else if (!ex_strcmp(identifier, "WE"))
		game->west = path;
	else if (!ex_strcmp(identifier, "EA"))
		game->east = path;
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void set_color(char *identifier, int arr[3], t_gdata *game)
{
	if (!ex_strcmp(identifier, "F"))
		game->floor = get_rgba(arr[0], arr[1], arr[2], 0xAA);
	else if (!ex_strcmp(identifier, "C"))
		game->ceiling = get_rgba(arr[0], arr[1], arr[2], 0xAA);
}

int	check_texture(char *identifier, char *line, t_gdata *game)
{
	int i;
	char *tmp;
	char *path;
	int fd;

	tmp = line;
	i = 0;
	while (tmp && *tmp == ' ')
		tmp ++;
	tmp += 2;
	while (*tmp == ' ')
		tmp ++;
	path = malloc(ex_strlen(tmp));
	while (tmp[i] != '\n')
	{
		path[i] = tmp[i];
		i ++;
	}
	path[i] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	set_texture(identifier, path, game);
	return (close(fd), 0);
	return (0);
}

int is_color(char **dbl_ptr, t_elements *elements)
{
	if (count_elements(dbl_ptr) > 3)
		return (1);
	if (count_elements(dbl_ptr) == 3 && ex_strcmp(dbl_ptr[count_elements(dbl_ptr) - 1], "\n"))
		return (1);
	if (!ex_strcmp(dbl_ptr[0], "F"))
		return (elements->f += 1, 0);
	if (!ex_strcmp(dbl_ptr[0], "C"))
		return (elements->c += 1, 0);
	return (1);
}



int check_color(char *identifier, char *str, t_gdata *game)
{
	char **dbl_ptr;
	int	i;
	char *color;
	int	rgb[3];

	i = 0;
	color = malloc(ex_strlen(str));
	while (str[i] && str[i] != '\n')
	{
		color[i] = str[i];
		i++;
	}
	color[i] = '\0';
	dbl_ptr = ft_split(color, ',');
	if (count_elements(dbl_ptr) != 3)
		return (1);
	if (is_number(dbl_ptr[0]) || is_number(dbl_ptr[1]) || is_number(dbl_ptr[2]))
		return (1);
	rgb[0] = ft_atoi(dbl_ptr[0]);
	rgb[1] = ft_atoi(dbl_ptr[1]);
	rgb[2] = ft_atoi(dbl_ptr[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (free(color), 1);
	return (free(color), set_color(identifier, rgb, game), 0);
}

int	check_map_content(char *line, t_elements *elements, t_gdata *game)
{
	int ce;
	char **dbl_ptr;
	static int iteration;

	iteration++;
	dbl_ptr = ft_split(line, ' ');
	ce = count_elements(dbl_ptr);
	if (!ex_strcmp(dbl_ptr[0], "\n"))
		return (0);
	if (ce < 2)
		return (1);
	if (!is_a_direction(dbl_ptr[0], elements))
		return (check_texture(dbl_ptr[0], line, game));
	if (!is_color(dbl_ptr, elements))
		return (check_color(dbl_ptr[0], dbl_ptr[1], game));
	return (1);
}

t_gdata	*init_data(t_elements *elements, char *file)
{
	t_gdata *game;
	game = malloc(sizeof(t_gdata));
	if (!game)
	{
		ft_error("Allocation Error!!");
		exit(1);
	}
	elements->map = 0;
	elements->no = 0;
	elements->so = 0;
	elements->we = 0;
	elements->ea = 0;
	elements->f = 0;
	elements->c = 0;
	game->map.max_column = 0;
	game->map.max_row = 0;
	game->map.the_map = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->file = file;
	game->map.start = 0;
	return (game);
}

int	check_elements_count(t_elements elements)
{
	if (elements.no > 1
		|| elements.so > 1
		|| elements.we > 1
		|| elements.ea > 1
		|| elements.f > 1
		|| elements.c > 1)
		return (1);
	if (elements.no == 1
		&& elements.so == 1
		&& elements.we == 1
		&& elements.ea == 1
		&& elements.f == 1
		&& elements.c == 1)
		return (2);
	return (0);
}
int in_set(char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int is_valid(char *line, int *count)
{
	int i;
	char possible_chars[] = "\n01 NSWE";

	i = 0;
	while (line[i] && line[i] == ' ')
		i ++;
	if (line[i] != '1')
		return (1);
	while (line[i])
	{
		if (in_set(&possible_chars[4], line[i]))
			(*count)++;
		if (!in_set(possible_chars, line[i]))
			return (1);
		i++;
	}
	return (0);
}

int parse_line(char *line, int *count)
{
	if (!ex_strcmp(line, "\n"))
		return (1);
	if (is_valid(line, count))
		return (1);
	return (0);
}
int row_length(char *line)
{
	int i;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while ((line[i] == 32 && i >= 0) || line[i] == '\n' || line[i] == '\0')
		i--;
	i++;
	return (i);
}

void fill_map_info(char *line, t_gdata *game)
{
	int length;

	length = row_length(line);
	if (length > game->map.max_column)
		game->map.max_column = length;
	game->map.max_row++;
}

int map_parse(int fd, t_gdata *game)
{
	char *line;
	int count;

	line = get_next_line(fd);
	while (ex_strcmp(line, "\n") == 0)
	{
		game->map.start++;
		line = get_next_line(fd);
	}
	while (line)
	{
		if (parse_line(line, &count))
			return (1);
		else
		{
			fill_map_info(line, game);
		}
		line = get_next_line(fd);
	}
	if (count != 1)
	{
		return (1);
	}
	return (0);
}

char *get_row(char *line, t_gdata *game)
{
	char *row;
	int		i;

	i = 0;
	row = malloc(sizeof(char) * game->map.max_column + 1);
	if (!row)
		return (ft_error("Allocation Error!!"), NULL);
	while (i < row_length(line))
	{
		row[i] = line[i];
		i++;
	}
	while (i < game->map.max_column)
	{
		row[i] = 32;
		i++;
	}
	row[i] = '\0';
	return (row);
}

int get_map(int fd, t_gdata *game)
{
	int	i;
	char *line;
	char **grid;
	
	i = -1;
	grid = malloc((sizeof(char *) * game->map.max_row) + 1);
	if (fd == -1)
		return (ft_error("Allocation Error !!"), 1);
	close(fd);
	fd = open(game->file, O_RDONLY);
	while (++i < game->map.start) // skip untill map
		get_next_line(fd);
	i = 0;
	line = get_next_line(fd);
	while (line && i < game->map.max_row)
	{
		grid[i] = get_row(line, game);
		line = get_next_line(fd);
		i++;
	}
	grid[i] = NULL;
	game->map.the_map = grid;
	close(fd);
	return (0);
}


void view_map(t_gdata *game)
{
	int i = 0;
	int j = 0;
	

	while (i < game->map.max_row)
	{
		j = 0;
		while (j < game->map.max_column)
		{
			printf("%c ", game->map.the_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	is_sourounded_by_void(t_map map, int y, int x)
{
	char **grid;

	
	grid = map.the_map;
	if (!x || !y || x == map.max_column - 1 || y == map.max_row - 1)
		return (0);
	if (!in_set("01", grid[y - 1][x]))
		return (1);
	else if (!in_set("01", grid[y + 1][x]))
		return (1);
	else if (!in_set("01", grid[y][x - 1]))
		return (1);
	else if (!in_set("01", grid[y][x + 1]))
		return (1);
	return (0);
}

int validate_map(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.max_row)
	{
		j = 0;
		while (j < map.max_column)
		{
			if (in_set("NSEW0", map.the_map[i][j]))
			{
				if (is_sourounded_by_void(map, i, j))
				{
					ft_error("Invalid Map In");
					return (printf("X= %d, Y= %d\n", j, i), 1);
				}	
			}
			j++;
		}
		i++;
	}
	return (0);
}

int map_borders(t_map map)
{
	int i;
	char **grid;

	grid = map.the_map;
	i = 0;
	while (i < map.max_column)
	{
		if (!in_set("1 ", grid[0][i]) || !in_set("1 ", grid[map.max_row - 1][i]))
			return (ft_error("Looks like you forgot to build the walls ^_^"));
		i++;
	}
	i = 0;
	while (i < map.max_row)
	{
		if (!in_set("1 ", grid[i][0]) || !in_set("1 ", grid[i][map.max_column - 1]))
			return (ft_error("Looks like you forgot to build the walls ^_^"));
		i++;
	}
	return (0);
	
}


void	get_player_info(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->the_map[i])
	{
		j = 0;
		while (map->the_map[i][j])
		{
			if (in_set("NSEW", map->the_map[i][j]))
			{
				map->player.x = j;
				map->player.y = i;
				map->direction = map->the_map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

t_gdata	*parsing(int argc, char **argv)
{
	char	*line;
	t_elements	elem_parse;
	t_gdata		*game;
	int		fd;

	game = NULL;
	if (argc != 2)
		return (ft_error("Invalid arguments!!"), NULL);
	if (check_file_name(argv[1]))
		return (NULL);
	game = init_data(&elem_parse, argv[1]);
	fd = open(game->file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Invalid map file!!"), NULL);
	while ((line = get_next_line(fd)))
	{
		game->map.start++;
		if (check_map_content(line, &elem_parse, game))
			return (free(line), ft_error("Invalid map content!!"), NULL);
		free(line);
		if (check_elements_count(elem_parse) == 1)
			return (ft_error("Invalid map content!!"), NULL);
		else if (check_elements_count(elem_parse) == 2)
			break ;
	}
	if (map_parse(fd, game))
		return (ft_error("Invalid map content!!"), NULL);
	
	if (get_map(fd, game))
		return (NULL);
	if (map_borders(game->map) || validate_map(game->map))
		return (NULL);
	
	get_player_info(&game->map);
	return (game);







	
	// printf("%d\n", game->map.max_column);
	// printf("%d\n", game->map.max_row);
	// printf("Start :%d", game->map.start);
	// printf("x = %d\n", game->map.player.x);
	// printf("y = %d\n", game->map.player.y);
	// printf("direction = %c\n", game->map.direction);
	
	// printf("North :|%s|\n", game->north);
	// printf("South :|%s|\n", game->south);
	// printf("West :|%s|\n", game->west);
	// printf("East :|%s|\n", game->east);
	// printf("Floor :%d\n", game->floor);
	// printf("Ceiling :%d\n", game->ceiling);
	
	
}
int main(int argc, char **argv)
{
	t_gdata *game;
	game = parsing(argc, argv);
	if (game)
		view_map(game);
	printf("x = %d\n", game->map.player.x);
	printf("y = %d\n", game->map.player.y);
	printf("direction = %c\n", game->map.direction);
	return (0);
}