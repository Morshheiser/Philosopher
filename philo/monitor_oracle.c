/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:17:59 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/23 16:42:12 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"
// Monitor the philosophers activity and detect if anr philosopher has died
void	*oracle_day(void *arg)
{
	t_table	*table;
	int	i;


	table = (t_table *)arg;
	i = 0;
	while(1)
	{
		if(check_all_sated(table))
				break;
		pthread_mutex_lock(&table->door);
		if(table->finished)
		{
			pthread_mutex_unlock(&table->door);
			break;
		}
		if (get_current_time() - table->philos[i].last_time_eat > table->time_to_die)
		{
			if(!table->finished)
				printf("%ld %d died\n", get_formatted_time(table->begin_time), i + 1);
			table->finished = 1;
			pthread_mutex_unlock(&table->door);
			break;
		}
		pthread_mutex_unlock(&table->door);
		i = (i + 1) % table->num_philos;
		usleep(1000);

	}
	return NULL;
}
// Create and manage the oracle thread for the table
void	create_oracle(t_table *table)
{
	if(pthread_create(&table->oracle, NULL, &oracle_day, table) != 0)
		return ;
	if(pthread_join(table->oracle, NULL) != 0)
		return ;
}
