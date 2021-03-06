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
			./src/stack/checkZero.cpp	\
			./src/registers.cpp	\
			\
			./src/abstractVM.cpp	\
			\
			./src/exception/exception.cpp

TEST	=	./tests/test_abstractVM.cpp	\
			./tests/test_madd.cpp	\
			./tests/test_msub.cpp	\
			./tests/test_mmul.cpp	\
			./tests/test_mdiv.cpp	\
			./tests/test_mmod.cpp	\
			./tests/test_mpush.cpp	\
			./tests/test_mpop.cpp	\
			./tests/test_mswap.cpp	\
			./tests/test_mdup.cpp	\
			./tests/test_massert.cpp	\
			./tests/test_mload.cpp	\
			./tests/test_mclear.cpp	\
			./tests/test_mstore.cpp	\
			./tests/test_checkcode.cpp	\
			./tests/test_overflow.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

CPPFLAGS	=	-Werror -Wall -Wextra -g -I ./include -I ./include/OperandTypes

all:	$(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(MAIN)

tests_run:
	g++ -o test $(CPPFLAGS) $(TEST) $(SRC) --coverage -lcriterion
	./test
	gcovr --exclude tests/
	rm test

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	rm -f test

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus tests_run
