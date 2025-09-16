/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:17:12 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:01 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	gnl_indexof(char *str, int c)
{
	int	i;

	if (!str)
	{
		return (-1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*buffer;

	buffer = (char *)malloc(gnl_strlen(str1) + gnl_strlen(str2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[i] != '\0')
	{
		buffer[i] = str1[i];
		i++;
	}
	while (str2 && str2[j] != '\0')
	{
		buffer[i + j] = str2[j];
		j++;
	}
	buffer[i + j] = '\0';
	if (str1)
		free(str1);
	return (buffer);
}

char	*gnl_substr_until(char *str, int end)
{
	int		i;
	char	*buffer;

	buffer = malloc(end + 0x02);
	if (!buffer)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && i < end)
	{
		buffer[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buffer[i] = '\n';
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	gnl_clear_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
	{
		i++;
	}
	while (buffer[i] != '\0')
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}
