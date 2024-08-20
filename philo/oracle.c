/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:17:59 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 13:37:09 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

void	*oracle_day(void *arg)
{
	(void) arg;
	printf("dia do oraclo");
	return NULL;
}

void	create_oracle(t_table *table)
{
	if(pthread_create(&table->oracle, NULL, &oracle_day, table) != 0)
		return ;
	if(pthread_join(table->oracle, NULL) != 0)
		return ;
}
