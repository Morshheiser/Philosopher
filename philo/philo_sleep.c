/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:35 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 00:02:18 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

//Handle philosophers 's sleeping routine
int	philo_sleep(t_philo *philo)
{
	t_table	*table;
	int		table_conclude;

	table = philo->table;
	table_conclude = 0;
	pthread_mutex_lock(&table->door);
	if (!table->finished)
	{
		printf("%ld %d is sleeping\n", 
			get_formatted_time(table->begin_time), philo->id + 1);
	}
	table_conclude = table->finished;
	pthread_mutex_unlock(&table->door);
	mspleep(table->time_to_sleep);
	return (table_conclude);
}
