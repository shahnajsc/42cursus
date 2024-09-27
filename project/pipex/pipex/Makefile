# Name
NAME 			= pipex

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -fsanitize=address -g
LDFLAGS 		= -fsanitize=address
INCLUDES 		= -I./includes -I./libft/includes
RM 				= rm -f

# LIBFT
LIBFT	 		= ./libft/libft.a

# Source files by directory
MAN_DIR 		= 	srcs/command_handle.c	srcs/command_path.c		srcs/command_split.c \
					srcs/command_utils.c	srcs/error_handle.c		srcs/pipex.c	\
					srcs/process_handle.c	\

BON_DIR			=	srcs_bonus/command_handle_bonus.c	srcs_bonus/command_path_bonus.c	\
					srcs_bonus/command_split_bonus.c	srcs_bonus/command_utils_bonus.c	\
					srcs_bonus/error_handle_bonus.c		srcs_bonus/pipex_bonus.c	\
					srcs_bonus/process_handle_bonus.c	srcs_bonus/here_doc_handle.c	\

# Source path

MAN_SRCS		=	main.c $(MAN_DIR)
BON_SRCS		=	main_bonus.c $(BON_DIR)

# Object files by directory

#MAN_OBJS = $(MAN_SRCS:.c=.o)
#BON_OBJS = $(BON_SRCS:.c=.o)

# Marker files to track which version is built
#mandatory : .mandatory
#bonus : .bonus

all: mandatory

$(LIBFT):
	$(MAKE) -C ./libft

mandatory : .mandatory
.mandatory: $(LIBFT) $(MAN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_SRCS) $(LIBFT) -o $(NAME)
	@touch .mandatory
	@$(RM) .bonus

bonus : .bonus
.bonus: $(LIBFT) $(BON_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BON_SRCS) $(LIBFT) -o $(NAME)
	@touch .bonus
	@$(RM) .mandatory

clean:
	$(MAKE) -C ./libft clean
	$(RM) .bonus .mandatory

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) .bonus .mandatory

re: fclean all

.PHONY: all clean fclean re bonus
