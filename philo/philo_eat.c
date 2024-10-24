/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:18:32 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/23 23:57:41 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Simulate a philosopher eating
int	eat(t_philo *philo)
{
	t_table		*table;
	int			table_conclude;
	int			forks[2];
	int			position_forks;

	table = philo->table;
	table_conclude = 0;
	position_forks = get_forks(philo, forks);
	if (position_forks == 0)
		return (table_conclude);
	pthread_mutex_lock(&table->door);
	philo->last_time_eat = get_current_time();
	if (!philo->table->finished)
	{
		printf("%ld %d is eating\n",
			get_formatted_time(table->begin_time), philo->id + 1);
	}
	philo->eat_count++;
	table_conclude = table->finished;
	pthread_mutex_unlock(&table->door);
	mspleep(table->time_to_eat);
	release_forks(forks, philo, position_forks);
	return (table_conclude);
}
