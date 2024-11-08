/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:05:03 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 15:20:52 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pv_puthex_n_deci(long n, int base, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += pv_putchar('-');
	}
	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= base)
		count += pv_puthex_n_deci(n / base, base, upper);
	return (count += pv_putchar(digits[n % base]));
}

int	pv_putaddress(void *p, int prefix)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long)p;
	if (!n)
		return (pv_putstr("(nil)"));
	if (prefix)
		count += pv_putstr("0x");
	if (n >= 16)
		count += pv_putaddress((void *)(n / 16), 0);
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
