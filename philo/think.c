/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:01 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 17:06:05 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

int think(t_philo *philo)
{	
	int	table_conclude;
	t_table *table = philo->table;
	
	table_conclude = 0;
	pthread_mutex_lock(&table->door);
    	if(!table->finished)
	{
		printf("%ld %d is thinking\n", 
		get_formatted_time(table->begin_time), philo->id);
	}
	table_conclude = table->finished;	
	mspleep(table->time_think);
	pthread_mutex_unlock(&table->door);
	return(table_conclude);
}

