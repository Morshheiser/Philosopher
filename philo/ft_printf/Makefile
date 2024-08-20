NAME = libftprintf.a

CC = cc

GFLAGS = -Wall -Wextra -Werror

SOURCES = ft_base.c \
	  ft_itoaprint.c \
	  ft_printf.c \
	  ft_putcharprint.c \
	  ft_putstrprint.c \
	  ft_pointer.c

OBJECT = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

all : $(NAME)

clean :
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re : fclean all
