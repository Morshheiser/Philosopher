/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:00:48 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 18:29:43 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// Inicializa cada filósofo    
void start_philo(t_table *table)
{    
    int i;
    
    create_philos(table);
    i = 0;
    while(i < table->num_philosofos)
    {
        boot_philosofos(i + 1, &table->philo[i], table);
        i++;
    }
    
}
void wait_join_philo(t_table *table)
{
    int i;
    
    i = 0;
    while(i < table->num_philosofos)
    {
        if(pthread_create(&table->philo[i].thread, NULL, routine_philo, &table->philo[i]) != 0)
        {
            printf("Erro ao criar a thread para o filósofo %d\n", i);
            return;
        }
        i++;
    }
    i = 0;
    while (i < table->num_philosofos) {
        if (pthread_join(table->philo[i].thread, NULL) != 0)
        {
            printf("Erro ao esperar a thread do filósofo %d\n", i);
            return;
        }
        i++;
    }
}

