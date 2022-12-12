NAME		:=	libftprintf.a

SRCS		:=	srcs/ft_printf.c \
				srcs/print_str.c \
				srcs/print_digit.c \
				srcs/print_unsdigit.c \
				srcs/print_lhex.c \
				srcs/print_uphex.c \
				srcs/print_ptr.c \
				srcs/print_char.c

OBJS		:=	${SRCS:.c=.o}

CC			:=	gcc

CFLAGS		:= -Wall -Wextra -Werror -c

INCLUDES	:=	./includes

all:		${NAME}

${NAME}:	${OBJS}
		@make -C ./libft
		cp libft/libft.a ${NAME}
		ar rc $@ $^

clean:
		@make clean -C ./libft
		rm -f ${OBJS}

fclean:		clean
		@make fclean -C ./libft
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re