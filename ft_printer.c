/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:05:03 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 21:23:58 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long long n, int base, int upper)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (base == 16)
	{
		if (n >= 16)
			count += ft_puthex(n / 16, base, upper);
		if (upper)
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
			count += ft_putchar("0123456789abcdef"[n % 16]);
	}
	else if (base == 10)
	{
		if (n >= 10)
			count += ft_puthex(n / 10, base, upper);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

int	ft_puthex_unsigned(unsigned long long n, int base, int upper)
{
	int		count;

	count = 0;
	if (base == 16)
	{
		if (n >= 16)
			count += ft_puthex_unsigned(n / 16, base, upper);
		if (upper)
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
			count += ft_putchar("0123456789abcdef"[n % 16]);
	}
	return (count);
}

int	ft_putpointer(void *pointer)
{
	int	count;

	count = 0;
	if (pointer == 0)
		return (count += ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex_unsigned((unsigned long long)pointer, 16, 0);
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}
