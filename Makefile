NAME = cub3D

LIBS = libft/libft.a \

CC = gcc

FLAGS = -I /usr/local/include \
	  	-L /usr/local/lib -lmlx \
	  	-framework OpenGL -framework AppKit \

MAKE = make -C

SRC = get_next_line/get_next_line.c oldtest1.c main.c readfile.c readfile2.c read_map.c drawing.c check_map.c heroz_vertical.c read_map2line.c printerror_init_varset.c draw_wall_heavens_rect.c draw_sprites.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(MAKE) libft
	@$(CC) $(FLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) libft clean
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) libft fclean
	@rm -f cub3D

re:	fclean all