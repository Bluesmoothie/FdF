NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	minilibx-linux/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f
SRCS		=	

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lm -o $(NAME)

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(GNL_A):
				@$(MAKE) -s -C $(GNL)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
				@$(RM) $(OBJS)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(GNL)
				$(MAKE) clean -s -C $(MLX)

fclean:			clean
				$(MAKE) fclean -s -C $(LIBFT)
				$(MAKE) fclean -s -C $(GNL)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re