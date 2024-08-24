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
	if(philo->table->must_eat <= 0)
	{
		pthread_mutex_unlock(&philo->table->door);
		return (1);
	}
	if(philo->eat_count <= &philo->table->must_eat)
	{
		pthread_mutex_unlock(&philo->table->door);
		return(1);
	}
	pthread_mutex_lock(&philo->table->door);
	return(0);	
}
// Check if all philosophers are sated according to the must-eat requirement
int check_all_sated(t_table *table)
{
	
}

