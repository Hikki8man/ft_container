NAME	=	container

SRC		=	main.cpp

INC		=	vector.hpp \
			iterator_traits.hpp \
			random_access_iterator.hpp \
			reverse_iterator.hpp \
			stack.hpp

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	= 	-std=c++98 #-Wall -Werror -Wextra

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
