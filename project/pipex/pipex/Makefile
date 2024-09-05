# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
INCLUDES 		= -I./includes -I./libft
RM 				= rm -f

# Directories
MAN_DIR 		= ./srcs
MYLIB_DIR	 	= ./libft

# Source files by directory
MAN_FILES 		= 	command_handle.c 									\
					pipex.c			process_handle.c			\
					

MAN_SRCS		= 	main.c $(addprefix $(MAN_DIR)/, $(MAN_FILES))

				
# Library
MYLIB 			= $(MYLIB_DIR)/libft.a

# Executables
NAME 			= pipex

# Targets
all : mandatory

mandatory : .mandatory
.mandatory: $(MYLIB) $(MAN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_SRCS) $(MYLIB) -o $(NAME)
	@touch .mandatory

$(MYLIB):
	$(MAKE) -C $(MYLIB_DIR)

clean:
	$(MAKE) clean -C $(MYLIB_DIR)
	$(RM) .mandatory


fclean: clean
	$(MAKE) fclean -C $(MYLIB_DIR)
	$(RM) $(NAME) .mandatory
	
re: fclean all

.PHONY: all clean fclean re mandatory