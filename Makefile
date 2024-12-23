SRC_FILES = 	src/main.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				utils/utils.c utils/ft_split.c utils/utils2.c \
				src/starting_game.c
OBJ_FILES = $(SRC_FILES:.c=.o)

HEADER_FILES = Includes/cube.h Includes/get_next_line.h
NAME = cub3D
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:	$(NAME)

$(NAME):$(OBJ_FILES)
		cc  $(CFLAGS) $(OBJ_FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c  $(HEADER_FILES)
				cc -c $(CFLAGS) $< -o $@

clean:
				$(RM) $(OBJ_FILES)


fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)