/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:46:45 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:16 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(void *ptr, int *count)
{
	unsigned long long int	num;

	num = (unsigned long long int)ptr;
	if (ptr == NULL)
	{
		return (ft_putstr("(nil)", count));
	}
	ft_putstr("0x", count);
	ft_puthex_lowercase(num, count);
}
