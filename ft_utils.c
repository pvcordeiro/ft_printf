/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 14:29:23 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printer(const char *input, va_list args, int *print_count)
{
	while (*input)
	{
		if (*input == '%' && *(input + 1) != '%' && *(input + 1))
		{
			input++;
			print_count += ft_manage_args(*input, args);
		}
		else if (*input == '%' && *(input + 1) == '%')
			write(1, ++input, 1);
		else
		{
			print_count++;
			write(1, input, 1);
		}
		input++;
	}
	return (*print_count);
}

int	ft_manage_args(char letter, va_list args)
{
	int char_count;
	// va_list args_copy;

	//char_count = count_printed(va_copy(args_copy, args));
	char_count = 0;
	if (letter == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if(letter == 'd' || letter == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if(letter == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	else if(letter == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	// else if ()
	// va_end(args_copy)
	return (char_count);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

// inf	count_printed(va_list args)
// {
//	int count;
//
//	count = 0;
//	
// }