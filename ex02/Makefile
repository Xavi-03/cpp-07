NAME = Array
SRC= ./src/main.cpp
HEADER = ./includes/Array.hpp
INCLUDE	:= -I ./includes

OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g
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
