/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:19:05 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 00:01:26 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

//Main routine for philosopher threads, handling eating, sleeping, and thinking
void	*routine_philo(void *arg)
{
	t_philo	*philo;
	int		table_conclude;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->door);
	table_conclude = philo->table->finished;
	pthread_mutex_unlock(&philo->table->door);
	if (philo->id % 2 == 0)
		usleep (1000);
	while (1)
	{
		if (table_conclude)
			break ;
		if (think(philo))
			break ;
		if (eat(philo))
			break ;
		if (philo_sleep(philo))
			break ;
	}
	return (NULL);
}
