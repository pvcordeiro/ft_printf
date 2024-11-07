/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:10:21 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/07 19:30:10 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				result;
	char			*string = NULL;
	int				integer = -1234;
	char			character = 'A';
	unsigned int	u_int = 4294967295;
	
	
	result = ft_printf("\nft_printf Args: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\n", string, integer, u_int, character);
	ft_printf("\nft_printf return value: %d\n", result);
	result = printf("\nft_printf Args: \nString: %s\nInt: %d\nUnsigned int: %u\nChar: %c\nPercent: %%\n", string, integer, u_int, character);
	printf("\nprintf return value: %d\n", result);
}
