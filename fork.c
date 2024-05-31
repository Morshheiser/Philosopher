/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:03 by emorshhe          #+#    #+#             */
/*   Updated: 2024/05/24 13:05:05 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

//funcao para inicializar os mutexes do garfos
void    boot_mutex(t_table *table)
{
    table->forks_mutex = malloc(table->num_philosofos * sizeof(pthread_mutex_t))
    if(!(table->forks_mutex))
    {
        printf("%s", "Erro ao alocar memória para os mutexes dos forks\n");
        exit(EXIT_FAILURE);   
    }

}

