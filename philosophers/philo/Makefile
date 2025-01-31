# Name
NAME 			= philo

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
#LDFLAGS 		= -fsanitize=address -fsanitize=address -g
INCLUDES 		= -I./includes
RM 				= rm -f

# Source files by directory
MAN_DIR 		= srcs/data_init.c	srcs/error_handle.c	\
				  srcs/simulation.c	srcs/simulation_monitor.c\
				  srcs/routine_utils.c	srcs/print_msg.c	\
				  srcs/utils.c	\

# Source path

MAN_SRCS		=	main.c $(MAN_DIR)

# Marker files (object) to track which version is built
#mandatory : .mandatory

all: mandatory

mandatory : .mandatory
.mandatory: $(MAN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_SRCS) -o $(NAME)
	@touch .mandatory

clean:
	$(RM) .mandatory

fclean: clean
	$(RM) $(NAME) .mandatory

re: fclean all

.PHONY: all clean fclean re
