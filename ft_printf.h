/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:39:58 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 21:24:04 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_filter_args(char letter, va_list args);
int	ft_checker(const char *input, va_list args);
int	ft_puthex(long long n, int base, int upper);
int	ft_puthex_unsigned(unsigned long long n, int base, int upper);
int	ft_putpointer(void *pointer);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif