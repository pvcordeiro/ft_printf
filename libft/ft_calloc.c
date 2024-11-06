/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:36:53 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/05 21:16:01 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*alloc;
	size_t			full_s;

	if (!nmemb || !size)
	{
		alloc = malloc(0);
		if (!alloc)
			return (NULL);
		return (alloc);
	}
	full_s = nmemb * size;
	if (nmemb != full_s / size)
		return (NULL);
	alloc = malloc(full_s);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, full_s);
	return ((void *)alloc);
}
