SRCS	= ft_printf.c sources/ft_cho.c sources/ft_cho2.c sources/ft_useprintf.c\

CFLAGS	= -Wall -Werror -Wextra 

CC		= gcc 
RM		= rm -f

OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean
