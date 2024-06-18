NAME = philos

CC = cc

GFLAGS = -Wall -Wextra -Werror 

SOURCES = main.c \
	initialize_table.c \
	boot_philo_forks.c \
	routine_philo.c
	  
OBJECT = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECT)
	$(CC) $(GFLAGS) -o $(NAME) $(OBJECT)

all : $(NAME)

clean :
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re : fclean all