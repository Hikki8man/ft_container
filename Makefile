NAME	=	container

SRC		=	main.cpp

INC		=	vector/vector.hpp \
			vector/vector_iterator.hpp \
			map/map.hpp \
			rb_tree.hpp \
			stack/stack.hpp \
			utils/iterator_traits.hpp \
			utils/enable_if.hpp \
			utils/equal.hpp \
			utils/is_integral.hpp \
			utils/lexicographical_compare.hpp \
			utils/pair.hpp \
			utils/reverse_iterator.hpp

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	= 	-std=c++98 -Wall -Werror -Wextra -g -fsanitize=address

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
