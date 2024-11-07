/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 16:36:43 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_parser(const char *input, va_list args)
{
	int		count;
	
	count = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
			count += ft_print_args(*(++input), args);
		else
			count += ft_putchar_fd(*input, 1);
		input++;
	}
	return (count);
}

int	ft_print_args(char letter, va_list args)
{
	int count;

	count = 0;
	if (letter == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (letter == 'd' || letter == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (letter == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (letter == 'c')
		count +=ft_putchar_fd(va_arg(args, int), 1);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	count++;
	return (count);
}
