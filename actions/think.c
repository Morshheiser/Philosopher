/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:25 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/07 21:11:37 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo/philo_library.h"

void *think(int philo_id, int time_think)
{
    int t_think; 
    
    t_think = 0;
    printf("Filósofo %d está pensando\n", philo_id);
    while((t_think < time_think))
    {
        sleep(1);
        t_think++;
    }
    printf("Filósofo %d foi iluminado\n", philo_id);
}

