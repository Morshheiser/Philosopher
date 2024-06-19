/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot_philo_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:03 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 18:23:25 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

//funcao para alocar memoria nos mutexes do garfos
int    memory_forks_mutex(t_table *table)
{
    table->forks_mutex = malloc(table->num_philosofos * sizeof(pthread_mutex_t));
    if(!(table->forks_mutex))
    {
        printf("%s", "Erro ao alocar memória para os mutexes dos forks\n");
        return (0);   
    }
    return (1);
}

//inicia os mutex dos garfos
int start_forks_mutex(t_table *table)
{
    int    i;

    if(!memory_forks_mutex(table))
        return(0);
    i = 0;
    while(i < table->num_philosofos)
    {
        if(pthread_mutex_init(&table->forks_mutex[i], NULL) != 0)
        {
            printf("%s", "Erro ao inicializar a mutex dos forks\n");
            return(0);
        }   
        i++;
    }
    return(1);
}   

//funcao para alocar memoria nos mutexes do garfos
void create_philos (t_table *table)
{     
    table->philo = (t_philo *) malloc(table->num_philosofos* sizeof(t_philo));
    if(!table->philo)
    {
        printf("Erro ao alocar memória para os filósofos\n");
        return;
    }
}
   

//funcao para iniciar cada philosofo
void boot_philosofos(int i, t_philo *philo, t_table *table)
{
    philo->id = i; 
    philo->is_alive = 1;
    philo->table = table;
    philo->table->must_eat = -1;
    printf("philofo criado:%d\n",philo->id);
}