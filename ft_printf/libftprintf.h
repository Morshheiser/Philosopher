/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:07:01 by emorshhe          #+#    #+#             */
/*   Updated: 2023/12/05 21:35:40 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putcharprint(int str);
int	ft_putstrprint(char *str);
int	ft_itoaprint(int n, char format);
int	ft_base(unsigned int n, char format);
int	ft_printf(const char *format, ...);
int	ft_pointer(long long int nbr, const char *base);

#endif
