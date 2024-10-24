/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_library.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:43:21 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 07:36:40 by emorshhe         ###   ########.fr       */
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
	time_t				begin_time;
	int					num_philos;
	int					must_eat;
	int					finished;
	int					time_to_eat;
	int					finished_eat;
	int					time_to_sleep;
	int					time_to_die;
	t_philo				*philos;
	pthread_t			oracle;
	pthread_mutex_t		door;
	pthread_mutex_t		*forks;

}						t_table;

typedef struct s_philo
{
	int					id;
	int					eat_count;
	time_t				last_time_eat;
	t_table				*table;
	pthread_t			thread;
}						t_philo;

// Mutex operations
int						memory_forks_mutex(t_table *table);
int						start_forks_mutex(t_table *table);

// Philosopher and oracle functions

void					*routine_philo(void *arg);
void					*oracle_day(void *arg);
void					error_initialize_table(t_table *table);
int						create_oracle(t_table *table);
int						create_philos_forks(t_table *table);
int						boot_philosofos(int i, t_philo *philo, t_table *table);
int						start_philo(t_table *table);
int						release_forks(int *forks, t_philo *philo,
							int position_forks);
int						get_forks(t_philo *philo, int *forks_pointer);

// Time functions

time_t					get_current_time(void);
time_t					get_formatted_time(time_t start_time);
void					mspleep(time_t time_sleep);

// Utility Functions

void					cleanup(t_table *table);
int						ft_isdigit(char *str);
int						value_parameter(char **argv, int argc, t_table *table);
int						initialize_table(t_table *table);

// Actions

int						eat(t_philo *philo);
int						think(t_philo *philo);
int						philo_sleep(t_philo *philo);

// validation_utils

int						check_must_eat(t_philo *philo);
int						check_all_sated(t_table *table);
int						check_all_philo_finalize(t_table *table);
#endif
