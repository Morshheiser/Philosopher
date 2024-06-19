/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:13 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 18:11:10 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo_library.h"

void eat(t_table *table)
{
    int right_fork;
    int left_fork;
    
    right_fork = table->philo->id;
    left_fork = (table->philo->id + 1) % table->num_philosofos;
    printf("zz\n");
    pthread_mutex_lock(&(table->forks_mutex[right_fork]));
    pthread_mutex_lock(&(table->forks_mutex[left_fork]));
    printf("Filósofo %d está comendo\n", table->philo->id);
    printf("zz\n");
    usleep(table->time_eat);
    pthread_mutex_unlock(&(table->forks_mutex[right_fork]));
    pthread_mutex_unlock(&(table->forks_mutex[left_fork]));
    printf("Filósofo %d terminou de comer\n", table->philo->id);
}
