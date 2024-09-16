# Source files
SRCS	=	./ft_printf.c \
			./ft_print_utils.c \
			./ft_print_str.c \
			./ft_print_ptr.c \
			./ft_print_nbr.c \
			./ft_print_unsign.c \
			./ft_print_hex.c \

# Object files
OBJS	=	${SRCS:.c=.o}

# Header file
HEAD	=	.

# Library name
NAME	=	libftprintf.a

# Default target
all	:	${NAME}

# Rule to compile source files into object files
%.o: %.c
	cc -Wall -Wextra -Werror -c -I ${HEAD} $< -o $@

# Target to create the library
${NAME}	:	${OBJS}
	ar rcs $@ $^

# Target to clean object files
clean	:
	rm -f ${OBJS}

# Target to clean library and object files
fclean	: clean
	rm -f ${NAME}

# Target to rebuild (clean and build again)
re	: fclean all

# Ensure that 'clean', 'fclean', and 're' are not dependent on actual file names
.PHONY: all clean fclean re bonus