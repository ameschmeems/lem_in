NAME		:=	lem-in

SRCS		:=	src/main.c

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${SRCS}
		@make -C ./ft_printf
		${CC} ${OBJS} -Lft_printf -lftprintf -o ${NAME}

clean:
		@make -C ./ft_printf clean
		rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
		@make -C ./ft_printf fclean
		rm -f ${NAME} ${BONUS_NAME}

re:			fclean all

.PHONY:		all clean fclean re