# Program info

NAME		= push_swap
# NAME_BONUS	=  bonus executable name is different
CC			= cc
CFLAG		= -Wall -Wextra -Werror
#LDFLAGS		= -fsanitize=adddress  -fsanitize=address -g
INCLUDES	= -I./includes -I./libft/includes
RM			= rm -f

# LIBFT
LIBFT		= ./libft/libft.a

# Source
MAN_DIR		= srcs/operations_a.c 	srcs/operations_b.c	\
			srcs/operations_both.c	srcs/error_handle.c	\
			srcs/argument_process.c	srcs/test_stages.c	\
			srcs/node_operations.c	\

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

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) .mandatory

re: fclean all

.PHONY: all clean fclean re bonus
