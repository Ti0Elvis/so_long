/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:38:42 by evera             #+#    #+#             */
/*   Updated: 2025/09/12 17:32:30 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	ft_putfn(char c, va_list args, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putpointer(void *ptr, int *count);
void	ft_putnbr(long int num, int *count);
void	ft_puthex_lowercase(unsigned long long int num, int *count);
void	ft_puthex_uppercase(unsigned long long int num, int *count);

#endif
