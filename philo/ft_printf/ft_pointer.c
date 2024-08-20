/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:37:33 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/05 21:42:26 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write (1, &str[i++], 1);
	return (i);
}

static int	ft_putnbr(unsigned long int nbr, const char *base)
{
	unsigned long int	base_len;
	int					count;

	base_len = 0;
	count = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (nbr >= base_len)
	{
		count += ft_putnbr(nbr / base_len, base);
		count += ft_putnbr(nbr % base_len, base);
	}
	else
		count += ft_putcharprint(base[nbr]);
	return (count);
}

int	ft_pointer(long long int nbr, const char *base)
{
	unsigned long long int	n;

	n = (unsigned long long int) nbr;
	if (n == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr(n, base));
}
