/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:35 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 17:05:26 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

int philo_sleep(t_philo *philo)
{
	int	table_conclude;
	t_table	*table = philo->table;

	table_conclude = 0;
	pthread_mutex_lock(&table->door);
	if(!table->finished)
	{
		printf("%ld %d is sleeping\n", 
		get_formatted_time(table->begin_time), philo->id);
	}
	table_conclude = table->finished;
	mspleep(table->time_sleep);
	pthread_mutex_unlock(&table->door);
	return(table_conclude);
}
