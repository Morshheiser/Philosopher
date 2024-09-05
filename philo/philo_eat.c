/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:18:32 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 17:04:45 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"
/*
// Attempt to lock two forks (mutexes) to ensure a philosopher can eat
int lock_two_forks(pthread_mutex_t *right_fork, pthread_mutex_t *left_fork)
{
    int right_lock_result;
    int left_lock_result;

    right_lock_result = pthread_mutex_lock(right_fork);
    if (right_lock_result != 0)
	    return -1;
    left_lock_result = pthread_mutex_lock(left_fork);
    if (left_lock_result != 0)
    {
        pthread_mutex_unlock(right_fork);
	return -1;
    }
    return 0;
}*/
// Simulate a philosopher eating
int eat(t_philo *philo)
{
    int table_conclude = 0;
    int	forks[2];

    t_table *table = philo->table;

    if (!get_forks(philo, forks))
		return (table_conclude);
    pthread_mutex_lock(&table->door);
    philo->last_time_eat = get_current_time();
    if (!table->finished)
        printf("%ld %d is eating\n", get_formatted_time(table->begin_time), philo->id);
    philo->eat_count++;
    table_conclude = table->finished;
    pthread_mutex_unlock(&table->door);
    mspleep(table->time_eat);
    release_forks(forks[0], forks[1], philo);
    return (table_conclude);
}

