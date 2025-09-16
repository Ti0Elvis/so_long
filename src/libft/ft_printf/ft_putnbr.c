/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:48:06 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:19 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int num, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', count);
		num = num * -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, count);
		ft_putnbr(num % 10, count);
	}
	else
	{
		ft_putchar(num + '0', count);
	}
}
