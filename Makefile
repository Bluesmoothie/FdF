NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	minilibx-linux/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f
SRC_FILES	=	fdf \
				user_input

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJ) $(LIBFT_A) $(GNL_A) $(MLX_A)
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lm -o $(NAME) -lXext -lX11

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(GNL_A):
				@$(MAKE) -s -C $(GNL)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(GNL)
				$(MAKE) clean -s -C $(MLX)

fclean:			clean
				$(MAKE) fclean -s -C $(LIBFT)
				$(MAKE) fclean -s -C $(GNL)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re