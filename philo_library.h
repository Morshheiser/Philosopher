/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_library.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:45 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/07 18:47:31 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIBRARY_H
# define PHILO_LIBRARY_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo t_philo;

typedef struct s_table
{
    int num_fork;
    int num_philosofos;
    int time_eat;
    int time_sleep;
    int time_die;
    int must_eat;
    pthread_mutex_t *forks_mutex;
    t_philo *philo;
} t_table;

typedef struct s_philo 
{
    int is_alive;
    int id;
    int must_eat;
    t_table *table;
    pthread_t thread;
    pthread_mutex_t *fork_esquerdo;
    pthread_mutex_t *fork_direito;
} t_philo;

t_philo *boot_philosofos(t_philo *philo, t_table *table, int id);
t_philo *memory_philofos(int num);
int    memory_forks_mutex(t_table *table);
int boot_forks_mutex(t_table *table);
void create_philos (t_table *table);
void *routine_philo(void *arg);
void *eat(void *arg);


#endif