.PHONY:			all clean fclean re

CC			=	gcc
INCLUDE 	=	-I includes -I libft/includes -I minilibx-linux
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDE)

NAME		=	fdf

LIBFT		=	libft/
MLX			=	minilibx-linux/

LIBFT_A		=	$(addprefix $(LIBFT), libft_ex.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
INC 		= 	includes/fdf.h

SRC_DIR		=	src/
OBJ_DIR		=	obj/

RM			=	rm -f

SRC_FILES	=	fdf 		\
				user_input 	\
				map 		\
				mlx 		\
				image 		\
				image_utils	\
				parse 		\
				isometric	\
				curve		\
				curve_utils	\
				axonometric	\

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJ) $(LIBFT_A) $(MLX_A) $(INC)
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft_ex -L$(MLX) -lmlx -lm -o $(NAME) -lXext -lX11

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c includes/fdf.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(MLX)

fclean:			clean
				$(MAKE) fclean -s -C $(LIBFT)
				@$(RM) $(NAME)

re:				fclean all
