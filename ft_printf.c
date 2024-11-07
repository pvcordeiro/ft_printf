/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:06 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 12:35:07 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*format + 1))
		{
			format++;
			char_count = ft_manage_args(*format, args);
		}
		else
		{
			char_count++;
			write(1, format++, 1);
		}
	}
	va_end(args);
	return (char_count);
}

