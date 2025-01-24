SRC_FILES = Mandatory/Execution/main.c Mandatory/Execution/draw_utils.c Mandatory/Execution/draw.c Mandatory/Execution/exec.c \
			Mandatory/Parsing/index.c Mandatory/Execution/init_funcs.c Mandatory/Parsing/map.c Mandatory/Parsing/map2.c Mandatory/Execution/player_hooks.c \
			Mandatory/Textures/put_textures.c Mandatory/Execution/ray_casting.c Mandatory/Parsing/textures_colors.c \
			Mandatory/Parsing/textures_colors2.c Mandatory/Parsing/textures_utils.c Mandatory/Utils/utils_1.c Mandatory/Utils/utils_2.c \
			Mandatory/Utils/ft_split.c Mandatory/Utils/special_utils.c Mandatory/Utils/utils.c Mandatory/Utils/utils2.c \

BONUS_SRC_FILES =	Bonus/Execution/main_bonus.c Bonus/Utils/utils2_bonus.c Bonus/Utils/utils_bonus.c Bonus/Utils/utils_2_bonus.c \
					Bonus/Utils/utils_1_bonus.c Bonus/Parsing/textures_utils_bonus.c Bonus/Parsing/textures_colors2_bonus.c \
					Bonus/Parsing/textures_colors_bonus.c Bonus/Utils/special_utils_bonus.c Bonus/Execution/ray_casting_bonus.c \
					Bonus/Textures/put_textures_bonus.c Bonus/Execution/player_utils_bonus.c Bonus/Execution/player_hooks_bonus.c \
					Bonus/Execution/open_dors_bonus.c Bonus/Parsing/map2_bonus.c Bonus/Parsing/map_bonus.c Bonus/Execution/init_funcs_bonus.c \
					Bonus/Parsing/index_bonus.c Bonus/Utils/ft_split_bonus.c Bonus/Execution/exec_bonus.c \
					Bonus/Execution/draw_bonus.c Bonus/Execution/draw_utils_bonus.c Bonus/Animation/animation_bonus.c Bonus/Animation/animation_utils_bonus.c \

GNL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

HEADER_FILES = Mandatory/cub3d.h gnl/get_next_line.h Bonus/cub3d_bonus.h

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math

MLX =	MLX/libglfw3.a MLX/libmlx42.a -framework \
		Cocoa -framework OpenGL -framework IOKit

RM = rm -f

all:	$(NAME)

$(NAME)			:	$(OBJ_FILES) $(GNL_OBJ)
					cc $(CFLAGS) $(OBJ_FILES) $(GNL_OBJ) $(MLX) -o $(NAME)

bonus: $(BONUS_OBJ_FILES) $(GNL_OBJ)
	cc $(CFLAGS) $(BONUS_OBJ_FILES) $(GNL_OBJ) $(MLX) -o $(NAME)

%.o : %.c  $(HEADER_FILES)
				cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES) $(BONUS_OBJ_FILES) $(GNL_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re