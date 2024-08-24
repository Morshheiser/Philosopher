/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_library.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:43:21 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 14:57:45 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIBRARY_H
# define PHILO_LIBRARY_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t			begin_time;
	int				num_philos;
	int				must_eat;
	int				finished;
	int				time_eat;
	int				finished_eat;
	int				time_sleep;
	int				time_die;
	int				time_think;
	t_philo			*philos;
	pthread_t		oracle;
	pthread_mutex_t	door;
	pthread_mutex_t	*forks;

}	t_table;

typedef struct s_philo
{
	int			is_alive;
	int			id;
	int			eat_count;
	time_t		last_time_eat;
	t_table		*table;
	pthread_t	thread;	
}	t_philo;

//Mutex operations
int	memory_forks_mutex(t_table *table);
int	start_forks_mutex(t_table *table);

//Philosopher and oracle functions
void	create_philos(t_table *table);
void	boot_philosofos(int i, t_philo *philo, t_table *table);
int		start_philo(t_table *table);
void	*routine_philo(void *);
void    *oracle_day(void *arg);
void    create_oracle(t_table *table);

//Thread Management
int	create_and_join_philo(t_table *table);

//Time functions

time_t get_current_time(void);
time_t get_formatted_time(time_t start_time);
void    mspleep(time_t time_sleep);

//Utility Functions

int     ft_isdigit(char *str);
int	value_parameter(char **argv, int argc);
void cleanup(t_table *table);
int     initialize_table(t_table *table);

//Actions

int lock_two_forks(pthread_mutex_t *right_fork, pthread_mutex_t *left_fork);
int eat(t_philo *philo);
int think(t_philo *philo);
int philo_sleep(t_philo *philo);

//Checks

int check_must_eat(t_philo *philo);
int check_all_sated(t_table *table);
int check_all_philo_finalize(t_table *table);
#endif
