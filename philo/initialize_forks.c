/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:18:45 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/25 02:54:48 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Allocating memory for the forks
int	memory_forks_mutex(t_table *table)
{
	table->forks = (pthread_mutex_t *)
		malloc(table->num_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	return (1);
}

// Initializing the forks
int	start_forks_mutex(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
	}
	return (1);
}

// Making a philosopher take a fork
int	take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->table->forks[fork_id]);
	pthread_mutex_lock(&philo->table->door);
	if (!philo->table->finished)
	{
		printf("%ld %d has taken a fork\n",
			get_formatted_time(philo->table->begin_time), philo->id + 1);
	}
	pthread_mutex_unlock(&philo->table->door);
	return (fork_id);
}

// Getting the necessary forks for the philosopher
int	get_forks(t_philo *philo, int *forks)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id;
	right_fork = (philo->id + 1) % philo->table->num_philos;
	if (philo->table->num_philos < 2)
	{
		mspleep(philo->table->time_to_die);
		return (0);
	}
	if (left_fork < right_fork)
	{
		forks[0] = take_fork(philo, left_fork);
		forks[1] = take_fork(philo, right_fork);
		return (1);
	}
	else
	{
		forks[0] = take_fork(philo, right_fork);
		forks[1] = take_fork(philo, left_fork);
		return (2);
	}
	return (0);
}

// Releasing the forks after the philosopher has finished eating
int	release_forks(int *forks, t_philo *philo, int position_forks)
{
	if (position_forks == 1)
	{
		pthread_mutex_unlock(&philo->table->forks[forks[1]]);
		pthread_mutex_unlock(&philo->table->forks[forks[0]]);
		return (1);
	}
	else if (position_forks == 2)
	{
		pthread_mutex_unlock(&philo->table->forks[forks[0]]);
		pthread_mutex_unlock(&philo->table->forks[forks[1]]);
		return (2);
	}
	printf("%ld %d is trying to largou fork %ls\n",
		get_formatted_time(philo->table->begin_time), philo->id + 1, forks);
	return (0);
}
