/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:10:21 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 21:31:01 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int				result;
	char			*string = NULL;
	int				integer = -1234;
	char			character = 'A';
	unsigned int	u_int = 151516;
	
	
	result = ft_printf("\nft_printf Args: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\nPointer: %p\n", string, integer, u_int, character, u_int, u_int, &u_int);
	ft_printf("\nft_printf return value: %d (-3 because of \"ft_\")\n", result);
	result = printf("\nprintf Args: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\nPointer: %p\n", string, integer, u_int, character, u_int, u_int, &u_int);
	printf("\nprintf return value: %d\n", result);
}
