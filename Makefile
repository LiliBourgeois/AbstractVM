##
## EPITECH PROJECT, 2020
## B-OOP-400
## File description:
## Makefile
##

MAIN	=	./src/main.cpp

SRC		=	./src/IOperand/checkOverflowUnderflow.cpp	\
			./src/IOperand/types/bigdecimal.cpp	\
			./src/IOperand/types/double.cpp	\
			./src/IOperand/types/float.cpp	\
			./src/IOperand/types/int8.cpp	\
			./src/IOperand/types/int16.cpp	\
			./src/IOperand/types/int32.cpp	\
			\
			./src/instructionlist/checkInstructions.cpp	\
			./src/instructionlist/instructionList.cpp	\
			\
			./src/factory/factory.cpp\
			\
			./src/stack/stack.cpp	\
			\
			./src/abstractVM.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

CPPFLAGS	=	-Werror -Wall -Wextra -g -I ./include -I ./include/OperandTypes

all:	$(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(MAIN)

tests_run:
	g++ -o test $(CFLAGS) $(TEST) $(SRC) --coverage -lcriterion
	./test
	gcovr --exclude tests/
	rm test

clean:
	rm -f $(OBJ)
	touch test.gcno
	rm *.gc*

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus tests_run
