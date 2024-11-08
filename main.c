/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:17:40 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 21:22:14 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			character = 'A';
	char			*string = NULL;
	char			*pointer = "abcjds";
	int				integer = INT_MIN;
	unsigned int	u_int = UINT_MAX;
	int				hex = 151516;
	int				result;

	ft_printf("\nft_printf:\n");
	result = ft_printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	ft_printf("\nft_printf return value: %d\n", result);

	printf("\n\nprintf:\n");
	result = printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	printf("\nprintf return value: %d\n", result);
}