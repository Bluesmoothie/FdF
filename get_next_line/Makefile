SRCS	=	get_next_line.c \
			get_next_line_utils.c

OBJS	=	$(SRCS:%.c=%.o)

INCS	= .

CC		=	gcc

LIBC	= ar rc

LIBR	= ranlib

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libgnl.a

all:		$(NAME)

%.c:%.o
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re