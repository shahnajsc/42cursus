# Program info

NAME		= so_long

CC			= cc
CFLAG		= -Wall -Wextra -Werror
MLX42_FLAGS	= -ldl -lglfw -pthread -lm
#LDFLAGS		= -fsanitize=adddress -fsanitize=address -g
INCLUDES	= -I./includes -I./libft/includes -I./mlx42/includes
RM			= rm -f

# LIBFT
LIBFT		= ./libft/libft.a

# MLX
MLX42_DIR	= ./mlx42
MLX42		= $(MLX42_DIR)/build/libmlx42.a

# Source directory
MAN_DIR		= srcs/map_read.c	srcs/error_handle.c	\
			srcs/utils.c	\
			tester.c	\

# Source path
MAN_SRCS	= main.c $(MAN_DIR)

# Marker files to track which version is built
# mandatory : .mandatory

all: mandatory

$(LIBFT):
	$(MAKE) -C ./libft

mandatory : .mandatory
.mandatory: $(LIBFT) $(MAN_SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(MAN_SRCS) $(LIBFT) -o $(NAME)
	@touch .mandatory

clean:
	$(MAKE) -C ./libft clean
	$(RM)  .mandatory

fclean:
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) .mandatory

re: fclean all

.PHONY: all clean fclean re
