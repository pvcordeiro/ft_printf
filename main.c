#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char	*test = "abc";
	ft_printf("ft_printf: 123%s\n", test);
	printf("printf: 12%s\n", test);
}