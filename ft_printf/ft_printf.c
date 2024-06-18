/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:12:34 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:52 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	count_args(char a, va_list args)
{
	const char	*base;

	if (a == 'c')
		return (ft_putcharprint(va_arg(args, int)));
	if (a == 's')
		return (ft_putstrprint(va_arg(args, char *)));
	if (a == 'd' || a == 'i' || a == 'u')
		return (ft_itoaprint(va_arg(args, int), a));
	if (a == 'x' || a == 'X')
		return (ft_base(va_arg(args, unsigned int), a));
	if (a == 'p')
	{
		base = "0123456789abcdef";
		return (ft_pointer(va_arg(args, long long int), base));
	}
	if (a == '%')
		return (ft_putcharprint('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (0);
	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + count_args(format[i], args);
		}
		else
		{
			ft_putcharprint((int)format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
