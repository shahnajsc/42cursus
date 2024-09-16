# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror  
# LDFLAGS 		= -fsanitize=address -fsanitize=address -g
INCLUDES 		= -I./includes -I./libft/includes
RM 				= rm -f

# Directories
MAN_DIR 		= ./srcs
LIBFT_DIR	 	= ./libft

# Source files by directory
MAN_FILES 		= 	command_handle.c	command_path.c	command_split.c \
					command_utils.c		error_handle.c	pipex.c			\
					process_handle.c	\
					
# //ONUS_FILES 	= 	execute_pipex_bonus.c 		read_here_doc_bonus.c 	\
			

MAN_SRCS		= 	main.c $(addprefix $(MAN_DIR)/, $(MAN_FILES))

#// BONUS_SRCS		=	main_bonus.c $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
					
# Library
LIBFT 			= $(LIBFT_DIR)/libft.a

# Executables
NAME 			= pipex

# Targets
all : mandatory

mandatory : .mandatory
.mandatory: $(LIBFT) $(MAN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_SRCS) $(LIBFT) -o $(NAME)
	@touch .mandatory

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) .mandatory


fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) .mandatory
	
re: fclean all

.PHONY: all clean fclean re mandatory