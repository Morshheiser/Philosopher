/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:47:52 by emorshhe          #+#    #+#             */
/*   Updated: 2024/10/25 03:21:04 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_library.h"

// check if all characters in the string are digits
int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("\nError\n");
			printf("\nOnly positive numbers are accepted.\n");
			printf("\nUsage: ./philo <philo> <die> <eat> <sleep> (<must eat>)");
			printf("\n\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* Parses and validates command-line arguments
 to initialize the philosopher table,
converting strings to integers and setting parameters,
 including 'must_eat' if provided.*/

int	value_parameter(char **argv, int argc, t_table *table)
{
	int	i;

	i = 1;
	while (argv[i] && i <= argc)
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	table->begin_time = get_current_time();
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] && atoi(argv[5]) > 0)
		table->must_eat = ft_atoi(argv[5]);
	if (error_initialize_table(table))
	{
		printf("\nError\n");
		printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
		return (0);
	}
	return (1);
}

/* Validates the parameters for initializing the philosopher table.
	Prints error messages for any invalid parameters.*/
int	error_initialize_table(t_table *table)
{
	if (!(table->num_philos > 0 && table->num_philos < 200))
	{
		printf("\nOnly 1 to 200 philosophers are accepted.\n\n");
		return (0);
	}
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
	{
		printf("\nTimestamps needs to be greater than 60\n\n");
		return (0);
	}
	return (1);
}

/* Verify that the command-line arguments are valid numbers and fall
 within the acceptable ranges */
int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc < 5 || argc > 6)
	{
		printf("Error\n");
		printf("Usage: ./philo <philo> <die> <eat> <sleep> (<must eat>)\n");
	}
	if (argc > 4 && argc < 7)
	{
		value_parameter(argv, argc, &table);
		initialize_table(&table);
		cleanup(&table);
	}
	return (0);
}
