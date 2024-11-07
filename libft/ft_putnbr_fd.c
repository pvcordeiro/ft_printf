/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:36:11 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 16:55:30 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
		count += ft_putnbr_fd((nb / 10), fd);
	count += ft_putchar_fd(nb % 10 + '0', fd);
	return (count);
}
