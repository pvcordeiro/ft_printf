/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 19:55:36 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(const char *input, va_list args)
{
	int		count;

	count = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
			count += ft_print_args(*(++input), args);
		else if (*input == '%' && *(input + 1) == '%')
			count += ft_putchar_fd(*(++input), 1);
		else
			count += ft_putchar_fd(*input, 1);
		input++;
	}
	return (count);
}

int	ft_print_args(char letter, va_list args)
{
	int	count;

	count = 0;
	if (letter == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (letter == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (letter == 'd' || letter == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (letter == 'u')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 10, 0);
	else if (letter == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 16, 0);
	else if (letter == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 16, 1);
	else if (letter == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putnbr_hex(va_arg(args, unsigned long), 16, 0);
	}
	return (count);
}

int	ft_putnbr_hex(unsigned long n, int base, int upper)
{
	int		count;
	
	count = 0;
	if (base == 16)
	{
		if (n >= 16)
			count += ft_putnbr_hex(n / 16, base, upper);
		if (upper)
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
			count += ft_putchar("0123456789abcdef"[n % 16]);
	}
	else if (base == 10)
	{
		if (n >= 10)
			count += ft_putnbr_hex(n / 10, base, upper);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}