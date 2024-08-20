/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:38:30 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 16:19:02 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

time_t get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec*1000) + (tv.tv_sec/1000));
}

time_t get_formatted_time(time_t start_time)
{
	time_t temp;

	temp = get_current_time() - start_time;
	
	return(temp);
}

void	mspleep(time_t time_sleep)
{
	time_t	time;

	time = get_current_time();
	while (get_current_time() - time < time_sleep)
		usleep(100);
}
