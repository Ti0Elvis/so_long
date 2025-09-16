/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:09:20 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:43:14 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *src, size_t n);
void	*ft_calloc(size_t n_elements, size_t size);
void	*ft_memset(void *src, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
