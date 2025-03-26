#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int putstr(char *str)
{
	int count = 0;
	if (!str)
		return (count += write(1, "(null)", 6));
	if (!*str)
		return (0);
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int putbase(int n, int base)
{
	int count = 0;
	char *digits = "0123456789abcdef";

	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	if (n >= base)
		count += putbase(n / base, base);
	return (count += write(1, &digits[n % base], 1));
}

int	ft_printf(char *input, ...)
{
	va_list args;
	int count = 0;
	va_start(args, input);

	while (*input)
	{
		if (*input == '%' && *(input + 1) == 's')
			count += putstr(va_arg(args, char *)), input++;
		else if (*input == '%' && *(input + 1) == 'd')
			count += putbase(va_arg(args, int), 10), input++;
		else if (*input == '%' && *(input + 1) == 'x')
			count += putbase(va_arg(args, unsigned int), 16), input++;
		else
			count += write(1, input, 1);
		input++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	char *str = "ABC";
	int hex = 151516;
	int digit = 12345;
	int output;

	output = ft_printf("ft_printf: %s\n%x\n%d\n", str, hex, digit);
	ft_printf("output: %d\n", output);
	output = printf("printf: %s\n%x\n%d\n", str, hex, digit);
	printf("output: %d\n", output);
}