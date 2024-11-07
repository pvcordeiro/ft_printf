#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char			*string = "abc";
	int				integer = 456;
	char			character = 'A';
	unsigned int	u_int = 4294967295;

	ft_printf("ft_printf:\nString: %s\n", string);
	ft_printf("Int: %d\n", integer);
	ft_printf("Unsigned int: %u\n", u_int);
	ft_printf("Char: %c\n", character);
	ft_printf("Percent: %%\n");
	
	printf("\nprintf:\nString: %s\n", string);
	printf("Int: %d\n", integer);
	printf("Unsigned int: %u\n", u_int);
	printf("Char: %c\n", character);
	printf("Percent: %%\n");

	printf("\n");
	ft_printf("\nft_printf return: %d\n", ft_printf("Input: asdada"));
	printf("\n");
	printf("\nprintf return: %d\n", printf("Input: asdada"));
}