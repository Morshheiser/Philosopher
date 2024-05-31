/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot_philo_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:03 by emorshhe          #+#    #+#             */
/*   Updated: 2024/05/31 19:38:32 by emorshhe         ###   ########.fr       */
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

//funcao para inicializar os mutexs do garfos
int boot_forks_mutex(t_table *table)
{
    int i;

    memory_forks_mutex(table);
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

//funcao para alocar memoria nos philosofos

t_philo *memory_philofos(t_philo *philos, int num)
{
    philos = malloc (num * sizeof(t_philo));
    if(!philos)
    {
        printf("%s", "Erro ao alocar memória para os philosofos\n");
        return(0);   
    }
    return(philos);   
}

//funcao para iniciar  e criar thread dos philosofos
t_philo *boot_philosofos(t_philo *philo, t_table *table, int id)
{
    int i;

    i = id;
    philo[i].is_alive = 1;
    philo[i].must_eat = 0;
    philo[i].id = i;
    philo[i].table = table;
    if(pthread_create(philo[i].thread, NULL, routine_philo, &philo[1]) != 0);
    {
        printf("Erro ao criar a thread para o filósofo %d\n", i);
        return (NULL);
    }
    return (philo);
}