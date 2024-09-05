/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:50:20 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:46 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"
// Check if the philosopher has met the required eating count
int check_must_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->door);
	if((philo->table->must_eat < 1) 
	|| (philo->eat_count <= philo->table->must_eat))
	{
		pthread_mutex_unlock(&philo->table->door);
		return (1);
	}
	pthread_mutex_lock(&philo->table->door);
	return(0);	
}
// Check if all philosophers are sated according to the must-eat requirement
int check_all_sated(t_table *table)
{
	int	i;
	int	all_sated;

	i = 0;
	all_sated = 1;
	pthread_mutex_lock(&table->door);
	while(i < table->num_philos)
	{
		if(table->philos[i].eat_count < table->must_eat)
		{
			all_sated = 0;
			break;
		}
		i++;
	}
	pthread_mutex_unlock(&table->door);
	return(all_sated);
}
// Check if all philosophers have eaten enough and finalize the table if so
int check_all_philo_finalize(t_table *table)
{
		
	if(table->must_eat > 0 && check_all_sated(table))
	{
		pthread_mutex_lock(&table->door);
		table->finished = 1;
		pthread_mutex_unlock(&table->door);
	}

	return(table->finished);
}
