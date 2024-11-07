/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 12:38:18 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_manage_args(char letter, va_list args)
{
	int char_count;

	char_count = 0;
	if (letter == 's')
	{
		char_count = ft_strlen(va_arg(args, char *));
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	// else if ()
	return (char_count);
}