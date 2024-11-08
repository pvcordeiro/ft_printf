/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pv_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:05:03 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 00:32:16 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pv_puthex(long n, int base, int upper)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += pv_putchar('-');
	}
	if (base == 16)
	{
		if (n >= 16)
			count += pv_puthex(n / 16, base, upper);
		if (upper)
			count += pv_putchar("0123456789ABCDEF"[n % 16]);
		else
			count += pv_putchar("0123456789abcdef"[n % 16]);
	}
	else if (base == 10)
	{
		if (n >= 10)
			count += pv_puthex(n / 10, base, upper);
		count += pv_putchar(n % 10 + '0');
	}
	return (count);
}

int	pv_putpointer(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (count += pv_putstr("(nil)"));
	count += pv_putstr("0x");
	count += pv_puthex_unsigned((unsigned long)p);
	return (count);
}

int	pv_puthex_unsigned(unsigned long n)
{
	int		count;

	count = 0;
	if (n >= 16)
		count += pv_puthex_unsigned(n / 16);
	count += pv_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	pv_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (count += pv_putstr("(null)"));
	while (*s)
		count += pv_putchar(*s++);
	return (count);
}

int	pv_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}
