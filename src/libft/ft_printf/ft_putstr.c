/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:45:55 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:14 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (str == NULL)
	{
		return (ft_putstr("(null)", count));
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}
