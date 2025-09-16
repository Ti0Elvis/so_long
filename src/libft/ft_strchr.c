/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:54:46 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:27:40 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			dest = (char *)&str[i];
			return (dest);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (dest);
}
