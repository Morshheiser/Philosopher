/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:01 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 00:02:31 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Handle philosopher's thinking routine
int	think(t_philo *philo)
{
	t_table	*table;
	int		table_conclude;

	table = philo->table;
	table_conclude = 0;
	pthread_mutex_lock(&table->door);
	if (!table->finished)
	{
		printf("%ld %d is thinking\n", 
			get_formatted_time(table->begin_time), philo->id + 1);
	}
	table_conclude = table->finished;
	pthread_mutex_unlock(&table->door);
	return (table_conclude);
}
