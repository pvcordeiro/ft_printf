/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:24:51 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/06 00:43:51 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ltt_len;

	ltt_len = ft_strlen(little);
	if (!ltt_len)
		return ((char *)big);
	while (*big && ltt_len <= len--)
	{
		if (!ft_strncmp(big++, little, ltt_len))
			return ((char *)--big);
	}
	return (NULL);
}
