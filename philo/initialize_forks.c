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

/* while (++i < table->num_philos)
		pthread_mutex_init(&table->forks[i], NULL);
*/
int	get_first_fork(t_philo *philo)
{
	int	first_fork;

	first_fork = philo->id;
	pthread_mutex_lock(&philo->table->forks[first_fork]);
	pthread_mutex_lock(&philo->table->door);
	if (!philo->table->finished)
		printf("%ld %d has taken a fork\n",
			get_formatted_time(philo->table->begin_time), philo->id + 1);
	pthread_mutex_unlock(&philo->table->door);
	return (first_fork);
}

int	get_second_fork(t_philo *philo)
{
	int	second_fork;

	second_fork = (philo->id + 1) % philo->table->num_philos;
	pthread_mutex_lock(&philo->table->forks[second_fork]);
	pthread_mutex_lock(&philo->table->door);
	if (!philo->table->finished)
		printf("%ld %d has taken a fork\n",
			get_formatted_time(philo->table->begin_time), philo->id + 1);
	pthread_mutex_unlock(&philo->table->door);
	return (second_fork);
}

int	get_forks(t_philo *philo, int *forks_pointer)
{
	if (philo->table->num_philos == 1)
	{
		mspleep(philo->table->time_die);
		return (0);
	}
	if ((philo->id + 1) == philo->table->num_philos)
	{
		forks_pointer[0] = get_second_fork(philo);
		forks_pointer[1] = get_first_fork(philo);
	}
	else
	{
		forks_pointer[0] = get_first_fork(philo);
		forks_pointer[1] = get_second_fork(philo);
	}
	return (1);
}

int	release_forks(int first_fork, int second_fork, t_philo *philo)
{
	if ((philo->id + 1) == philo->table->num_philos)
	{
		pthread_mutex_unlock(&philo->table->forks[second_fork]);
		pthread_mutex_unlock(&philo->table->forks[first_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[first_fork]);
		pthread_mutex_unlock(&philo->table->forks[second_fork]);
	}
	return (1);
}

void	free_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

/*
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
*/


