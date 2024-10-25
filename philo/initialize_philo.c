/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:39:15 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/25 03:19:24 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Allocating memory for the philosopher
int	create_philos_forks(t_table *table)
{
	table->philos = (t_philo *)malloc(table->num_philos * sizeof(t_philo));
	if (!table->philos)
		return (0);
	if (memory_forks_mutex(table) != 1)
	{
		free(table->philos);
		return (0);
	}
	if (pthread_mutex_init(&table->door, NULL) != 0)
		return (0);
	return (1);
}

// Initialize a philosopher
int	boot_philosofos(int i, t_philo *philo, t_table *table)
{
	philo->table = table;
	philo->id = i;
	philo->eat_count = 0;
	philo->last_time_eat = table->begin_time;
	if (pthread_create(&philo->thread, NULL, routine_philo, philo) != 0)
		return (0);
	return (1);
}

/* Initialize philosopher array,create threads, and set up monitoring
 Create philosopher threads and wait for their completion*/
int	start_philo(t_table *table)
{
	int	i;

	if (create_philos_forks(table) != 1)
		return (0);
	if (start_forks_mutex(table) != 1)
		return (0);
	i = -1;
	while (++i < table->num_philos)
	{
		if (boot_philosofos(i, &table->philos[i], table) != 1)
			return (0);
	}
	if (create_oracle(table) != 1)
		return (0);
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
