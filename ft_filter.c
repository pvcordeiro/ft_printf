/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 21:17:07 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char *input, va_list args)
{
	int		count;

	count = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
			count += ft_filter_args(*(++input), args);
		else if (*input == '%' && *(input + 1) == '%')
			count += ft_putchar(*(++input));
		else
			count += ft_putchar(*input);
		input++;
	}
	return (count);
}

int	ft_filter_args(char letter, va_list args)
{
	int	count;

	count = 0;
	if (letter == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (letter == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (letter == 'd' || letter == 'i')
		count += ft_puthex(va_arg(args, int), 10, 0);
	else if (letter == 'u')
		count += ft_puthex(va_arg(args, unsigned int), 10, 0);
	else if (letter == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 16, 0);
	else if (letter == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 16, 1);
	else if (letter == 'p')
		count += ft_putpointer(va_arg(args, void *));
	return (count);
}
