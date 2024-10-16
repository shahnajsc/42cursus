# Program info

NAME		= push_swap
# NAME_BONUS	=  bonus executable name is different
CC			= cc
CFLAG		= -Wall -Wextra -Werror -fsanitize=address -g
LDFLAGS		= -fsanitize=adddress
INCLUDES	= -I./includes -I./libft/includes
RM			= rm -f

# LIBFT
LIBFT		= ./libft/libft.a

# Source
MAN_DIR		= srcs/argument_process.c	srcs/error_handle.c	\
			srcs/test_stages.c	\
			operations/operations_node.c	operations/operations_utils.c	\
			operations/operations_a.c	operations/operations_b.c	\
			operations/operations_both.c	\
			sort/push_swap.c	sort/sort_utils.c	\

# Source path
MAN_SRCS	= main.c $(MAN_DIR)

# Marker files to track which version is built
# mandatory : .mandatory
# bonus : .bonus

all: mandatory

$(LIBFT):
	$(MAKE) -C ./libft

mandatory : .mandatory
.mandatory: $(LIBFT) $(MAN_SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(MAN_SRCS) $(LIBFT) -o $(NAME)
	@touch .mandatory
#	@$(RM) .bonus

# bonus : .bonus

clean:
	$(MAKE) -C ./libft clean
	$(RM) .mandatory

fclean:
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) .mandatory

re: fclean all

.PHONY: all clean fclean re bonus
