/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:02:04 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 16:10:55 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

void cleanup(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->door);
	free(table->forks);
	free(table->philos);
}

int	initialize_table(t_table *table)
{
	if(pthread_mutex_init(&table->door, NULL) != 0)
		return(0);
	table->finished = 0;
	if(!start_forks_mutex(table))
		return(0);
	if(!start_philo(table))
		return(0);
	if(!create_and_join_philo(table))
		return(0);
	return(1);
}
