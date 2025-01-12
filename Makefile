SRC_FILES = 	src/main.c \
				src/parse/index.c  src/parse/textures_colors.c src/parse/textures_colors2.c \
				src/parse/map.c src/parse/map2.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c \
				utils/utils.c utils/ft_split.c utils/utils2.c utils/special_utils.c \
				src/exec/init_funcs.c src/exec/exec.c src/exec/ray_casting.c \
				src/exec/utils_1.c src/exec/draw.c src/exec/player_hooks.c src/exec/draw_utils.c \
				src/exec/put_textures.c
				 
				
OBJ_FILES = $(SRC_FILES:.c=.o)

HEADER_FILES = Includes/cube.h Includes/get_next_line.h

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

# MLX = -I  Includes/libglfw3.a -I  Includes/libmlx42.a  -framework OpenGL -framework IOKit
MLX =	MLX/libglfw3.a MLX/libmlx42.a -framework \
		Cocoa -framework OpenGL -framework IOKit

RM = rm -f

all:	$(NAME)

$(NAME)			:	$(OBJ_FILES)
					cc $(CFLAGS) $(OBJ_FILES) $(MLX) -o $(NAME)

%.o : %.c  $(HEADER_FILES)
				cc $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJ_FILES)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re