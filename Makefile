NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_putstr.c ft_putmem.c ft_putnbr.c ft_putunbr.c ft_puthex.c ft_puthexcap.c ft_printf.c
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

%.o: %.c Makefile
	${CC} ${CFLAGS} -c -MD $<

clean:
	rm -f ${OBJ} *.d

fclean: clean
	rm -f ${NAME} program

re: fclean all

program: ${NAME} main.c
	@${CC} ${CFLAGS} main.c ${NAME} -o program

ex: program clean
	@./program

sex: ${NAME} clean
	${CC} main.c ${NAME} -o program
	./program

t: ${NAME}
	ar -t ${NAME}

-include *.d

.PHONY: all clean fclean re
