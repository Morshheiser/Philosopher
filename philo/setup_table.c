/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:02:04 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 16:10:55 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"
// Clean up resources used by the table
void cleanup(t_table *table)
{
    int i;

    if (table->forks != NULL)
    {
        i = 0;
        while (i < table->num_philos)
        {
            pthread_mutex_destroy(&table->forks[i]);
            i++;
        }
        free(table->forks);
    }
    pthread_mutex_destroy(&table->door);
    if (table->philos != NULL)
		free(table->philos);
}

//Initialize the table and its resources
int	initialize_table(t_table *table)
{
	if(pthread_mutex_init(&table->door, NULL) != 0)
		return(0);
	if(!start_philo(table))
		return(0);
	return(1);
}
