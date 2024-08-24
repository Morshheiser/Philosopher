/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:18:45 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 11:32:59 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Allocating memory for the forks
int	memory_forks_mutex(t_table *table)
{
	table->forks = malloc(table->num_philos * sizeof(pthread_mutex_t));
	if(!table->forks)
		return (0);
	return (1);
}

// Initializing the forks
int	start_forks_mutex(t_table *table)
{
	int	i;

	if(!memory_forks_mutex(table))
		return (0);
	i = -1;
	while(++i < table->num_philos)
	{
		if(pthread_mutex_init(&table->forks[i], NULL))
			return (0);
	}
	if(pthread_mutex_init(&table->door,NULL))
		return (0);
	return(1);
}



