/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:23:11 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:29:00 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	void	*array;

	if (n_elements != 0 && size > 4294967295U / n_elements)
	{
		return (NULL);
	}
	array = malloc(n_elements * size);
	if (!array)
	{
		return (NULL);
	}
	ft_bzero(array, n_elements * size);
	return (array);
}
