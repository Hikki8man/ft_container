NAME	=	container

SRC		=	main.cpp

INC		=	vector.hpp \
			iterator_traits.hpp \
			vector_iterator.hpp

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	= 	-Wall -Werror -Wextra -std=c++98

CC		=	c++

all		:	$(NAME)

%.o:	%.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean $(NAME)

.phony	:	re clean fclean .c.o
