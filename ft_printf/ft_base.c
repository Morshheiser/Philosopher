/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:36:35 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/05 21:37:27 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	count(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	check_base(unsigned int n, char *base)
{
	char	*result;
	int		i;
	int		j;
	int		a;

	a = 0;
	j = 0;
	result = (char *) malloc (((i = count(n)) + 1) * sizeof(char));
	if (!result)
		return (0);
	result[i] = '\0';
	while (n > 0)
	{
		j = n % 16;
		result[--i] = base[j];
		n = n / 16;
		a++;
	}
	i = 0;
	while (result[i] != '\0')
		write(1, &result[i++], 1);
	free(result);
	return (a);
}

int	ft_base(unsigned int n, char format)
{
	char		*base;
	int			i;

	if (n == 0)
	{
		i = 1;
		write (1, "0", 1);
		return (i = 1);
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (check_base(n, base));
}
