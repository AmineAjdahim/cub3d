NAME = cub3D
LIBS = libft/libft.a \

CC = gcc
FLAGS = -Wall -Werror -Wextra -g \
      -I /usr/local/include \
      -L /usr/local/lib -lmlx \
      -framework OpenGL -framework AppKit \

MAKE = make -C
SRC = oldtest1.c main.c readfile.c readfile2.c read_map.c drawing.c check_map.c heroz_vertical.c read_map2line.c printerror_init_varset.c draw_wall_heavens_rect.c
all: $(NAME)
$(NAME):
    @$(MAKE)    libft
    @$(CC)	$(FLAGS)    $(SRC)  $(LIBS) -o  $(NAME)
clean:
    @$(MAKE)libft clean
    @rm -rf $(OBJ)
fclean: clean
    @$(MAKE) libft fclean
    @rm -f cub3D
re: fclean all