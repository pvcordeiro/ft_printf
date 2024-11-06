/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:06:11 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/06 01:23:18 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**ft_rec_split(const char *s, char c, char **str)
{
	const char	*substr;

	while (*s && *s == c)
		s++;
	if (!*s)
		return (str);
	substr = s;
	while (*s && *s != c)
		s++;
	*str = ft_substr(substr, 0, s - substr);
	if (!*str)
		return (NULL);
	return (ft_rec_split(s, c, str + 1));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**clean;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_sub_count(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	clean = str;
	if (!ft_rec_split(s, c, str))
	{
		while (*clean)
			free(*clean++);
		free(str);
		return (NULL);
	}
	return (str);
}
