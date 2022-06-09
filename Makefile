SRC_BNS			=	getnext_line/get_next_line_utils.c getnext_line/get_next_line.c \
	draw.c	exit_game.c	gameplay.c	init.c	map_validate.c player_update.c	read_map.c	so_long.c move.c
SRC				=	getnext_line/get_next_line_utils.c getnext_line/get_next_line.c \
	draw_copy.c	exit_game_copy.c	gameplay_copy.c	init_copy.c	map_validate_copy.c player_update_copy.c	read_map_copy.c	so_long_copy.c


OBJ_BNS			=	$(addprefix obj/, ${SRC_BNS:.c=.o})
OBJ				=	$(addprefix obj/, ${SRC:.c=.o})


CC				=	cc

CFLAGS 			=	-Wall -Werror -Wextra -g

RM 				=	rm -f

LIBS_BNS		=	so_long_bonus.h
LIBS			=	so_long.h

NAME_BNS		=	so_long_bonus
NAME			=	so_long

LIBRARY = libft/libft.a

MINILIBX	=	-L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all:	$(NAME_BNS) $(NAME)

$(NAME_BNS) :$(LIBRARY)	$(OBJ_BNS) $(LIBS_BNS)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ_BNS) -g ${MINILIBX}  -o $(NAME_BNS)

$(NAME) :$(LIBRARY)	$(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ) -g ${MINILIBX}  -o $(NAME)



$(LIBRARY) :
	make -C libft

obj/%.o: %.c
	@ mkdir -p obj/getnext_line
	$(CC)  -c $< -o $@


fclean:
	make fclean -C libft
	$(RM) $(OBJ_BNS) $(OBJ) $(NAME_BNS) $(NAME)

re:			fclean $(OBJ_BNS) $(OBJ) $(NAME_BNS) $(NAME)
