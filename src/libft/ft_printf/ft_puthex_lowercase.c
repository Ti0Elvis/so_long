/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:49:23 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:23 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_lowercase(unsigned long long int num, int *count)
{
	char	*hex;

	if (num >= 16)
	{
		ft_puthex_lowercase(num / 16, count);
		ft_puthex_lowercase(num % 16, count);
	}
	else
	{
		hex = "0123456789abcdef";
		ft_putchar(hex[num], count);
	}
}
