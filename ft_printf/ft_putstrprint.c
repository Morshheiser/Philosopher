/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:33:06 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/05 21:42:53 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_putstrprint(char *str)
{
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*str)
	{
		write (1, str, 1);
		str++;
		i++;
	}
	return (i);
}
