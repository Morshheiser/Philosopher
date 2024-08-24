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
//Main routine for philosopher threads, handling eating, sleeping, and thinking
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
	printf("Philosopher %d started his routine\n", philo->id);
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
	printf("Philosopher %d finished his routine\n", philo->id);
	return(NULL);
}

