##
## EPITECH PROJECT, 2020
## B-OOP-400
## File description:
## Makefile
##

MAIN	=	./src/main.cpp

SRC		=	./src/IOperand/Types/bigdecimal.cpp	\
			./src/IOperand/Types/double.cpp	\
			./src/IOperand/Types/float.cpp	\
			./src/IOperand/Types/int8.cpp	\
			./src/IOperand/Types/int16.cpp	\
			./src/IOperand/Types/int32.cpp	\
			\
			./src/instructions/commands.cpp	\
			\
			./src/factory/factory.cpp\
			\
			./src/abstractVM.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

CPPFLAGS	=	-Werror -Wall -Wextra -I ./include -I ./include/OperandTypes

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
