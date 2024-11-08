# ft_printf 🖨️

`ft_printf` is my custom implementation of the standard `printf` function in C, which formats and prints various types of data to the standard output. It supports multiple format specifiers, such as characters, strings, integers, unsigned integers, hexadecimal values, and pointers.

## 📑 Table of Contents
1. [Features](#-features)
2. [Files](#-files)
3. [Functions](#-functions)
4. [Compilation](#-compilation)
5. [Example Usage](#-example-usage)
6. [Authors](#-authors)

---

## 🔧 Features

- Supports basic specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, and `%%`.
- Implements formatted printing with recursion for hexadecimal and pointer output.
- Handles edge cases like null pointers and empty strings.
- Returns the number of characters printed, similar to the standard `printf`.

---

## 🛠️ Files

- **`ft_printf.c`**: Main logic for handling the printing functionality and format parsing.
- **`ft_printer.c`**: Helper functions to print specific data types, including characters, strings, integers, hexadecimal values, and pointers.
- **`ft_printf.h`**: Header file containing function prototypes and necessary includes.
- **`main.c`**: A test file for checking the correctness of the `ft_printf` implementation.
- **`Makefile`**: Build file for compiling the project and generating the static library `libftprintf.a`.

---

## 📑 Functions

**`int	ft_printf(const char *input, ...);`**

The main function that mimics the behavior of the standard printf. It takes a format string and a variable number of arguments.

**`int	pv_checker(const char *input, va_list args);`**

Responsible for parsing the format string and calling appropriate functions based on the format specifiers.

**`int	pv_filter_args(char letter, va_list args);`**

Handles specific format specifiers (%s, %c, %d, %u, %x, %X, %p).

**`int	pv_puthex(long n, int base, int upper);`**

Prints the hexadecimal representation of a number (both lower and upper case) or a decimal number.

**`int	pv_puthex_unsigned(unsigned long n);`**

Handles the printing of unsigned hexadecimal values.

**`int	pv_putpointer(void *pointer);`**

Prints the address of a pointer in the format 0x followed by the hexadecimal value.

**`int	pv_putstr(char *s);`**

Prints a string, handling NULL strings and empty strings by printing (null) or an empty string.

**`int	pv_putchar(char c);`**

Writes a single character to the standard output.

---

## 📦 Compilation

To compile the project and create the static library libftprintf.a, run the following command:

```
make
```

To clean up the object files, use:

```
make clean
```

To completely clean the project (remove object files and the library), use:

```
make fclean
```

To rebuild everything from scratch, use:

```
make re
```

Testing

You can also test the implementation by running:

```
make test
```

This will compile the library, link it with the provided main.c, clean everything and run the tests.

---

## 📝 Example Usage

Main file (main.c)

```
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			character = 'A';
	char			*string = NULL;
	int				integer = INT_MIN;
	unsigned int	u_int = UINT_MAX;
	int				hex = 151516;
	int				result;

	ft_printf("\n\nft_printf:\n");
	result = ft_printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n", character, string, &string, integer, u_int, hex, hex);
	ft_printf("\nft_printf return value: %d\n", result);
	ft_printf("\n\nprintf:\n");
	result = printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n", character, string, &string, integer, u_int, hex, hex);
	printf("\nprintf return value: %d\n", result);
}
```

Output:

```
ft_printf:

Char: A
String: (null)
Pointer: 0x7ffdd2ac7200
Int: -2147483648
Unsigned int: 4294967295
Percent: %
Lower Hex: 24db0
Upper Hex: 24DB0

ft_printf return value: 86

printf:

Char: A
String: (null)
Pointer: 0x7ffdd2ac7200
Int: -2147483648
Unsigned int: 4294967295
Percent: %
Lower Hex: 24db0
Upper Hex: 24DB0

printf return value: 86
```

---

## 👨‍💻 Authors

    pvcordeiro (me)
