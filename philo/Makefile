NAME = philo

CC = cc

GFLAGS = -Wall -Wextra -Werror 

SOURCES = main.c \
	boot_forks.c \
	boot_philo.c \
	routine_philo.c \
	threads_philo.c \
	eat.c \
	initialize_table.c \
	time_control.c \
	sleep.c \
	think.c \
	check_utils \
	oracle.c \
	  
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
