# Name
NAME 			= pipex

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror 
# LDFLAGS 		= -fsanitize=address  -fsanitize=address -g
INCLUDES 		= -I./includes -I./libft/includes
RM 				= rm -f

# LIBFT
LIBFT	 		= ./libft/libft.a

# Source files by directory
MAN_DIR 		= 	srcs/command_handle.c	srcs/command_path.c		srcs/command_split.c \
					srcs/command_utils.c	srcs/error_handle.c		srcs/pipex.c	\
					srcs/process_handle.c	\
					
#BON_DIR		=

# Source path

MAN_SRCS		=	main.c $(MAN_DIR)
#BON_SRCS		=	main_bonus.c $(BON_DIR)
			
# Object files by directory

MAN_OBJS = $(MAN_SRCS:.c=.o)
#BON_OBJS = $(BON_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT) $(MAN_OBJS) $(MAN_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(MAN_OBJS)

fclean:
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) $(MAN_OBJS) 

re: fclean all

.PHONY: all clean fclean re mandatory