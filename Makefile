SRC		= 	so_long.c

OBJ	=	${SRC:.c=.o}


CC		=	cc

CFLAGS 	= 	-Wall -Werror -Wextra

RM 		=	rm -f

LIBS	=	solong.h


NAME	=	solong

MINILIBX = -I  /usr/local/include -g -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all:	$(NAME)
# $(SERVER)	: $(LIBS) $(OBJS_S)
# 	$(CC) $(CFLAGS)  $(OBJS_S)  -o $(SERVER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ${MINILIBX}  -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)
