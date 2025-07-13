NAME = Start_with_a_few_functions
SRC= ./src/main.cpp
HEADER = ./includes/whatever.hpp
INCLUDE	:= -I ./includes

OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
DEP = ${OBJ:.o=.d}

all: ${NAME}

%.o: %.cpp ${HEADER} Makefile
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDE}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${INCLUDE} -o ${NAME}

-include ${DEP}

clean:
	rm -f ${OBJ} ${DEP}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
