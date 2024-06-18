/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:20:32 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/05 21:28:54 by emorshhe         ###   ########.fr       */
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
		n = n / 10;
		i++;
	}
	return (i);
}

static int	number(unsigned int n, int base1)
{
	char	*str;
	int		j;
	int		i;

	j = count(n);
	i = 0;
	str = (char *) malloc ((j + 1) * sizeof(char));
	if (!str)
		return (0);
	str[j] = '\0';
	while (n > 0)
	{
		str[--j] = n % base1 + '0';
		n = n / base1;
	}
	while (str[i])
		write(1, &str[i++], 1);
	free (str);
	return (i);
}

int	ft_itoaprint(int n, char format)
{
	int	i;

	if (n == 0)
	{
		i = 1;
		write (1, "0", 1);
		return (i = 1);
	}
	if (format == 'u')
		return (number ((unsigned int) n, i = 10));
	if (n < 0)
	{
		n = -n;
		return (ft_putcharprint('-') + number(n, i = 10));
	}
	if ((int)n == -2147483648)
		return (ft_putcharprint('-') + number((unsigned int) n, i = 10));
	return (number (n, i = 10));
}
