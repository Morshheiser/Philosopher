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
void create_philos(t_table *table)
{
	table->philos = (t_philo *) malloc(table->num_philos * sizeof(t_philo));
	if(!table->philos)
		return;
}

// Initialize a philosopher
void boot_philosofos(int i, t_philo *philo, t_table *table)
{
	philo->table = table;
	philo->id = i;
	philo->is_alive = 1;
	philo->eat_count = 0;
	philo->last_time_eat = get_current_time();
}

// Initialize philosopher array,create threads, and set up monitoring
int start_philo(t_table *table)
{
	int	i;

	create_philos(table);
	create_oracle(table);
	i = -1;
	while(++i < table->num_philos)
		boot_philosofos(i + 1, &table->philos[i], table);
	if(i != table->num_philos)
		return(0);
	return(1);	
}
