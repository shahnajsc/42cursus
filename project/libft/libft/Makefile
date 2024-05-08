# Source files
SRCS	=	./ft_isalpha.c		./ft_isdigit.c		./ft_isalnum.c		./ft_isascii.c	\
			./ft_isprint.c		./ft_strlen.c		./ft_memset.c		./ft_bzero.c	\
			./ft_memcpy.c 		./ft_memmove.c		./ft_strlcpy.c		./ft_strlcat.c	\
			./ft_toupper.c		./ft_tolower.c		./ft_strchr.c		./ft_strrchr.c 	\
			./ft_strncmp.c		./ft_memchr.c		./ft_memcmp.c		./ft_strnstr.c	\
			./ft_atoi.c			./ft_calloc.c		./ft_strdup.c		./ft_strjoin.c	\
			./ft_substr.c		./ft_strtrim.c		./ft_split.c		./ft_itoa.c		\
			./ft_strmapi.c		./ft_striteri.c		./ft_putchar_fd.c	./ft_putstr_fd.c	\
			./ft_putendl_fd.c	./ft_putnbr_fd.c	\

SRCS_BN	=	./ft_lstnew.c		./ft_lstadd_front.c	./ft_lstsize.c		./ft_lstlast.c	\


# Object files
OBJS	=	${SRCS:.c=.o}
OBJS_BN	=	${SRCS_BN:.c=.o}

# Header file
HEAD	=	./libft.h

# Library name
NAME	=	libft.a

# Default target
all	:	${NAME}

# Rule to compile source files into object files
%.o: %.c
	cc -Wall -Wextra -Werror -c -I ${HEAD} $< -o $@

# Target to create the library
${NAME}	:	${OBJS}
	ar rcs $@ $^

# Target to create the library with bonus
bonus: .bonus
.bonus: ${NAME} ${OBJS_BN}
	ar rcs ${NAME} ${OBJS_BN}
	@touch .bonus

# Target to clean object files
clean	:
	rm -f ${OBJS} ${OBJS_BN} .bonus

# Target to clean library and object files
fclean	: clean
	rm -f ${NAME}

# Target to rebuild (clean and build again)
re	: fclean all

# Ensure that 'clean', 'fclean', and 're' are not dependent on actual file names
.PHONY: all clean fclean re bonus