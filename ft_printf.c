/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:06 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 15:56:06 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	args;

	va_start(args, input);
	count = ft_parser(input, args);
	va_end(args);
	return (count);
}

