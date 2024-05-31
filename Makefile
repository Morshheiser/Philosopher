NAME = philos.a

CC = cc

GFLAGS = -Wall -Wextra -Werror

SOURCES = main.c \
	  initialize_table.c \
	  ft_printf.c \
	  boot_philo_forks.c \
	  .c \
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