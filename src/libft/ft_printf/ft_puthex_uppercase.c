/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:50:07 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:21 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_uppercase(unsigned long long int num, int *count)
{
	char	*hex;

	if (num >= 16)
	{
		ft_puthex_uppercase(num / 16, count);
		ft_puthex_uppercase(num % 16, count);
	}
	else
	{
		hex = "0123456789ABCDEF";
		ft_putchar(hex[num], count);
	}
}
