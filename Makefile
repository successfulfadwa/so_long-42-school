SRC			= 	so_long.c main.c

OBJ			=	${SRC:.c=.o}


CC			=	gcc

CFLAGS 		=	-Wall -Werror -Wextra

RM 			=	rm -f

LIBS		=	so_long.h

NAME		=	solong

MINILIBX	=	-I  /usr/local/include -g -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all:	$(NAME)
# $(SERVER)	: $(LIBS) $(OBJS_S)
# 	$(CC) $(CFLAGS)  $(OBJS_S)  -o $(SERVER)

$(NAME):	$(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ)  ${MINILIBX}  -o $(NAME)


clean:
	$(RM) $(OBJ)
