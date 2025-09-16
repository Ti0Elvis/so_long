/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:17:22 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:10 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define TRUE 1

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		gnl_strlen(char *str);
int		gnl_indexof(char *str, int c);
char	*gnl_strjoin(char *str1, char *str2);
char	*gnl_substr_until(char *str, int end);
void	gnl_clear_buffer(char *buffer);
char	*gnl_free_line(char *line);
char	*gnl_return_line(char *temp, char *buffer, char *line);

#endif
