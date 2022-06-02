SRC			=	getnext_line/get_next_line_utils.c getnext_line/get_next_line.c \
	draw.c	exit_game.c	gameplay.c	init.c	map_validate.c player_update.c	read_map.c	so_long.c move.c 

OBJ			=	$(addprefix obj/, ${SRC:.c=.o})
# OBJ			=	${SRC:.c=.o}


CC			=	cc

CFLAGS 		=	-Wall -Werror -Wextra -g

RM 			=	rm -f

LIBS		=	so_long.h

NAME		=	solong

LIBRARY = libft/libft.a

MINILIBX	=	-L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all:	$(NAME)
# $(SERVER)	: $(LIBS) $(OBJS_S)
# 	$(CC) $(CFLAGS)  $(OBJS_S)  -o $(SERVER)

$(NAME):$(LIBRARY)	$(OBJ) $(LIBS) 
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ) -g ${MINILIBX}  -o $(NAME)


$(LIBRARY) : 
	make -C libft
obj/%.o: %.c 
	@ mkdir -p obj/getnext_line 
	$(CC)  -c $< -o $@


fclean:
	make fclean -C libft
	$(RM) $(OBJ) $(NAME)

re:			fclean $(OBJ) $(NAME) 
