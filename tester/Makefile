STACK_STD	=	std_stack

STACK_FT	=	ft_stack

STACK_SRC =	./testerMains/stack_tester.cpp

STACK_OBJ =	$(STACK_SRC:.cpp=.o)

VEC_STD	=	std_vector

VEC_FT	=	ft_vector

VEC_SRC =	./testerMains/vector_tester.cpp

VEC_OBJ =	$(VEC_SRC:.cpp=.o)

CHECKER = checker

CHECKER_SRC = ./utils/checker.cpp

CHECKER_OBJ = $(CHECKER_SRC:.cpp=.o)

TESTOUT = ./testOutput/

TESTPATH = testerMains/

CFLAGS	=   #-Wall -Werror -Wextra

CC		=	c++

all		:	std ft checker
			mkdir -p diff
			mkdir -p testOutput

# %.o:	%.cpp
# 	$(CC) $(CFLAGS) -c $< -o $@

checker: 

std : $(STACK_OBJ) $(VEC_OBJ)
	$(CC) $(CFLAGS) -D STD -c $(STACK_SRC) -o $(STACK_OBJ)
	$(CC) $(CFLAGS) -o $(STACK_STD) $(STACK_OBJ)

	$(CC) $(CFLAGS) -D STD -c $(VEC_SRC) -o $(VEC_OBJ)
	$(CC) $(CFLAGS) -o $(VEC_STD) $(VEC_OBJ)

ft : $(STACK_OBJ) $(VEC_OBJ)
	$(CC) $(CFLAGS) -D FT -c $(STACK_SRC) -o $(STACK_OBJ)
	$(CC) $(CFLAGS) -o $(STACK_FT) $(STACK_OBJ)

	$(CC) $(CFLAGS) -D FT -c $(VEC_SRC) -o $(VEC_OBJ)
	$(CC) $(CFLAGS) -o $(VEC_FT) $(VEC_OBJ)

checker : $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -c $(CHECKER_SRC) -o $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJ)

clean	:
	rm -f $(VEC_OBJ) $(STACK_OBJ) $(CHECKER_OBJ)

fclean	:	clean
	rm -f $(STACK_STD) $(STACK_FT) $(CHECKER) $(VEC_STD) $(VEC_FT)
	rm -rf diff
	rm -rf testOutput

re		:	fclean all

.phony	:	re clean fclean .c.o checker std ft
