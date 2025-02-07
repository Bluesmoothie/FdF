.PHONY			:	all clean fclean re norme FORCE

NAME			=	fdf

#			GCC

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP $(INCLUDE)

#			COMMON

BUILD_DIR		=	.build/
SRC_DIR			=	src/
INCLUDE 		=	-I include/ -I $(LIBFT)include -I $(MLX)

#			LIBS

LIBFT			=	libft/
MLX				=	mlx/
LIBFT_A			=	$(addprefix $(LIBFT), libft_ex.a)
MLX_A			=	$(addprefix $(MLX), libmlx.a)

#			SRC

SRC_FILES		=	fdf 				\
					axonometric			\
					bresenham			\
					curves				\
					curves_utils		\
					curves_utils_2		\
					free				\
					image 				\
					image_utils			\
					isometric			\
					map 				\
					map_utils 			\
					menu 				\
					menu_utils 			\
					mlx 				\
					parse 				\
					user_input 			\
					user_input_utils	\

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 			= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			RULES

all				:	$(NAME)

$(NAME)			:	$(BUILD_DIR) $(OBJ) $(LIBFT_A) $(MLX_A)
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft_ex -L$(MLX) -lmlx -lm -o $(NAME) -lXext -lX11

$(LIBFT_A)		:	FORCE
				@$(MAKE) -s -C $(LIBFT)

$(MLX_A)		: FORCE
				@$(MAKE) -s -C $(MLX)

FORCE:

$(BUILD_DIR)		:
				mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o	: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean			:
				rm -rf $(BUILD_DIR)
				$(MAKE) clean -s -C $(LIBFT)
				$(MAKE) clean -s -C $(MLX)

fclean			:	clean
				$(MAKE) fclean -s -C $(LIBFT)
				rm $(NAME)

re				:	fclean all

norme			:
				norminette $(SRC_DIR) include/