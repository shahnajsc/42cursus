CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rc

TARGET =	ft_printf.o ft_printf_tool.o ft_putchar.o ft_putstr.o ft_putpoint.o \
			ft_putnbr.o ft_putnum_unsign.o ft_puthex.o


NAME = libftprintf.a

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(TARGET)
	$(AR) $(NAME) $^

clean:
	$(RM) $(TARGET) $(BONUS_TARGET)

fclean: clean
	$(RM) $(NAME) $(BONUS_TARGET)

re: fclean all