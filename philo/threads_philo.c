/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:03:50 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 15:58:00 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

//funçao para criar e esperar pelas threads dos folosofos
int	create_and_join_philo(t_table *table)
{
	int i;

	i = -1;
	while(++i < table->num_philos)
	{
		if(pthread_create(&table->philos[i].thread, NULL,routine_philo, &table->philos[i]) != 0)
			return(0);
	}
	i = -1;
	while(++i < table->num_philos)
	{
		if(pthread_join(table->philos[i].thread, NULL) != 0)
			return(0);
	}
	return(1);
}
