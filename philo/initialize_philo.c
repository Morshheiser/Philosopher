/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:39:15 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 15:31:23 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Allocating memory for the philosopher
void create_philos_forks(t_table *table)
{
	table->philos = (t_philo *) malloc(table->num_philos * sizeof(t_philo));
	if(!table->philos)
		return;
	table->forks = (pthread_mutex_t *)malloc(table->num_philos * sizeof(pthread_mutex_t));
    if (table->forks == NULL)
	{
        // Falha na alocação de memória para os mutexes
        free(table->philos); // Liberar a memória previamente alocada
        return;
    }
}

// Initialize a philosopher
void boot_philosofos(int i, t_philo *philo, t_table *table)
{
	philo->table = table;
	philo->id = i;
	philo->eat_count = 0;
	philo->last_time_eat = table->begin_time;
}

// Initialize philosopher array,create threads, and set up monitoring
//Create philosopher threads and wait for their completion
int start_philo(t_table *table)
{
	int	i;

	create_philos_forks(table);
	i = -1;
	while (++i < table->num_philos) 
	{
        if (pthread_mutex_init(&table->forks[i], NULL) != 0) {
            return (0);
    }
	i = -1;
	while(++i < table->num_philos)
		boot_philosofos(i + 1, &table->philos[i], table);
	if(i != table->num_philos)
		return(0);
	i = -1;
	while(++i < table->num_philos)
	{
		if(pthread_create(&table->philos[i].thread, NULL,routine_philo, &table->philos[i]) != 0)
			return(0);
	}
	i = -1;
	create_oracle(table);
	while(++i < table->num_philos)
	{
		if(pthread_join(table->philos[i].thread, NULL) != 0)
			return(0);
	}
	if(pthread_join(table->oracle, NULL) != 0)
		return (0);
	return(1);	
	}
}
