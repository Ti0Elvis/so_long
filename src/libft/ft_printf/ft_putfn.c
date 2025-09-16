/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:08:52 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:25 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putfn(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putpointer(va_arg(args, void *), count);
	else if (c == 'd')
		ft_putnbr((long int)va_arg(args, int), count);
	else if (c == 'i')
		ft_putnbr((long int)va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr((long int)va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex_lowercase((unsigned long long int)va_arg(args, unsigned int),
			count);
	else if (c == 'X')
		ft_puthex_uppercase((unsigned long long int)va_arg(args, unsigned int),
			count);
	else if (c == '%')
		ft_putchar('%', count);
}
