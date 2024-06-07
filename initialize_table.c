/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:00:48 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/07 16:38:50 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

t_philo *create_philo(t_philo *philo, t_table *table, int id)
{
    return (boot_philosofos(philo, table, id));
    

}

void create_philos (t_table *table)
{
    int i;
    t_philo *philos;
    
    philos = memory_philofos(table->num_philosofos);
    if(!philos)
    {
        printf("Erro ao alocar memória para os filósofos\n");
        return;
    }
    i = 0;
    while(i < table->num_philosofos)
    {
        create_philo(&philos[i], table, i);
        i++;
    }
    table->philo = philos; // Atualiza a tabela com os filósofos criados
}

void initialize_table(t_table *table)
{
    create_philos(table);
    //join_thread(table);
}