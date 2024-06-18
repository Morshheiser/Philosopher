/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:32:59 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/07 21:01:32 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void philo_sleep(int philo_id, int time_sleep)
{
    int t_sleep;

    t_sleep = 0;
    printf("Filósofo %d está dormindo\n", philo_id);
    while(t_sleep < time_sleep)
    {
        sleep(1);
        t_sleep++;
    }
    printf("Filósofo %d terminou de dormir\n", philo_id);
}