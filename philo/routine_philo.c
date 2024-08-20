/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:19:05 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 15:56:37 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

int check_must_eat(t_philo *philo)
{
    t_table *table = philo->table;
    if (philo->eat_count >= table->must_eat)
        return 1;
    return 0;
}


void *routine_philo(void *arg)
{
	t_philo	*philo;
	int	table_conclude;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->door);
	table_conclude = philo->table->finished;
	pthread_mutex_unlock(&philo->table->door);
	if(table_conclude)
		return(NULL);
	printf("Filosofo %d iniciou sua rotina\n", philo->id);
	if(philo->id % 2 == 0)
		mspleep(1000);
	while(1)
	{
		pthread_mutex_lock(&philo->table->door);
		table_conclude = philo->table->finished;
		pthread_mutex_unlock(&philo->table->door);
		if(table_conclude)
			break;
		if(eat(philo) && check_must_eat(philo))
			break;
		if(philo_sleep(philo))
			break;
		if(think(philo))
			break;
	}
	printf("Filósofo %d terminou sua rotina\n", philo->id);
	return(NULL);
}

