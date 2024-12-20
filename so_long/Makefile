# Program info

NAME		= so_long

CC			= cc
CFLAG		= -Wall -Wextra -Werror
MLX42_FLAGS	= -ldl -lglfw -pthread -lm
#MLX42_FLAGS	= -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
#LDFLAGS		= -fsanitize=adddress -fsanitize=address -g
INCLUDES	= -I./includes -I./libft/includes -I./MLX42/include/MLX42
RM			= rm -f

# LIBFT
LIBFT		= ./libft/libft.a

# MLX
MLX42_DIR	= ./MLX42
MLX42		= $(MLX42_DIR)/build/libmlx42.a

# Source directory
MAN_DIR		= srcs/map_read.c	srcs/error_handle.c	\
			srcs/map_utils.c	srcs/game_start.c	\
			srcs/game_render.c	srcs/game_handle.c	\

# Source path
MAN_SRCS	= main.c $(MAN_DIR)

# Marker files to track which version is built
# mandatory : .mandatory

all: mandatory

$(LIBFT):
	$(MAKE) -C ./libft

$(MLX42):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	@$(MAKE) -C MLX42/build -j4

mandatory : .mandatory
.mandatory: $(LIBFT) $(MLX42) $(MAN_SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(MAN_SRCS) $(LIBFT) $(MLX42) $(MLX42_FLAGS) -o $(NAME)
	@touch .mandatory

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./MLX42/build clean
	$(RM)  .mandatory

fclean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./MLX42/build clean
	$(RM) $(NAME) .mandatory

re: fclean all

.PHONY: all clean fclean re
