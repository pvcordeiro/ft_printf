/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:10:21 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/08 00:25:04 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pv_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int				result;
	char			*string = NULL;
	int				integer = -1234;
	char			character = 'A';
	int				hex = 151516;
	unsigned int	u_int = UINT_MAX;
	
	ft_printf("\n\nft_printf:\n");
	result = ft_printf("\nArgs: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\nPointer: %p\n", string, integer, u_int, character, hex, hex, &u_int);
	ft_printf("\nft_printf return value: %d\n", result);
	ft_printf("\n\nprintf:\n");
	result = printf("\nArgs: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\nPointer: %p\n", string, integer, u_int, character, hex, hex, &u_int);
	printf("\nprintf return value: %d\n", result);
}
