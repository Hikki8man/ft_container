STACK	=	stack

STACK_SRC =	stack_tester.cpp

STACK_OBJ =	$(STACK_SRC:.cpp=.o)

VEC	=	vector

VEC_SRC =	vector_tester.cpp

VEC_OBJ =	$(VEC_SRC:.cpp=.o)

CFLAGS	=  -Wall -Werror -Wextra

CC		=	c++

all		:	$(STACK) $(VEC)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(STACK) : $(STACK_OBJ)
	$(CC) $(CFLAGS) -o $(STACK) $(STACK_OBJ)

$(VEC) : $(VEC_OBJ)
	$(CC) $(CFLAGS) -o $(VEC) $(VEC_OBJ)

clean	:
	rm -f $(VEC_OBJ) $(STACK_OBJ)
	rm -f leaks_vector.txt leaks_stack.txt

fclean	:	clean
	rm -f $(STACK) $(VEC)

re		:	fclean $(STACK) $(VEC)

.phony	:	re clean fclean .c.o
