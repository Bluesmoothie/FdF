NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	minilibx-linux/
PRINTF		=	ft_printf/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)
PRINTF_A	=	$(addprefix $(PRINTF), libftprintf.a)

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
INC 		= 	$(addprefix $(INCLUDE)/, $(addsuffix .h, $(INCLUDE_FILES)))
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f
INCLUDE_FILES = fdf \
				ft_printf \
				get_next_line \
				libft \
				mlx
SRC_FILES	=	fdf \
				user_input \
				map \
				mlx \
				image

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJ) $(LIBFT_A) $(GNL_A) $(MLX_A) $(PRINTF_A) $(INC)
				$(CC) $(CFLAGS) $(OBJ) -L$(PRINTF) -lftprintf -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lm -o $(NAME) -lXext -lX11

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(GNL_A):
				@$(MAKE) -s -C $(GNL)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

$(PRINTF_A):
				@$(MAKE) -s -C $(PRINTF)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(GNL)
				$(MAKE) clean -s -C $(MLX)
				$(MAKE) clean -s -C $(PRINTF)

fclean:			clean
				$(MAKE) fclean -s -C $(LIBFT)
				$(MAKE) fclean -s -C $(GNL)
				$(MAKE) fclean -s -C $(PRINTF)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re