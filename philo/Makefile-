NAME = philo

CC = cc

GFLAGS = -Wall -Wextra -Werror -g

SOURCES = main.c \
	initialize_forks.c \
	initialize_philo.c \
	philo_routine.c \
	philo_eat.c \
	setup_table.c \
	time_management.c \
	philo_sleep.c \
	philo_think.c \
	validation_utils.c \
	monitor_oracle.c \
	  
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
