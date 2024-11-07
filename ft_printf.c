/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:06 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 14:26:52 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *input, ...)
{
	int		print_count;
	va_list	args;

	print_count = 0;
	va_start(args, input);
	ft_printer(input, args, &print_count);
	va_end(args);
	return (print_count);
}

