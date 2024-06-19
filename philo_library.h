/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_library.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:45 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 18:18:27 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIBRARY_H
# define PHILO_LIBRARY_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo t_philo;

typedef struct s_table
{
    int num_fork;
    int num_philosofos;
    int time_eat;
    int time_sleep;
    int time_die;
    int time_think;
    int must_eat;
    pthread_mutex_t *forks_mutex;
    t_philo *philo;
} t_table;

typedef struct s_philo 
{
    int is_alive;
    int id;
    t_table *table;
    pthread_t thread;
} t_philo;

void boot_philosofos(int i, t_philo *philo, t_table *table);
int memory_forks_mutex(t_table *table);
int start_forks_mutex(t_table *table);
void create_philos (t_table *table);
void *routine_philo(void *table);
void eat(t_table *table);
void philo_sleep(int philo_id, int time_sleep);
void think(int philo_id, int time_think);
void must_eat(t_table *table);
void wait_join_philo(t_table *table);
void start_philo(t_table *table);


#endif