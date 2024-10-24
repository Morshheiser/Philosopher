/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:50:20 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 00:09:10 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Check if the philosopher has met the required eating count
int	check_must_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->door);
	if ((philo->eat_count <= philo->table->must_eat))
	{
		pthread_mutex_unlock(&philo->table->door);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->door);
	return (1);
}

// Check if all philosophers are sated according to the must-eat requirement
int	check_all_sated(t_table *table)
{
	int	i;
	int	all_sated;

	i = -1;
	all_sated = 0;
	while (++i < table->num_philos)
	{
		pthread_mutex_lock(&table->door);
		if (table->philos[i].eat_count > table->must_eat)
		{
			if (++all_sated >= table->num_philos)
			{
				table->finished = 1;
				pthread_mutex_unlock(&table->door);
				return (1);
			}
		}
		pthread_mutex_unlock(&table->door);
	}
	return (0);
}

// Check if all philosophers have eaten enough and finalize the table if so
int	check_all_philo_finalize(t_table *table)
{
	if (table->must_eat > 0 && check_all_sated(table))
	{
		pthread_mutex_lock(&table->door);
		table->finished = 1;
		return (1);
	}
	return (0);
}
