/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:09:25 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/05 19:42:19 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*iter;

	iter = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*iter++ = *(unsigned char *)src++;
	return (dest);
}
