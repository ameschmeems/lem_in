NAME		:=	lem-in

SRCS		:=	src/main.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${SRCS}
		@make -C ./ft_printf
		${CC} ${SRCS} -Lft_printf -lftprintf -o ${NAME}

clean:
		@make -C ./ft_printf clean

fclean:		clean
		@make -C ./ft_printf fclean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re