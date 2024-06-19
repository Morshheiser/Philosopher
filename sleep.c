/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:32:59 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:12 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo_library.h"

void philo_sleep(int philo_id, int time_sleep)
{
    printf("Filósofo %d está dormindo\n", philo_id);
    usleep(time_sleep);
    printf("Filósofo %d terminou de dormir\n", philo_id);
}