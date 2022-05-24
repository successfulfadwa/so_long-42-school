SRC			= 	main.c

OBJ			=	${SRC:.c=.o}


CC			=	cc

CFLAGS 		=	-Wall -Werror -Wextra -g

RM 			=	rm -f

LIBS		=	so_long.h

NAME		=	solong

MINILIBX	=	-I  /usr/local/include -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all:	$(NAME)
# $(SERVER)	: $(LIBS) $(OBJS_S)
# 	$(CC) $(CFLAGS)  $(OBJS_S)  -o $(SERVER)

$(NAME):	$(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) -g ${MINILIBX}  -o $(NAME)

%.o: %.c $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	$(RM) $(OBJ) $(NAME)

re:			fclean $(OBJ) $(NAME) 
