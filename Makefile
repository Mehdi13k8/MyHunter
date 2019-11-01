SRC	=	my_hunternorm.c	\
		src.c		\
		flags.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	my_hunter

LIB	=	-lcsfml-audio -lcsfml-graphics -lcsfml-network -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
