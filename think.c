/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:25 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 16:27:28 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo/philo_library.h"

void think(int philo_id, int time_think)
{
    printf("Filósofo %d está pensando\n", philo_id);
    usleep(time_think);
    printf("Filósofo %d foi iluminado\n", philo_id);
}

