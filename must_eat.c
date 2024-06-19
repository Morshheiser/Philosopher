/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   must_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:41:12 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 13:18:40 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo_library.h"

void must_eat(t_table *table)
{
    int t_sleep;

    t_sleep = 0;
    printf("Filósofo %d está dormindo\n", table->philo->id);
    while(t_sleep < table->time_sleep)
    {
        sleep(1);
        t_sleep++;
    }
    printf("Filósofo %d terminou de dormir\n", table->philo->id);
}