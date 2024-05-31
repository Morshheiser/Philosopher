/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:00:48 by emorshhe          #+#    #+#             */
/*   Updated: 2024/05/31 16:48:52 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

t_philo create_philo(t_philo *philo, t_table *table, int id)
{
    
    philo = boot_philosofos(philo, table, id);
    printf("criando philo");
    return(philo);
}

void create_philos (t_table *table)
{
    int i;
    t_philo *philos;
    
    i = 0;
    philos = memory_philofos(table->philo, table->num_philosofos);
    while(i < table->num_philosofos)
    {
        philos[i] = create_philo(&philos[i], table, i);
        i++;
    }

}

void initialize_table(t_table *table)
{
    create_philos(table);
    //join_thread(table);
}