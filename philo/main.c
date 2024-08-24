/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:47:52 by emorshhe          #+#    #+#             */
/*   Updated: 2024/08/20 15:11:03 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// check if all characters in the string are digits
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
// Check if all command-line arguments are valid numbers and within the specified ranges
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
		|| !(atoi(argv[4]) >= 0))
	{
		printf("Error\n");
        printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
		return(0);
	}
	return(1);
}
// Verify that the command-line arguments are valid numbers and fall within the acceptable ranges
int main(int argc, char **argv)
{
	t_table	table;
	
	memset(&table, 0, sizeof(t_table));
	if (argc > 4 && argc < 7)
	{
		if (value_parameter(argv, argc) == 0)
			return(0);
		table.num_philos = atoi(argv[1]);
		table.time_die = atoi(argv[2]);
		table.time_eat = atoi(argv[3]);
		table.time_sleep = atoi(argv[4]);
		if(argv[5] && atoi(argv[5]) > 0)
			table.must_eat = atoi(argv[5]);
	
		if(!initialize_table(&table))
		{
			printf("Erro ao inicilizar a mesa.\n");
			return (1);
		}
		cleanup(&table);
	}
	else
	{
	    printf("Error\n");
	    printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
	}
	
	return(0);
}
