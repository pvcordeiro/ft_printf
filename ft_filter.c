/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 23:55:32 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pv_checker(const char *input, va_list args)
{
	int		count;

	count = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
			count += pv_filter_args(*(++input), args);
		else if (*input == '%' && *(input + 1) == '%')
			count += pv_putchar(*(++input));
		else
			count += pv_putchar(*input);
		input++;
	}
	return (count);
}

int	pv_filter_args(char letter, va_list args)
{
	int	count;

	count = 0;
	if (letter == 's')
		count += pv_putstr(va_arg(args, char *));
	else if (letter == 'c')
		count += pv_putchar(va_arg(args, int));
	else if (letter == 'd' || letter == 'i')
		count += pv_puthex(va_arg(args, int), 10, 0);
	else if (letter == 'u')
		count += pv_puthex(va_arg(args, unsigned int), 10, 0);
	else if (letter == 'x')
		count += pv_puthex(va_arg(args, unsigned int), 16, 0);
	else if (letter == 'X')
		count += pv_puthex(va_arg(args, unsigned int), 16, 1);
	else if (letter == 'p')
		count += pv_putpointer(va_arg(args, void *));
	return (count);
}
