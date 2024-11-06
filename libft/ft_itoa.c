/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:00:54 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/05 23:18:57 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_digit_counter(long nb)
{
	long	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	ft_create_str(long i, char *str, long n)
{
	while (i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	digits;
	long	nb;

	nb = n;
	digits = ft_digit_counter(nb);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		ft_create_str(digits - 1, str + 1, -nb);
	}
	else
		ft_create_str(digits, str, nb);
	return (str);
}
