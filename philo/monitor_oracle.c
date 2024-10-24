/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_oracle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:17:59 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/24 17:07:16 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Monitor the philosophers activity and detect if anr philosopher has died
void	*oracle_day(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	i = 0;
	while (1)
	{
		if (check_all_philo_finalize(table) == 1)
			break ;
		pthread_mutex_lock(&table->door);
		if (get_current_time() - table->philos[i].last_time_eat
			> table->time_to_die)
		{
			if (!table->finished)
				printf("%ld %d died\n",
					get_formatted_time(table->begin_time), i + 1);
			table->finished = 1;
			break ;
		}
		i = (i + 1) % table->num_philos;
		pthread_mutex_unlock(&table->door);
		usleep(1000);
	}
	pthread_mutex_unlock(&table->door);
	return (NULL);
}

// Create and manage the oracle thread for the table
int	create_oracle(t_table *table)
{
	if (pthread_create(&table->oracle, NULL, &oracle_day, table) != 0)
	{
		printf("Error: pthread_create\n");
		return (0);
	}
	if (pthread_join(table->oracle, NULL) != 0)
	{
		printf("Error: pthread_join\n");
		return (0);
	}
	return (1);
}
