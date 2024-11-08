/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:05:03 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 01:57:05 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pv_puthex(long n, int base, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		count += pv_putchar('-');
	}
	if (n >= base)
		count += pv_puthex(n / base, base, upper);
	return (count += pv_putchar(digits[n % base]));
}

int	pv_putpointer(void *p)
{
	if (!p)
		return (pv_putstr("(nil)"));
	return (pv_putstr("0x") + pv_puthex_unsigned((unsigned long)p));
}

int	pv_puthex_unsigned(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += pv_puthex_unsigned(n / 16);
	count += pv_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	pv_putstr(char *s)
{
	if (!s)
		return (pv_putstr("(null)"));
	if (!*s)
		return (0);
	return (pv_putchar(*s) + pv_putstr(s + 1));
}

int	pv_putchar(char c)
{
	return (write(1, &c, 1));
}
