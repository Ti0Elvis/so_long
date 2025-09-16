/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:16:59 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:06 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	char		*line;
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	while (TRUE)
	{
		if (gnl_indexof(buffer, '\n') >= 0)
			return (gnl_return_line(temp, buffer, line));
		line = gnl_strjoin(line, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (gnl_free_line(line));
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
		{
			if (!line || line[0] == '\0')
				return (gnl_free_line(line));
			return (line);
		}
	}
}

char	*gnl_return_line(char *temp, char *buffer, char *line)
{
	temp = gnl_substr_until(buffer, gnl_indexof(buffer, '\n'));
	line = gnl_strjoin(line, temp);
	free(temp);
	gnl_clear_buffer(buffer);
	return (line);
}

char	*gnl_free_line(char *line)
{
	free(line);
	return (NULL);
}
