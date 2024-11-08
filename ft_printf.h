/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:39:58 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 00:04:31 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *input, ...);
int	pv_filter_args(char letter, va_list args);
int	pv_checker(const char *input, va_list args);
int	pv_puthex(long n, int base, int upper);
int	pv_puthex_unsigned(unsigned long n);
int	pv_putpointer(void *pointer);
int	pv_putchar(char c);
int	pv_putstr(char *s);

#endif