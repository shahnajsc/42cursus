# Program info

# bonus executable name is different
NAME		= push_swap
BONUS 		= checker

# NAME_BONUS	=  bonus executable name is different
CC			= cc
CFLAG		= -Wall -Wextra -Werror
#LDFLAGS		= -fsanitize=adddress -fsanitize=address -g
INCLUDES	= -I./includes -I./libft/includes
RM			= rm -f

# LIBFT
LIBFT		= ./libft/libft.a

# Source
MAN_DIR		= srcs/argument_process.c	srcs/error_handle.c	\
			operations/operations_node.c	operations/operations_utils.c	\
			operations/operations_a.c	operations/operations_b.c	\
			operations/operations_both.c	\
			sort/push_swap.c	sort/sort_utils.c	sort/push_to_b.c\
			sort/push_cost.c	sort/push_opration.c	sort/push_back_to_a.c	\
			sort/sort_utils_2.c	\

BON_DIR			= srcs_bonus/argument_process_bonus.c	srcs_bonus/error_handle_bonus.c	\
				srcs_bonus/operation_a_bonus.c	srcs_bonus/operation_b_bonus.c	\
				srcs_bonus/operation_both_bonus.c	srcs_bonus/operation_node_bonus.c	\
				srcs_bonus/operation_utils_bonus.c	srcs_bonus/reader.c	\
				srcs_bonus/checker.c	srcs_bonus/common_utils.c	\

# Source path
MAN_SRCS	= main.c $(MAN_DIR)
BON_SRCS	= main_bonus.c $(BON_DIR)

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
	@$(RM) .bonus

bonus : .bonus
.bonus: $(LIBFT) $(BON_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BON_SRCS) $(LIBFT) -o $(BONUS)
	@touch .bonus
	@$(RM) .mandatory

clean:
	$(MAKE) -C ./libft clean
	$(RM) .bonus .mandatory

fclean:
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) .bonus .mandatory

re: fclean all

.PHONY: all clean fclean re bonus
