/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:55:18 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/06 00:50:56 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	full_size;

	if (!s1 || !s2)
		return (NULL);
	full_size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(full_size + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, full_size);
	ft_strlcat(str, s2, full_size + 1);
	return (str);
}
