/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:39:33 by emorshhe          #+#    #+#             */
/*   Updated: 2024/06/19 18:16:14 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo_library.h"

int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("Error\n");
			printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
		
			return(0);
		
		}
		i++;
	}
	return (1);
}

int value_parameter(char **argv, int argc)
{
	int i;

	i = 1;
	while(argv[i] && i <= argc)
	{
        	if(ft_isdigit(argv[i]) == 0)
               	return (0);
		i++;
	}
	
	if(!((atoi(argv[1]) > 0 && atoi(argv[1]) < 201)) 
		|| !(atoi(argv[2]) >= 60)
		|| !(atoi(argv[3]) >= 60)
		|| !(atoi(argv[4]) >= 60))
	{
		printf("Error\n");
        printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
		return(0);
	}
	return(1);
}

int main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc > 4 && argc < 7)
	{
		if (value_parameter(argv, argc) == 0)
			return(0);
		table.num_philosofos = atoi(argv[1]);
		table.time_die = atoi(argv[2]);
		table.time_eat = atoi(argv[3]);
		table.time_sleep = atoi(argv[4]);
		if(argv[5] && atoi(argv[5]) > 0)
			table.must_eat = atoi(argv[5]);
		printf("num_philos-> %d\n time_die->%d\ntime_eat->%d\ntime_sleep->%d\nmust_eat-> %d\n",table.num_philosofos, table.time_die, table.time_eat, table.time_sleep,table.must_eat);
	}
	else
    {
        printf("Error\n");
        printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
    }

	start_forks_mutex(&table);
	start_philo(&table);
	wait_join_philo(&table);
	
	
	return(0);
}
