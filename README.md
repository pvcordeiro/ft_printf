ft_printf 🖨️

ft_printf is my custom implementation of the classic printf function in C. This project was created as part of the 42 curriculum to gain a deeper understanding of variadic functions and formatted printing.
Table of Contents 📑

    Description
    Files
    Usage
    Functions
    Installation
    Example
    Makefile
    Contributing
    License

Description 📜

ft_printf replicates the behavior of the C standard library function printf. It handles formatted output with various specifiers and supports the following:

    %s - String
    %c - Character
    %d / %i - Signed integer
    %u - Unsigned integer
    %x - Lowercase hexadecimal
    %X - Uppercase hexadecimal
    %p - Pointer
    %% - Literal percentage character

This implementation processes format specifiers using a variadic function, which handles a variable number of arguments and prints them based on the format. The library is optimized for efficient handling of different types and edge cases such as null pointers.

Files 📂

This repository contains the following files:

ft_printf.c

    Description: Implements the core ft_printf function, which processes the input format and calls helper functions to handle specific format specifiers.

ft_printer.c

    Description: Contains the helper functions that handle printing strings, characters, integers, hexadecimal numbers, and pointers.

ft_printf.h

    Description: Header file that contains the function prototypes and necessary includes. This file is required to use the ft_printf function in other C files.

main.c

    Description: A test file used to compare the behavior of ft_printf against the standard printf function. It tests various format specifiers and prints the return values of both functions.

Makefile

    Description: A build script used to compile and link the ft_printf library and the test program. It supports commands for compiling, cleaning, and testing.

Usage 🚀

To use ft_printf in your C project, include the header file ft_printf.h and link the compiled library (libftprintf.a) in your build process.
Example Usage

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char character = 'A';
    char *string = NULL;
    int integer = INT_MIN;
    unsigned int u_int = UINT_MAX;
    int hex = 151516;
    int result;

    ft_printf("\n\nft_printf:\n");
    result = ft_printf("\nArgs: \nChar: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n", 
        character, string, &string, integer, u_int, hex, hex);
    ft_printf("\nft_printf return value: %d\n", result);

    ft_printf("\n\nprintf:\n");
    result = printf("\nArgs: \nChar: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n", 
        character, string, &string, integer, u_int, hex, hex);
    printf("\nprintf return value: %d\n", result);
}

Example Output:

ft_printf:
Args: 
Char: A
String: (null)
Pointer: 0x7ffee8fd38a8
Int: -2147483648
Unsigned int: 4294967295
Percent: %
Lower Hex: 249f4
Upper Hex: 249F4
ft_printf return value: 103

printf:
Args: 
Char: A
String: (null)
Pointer: 0x7ffee8fd38a8
Int: -2147483648
Unsigned int: 4294967295
Percent: %
Lower Hex: 249f4
Upper Hex: 249F4
printf return value: 103

Functions 🧑‍💻

Here’s a list of functions implemented in ft_printf:
int ft_printf(const char *format, ...)

    Description: The main function. It takes a format string and a variable number of arguments, processes them, and prints the result to the standard output.

int pv_checker(const char *input, va_list args)

    Description: This function processes each character of the format string and checks if it is a valid format specifier. It then calls the appropriate function to handle the specifier.

int pv_filter_args(char letter, va_list args)

    Description: This function handles each format specifier, such as %s, %d, %x, etc., by calling the corresponding helper function to print the argument.

int pv_puthex(long n, int base, int upper)

    Description: This function prints the hexadecimal representation of a number, either in lowercase or uppercase.

int pv_putpointer(void *pointer)

    Description: This function prints a pointer address in the format 0x followed by the hexadecimal representation of the pointer.

int pv_putstr(char *s)

    Description: This function prints a string. If the string is NULL, it prints (null).

int pv_putchar(char c)

    Description: This function writes a single character to standard output using the write() system call.

int pv_puthex_unsigned(unsigned long n)

    Description: This function prints an unsigned long number in hexadecimal format.

Installation 🔧

To install ft_printf, clone this repository and include ft_printf.c, ft_printer.c, and ft_printf.h in your project.

git clone https://github.com/your-username/ft_printf.git

Compile the library by running:

make

Make sure to include the compiled libftprintf.a in your project's linking process.
Makefile 🛠️

The provided Makefile allows you to build, clean, and test the ft_printf library easily.
Makefile Commands:

    make: Builds the libftprintf.a static library.
    make clean: Removes the compiled object files.
    make fclean: Removes the object files and the static library.
    make re: Cleans and rebuilds the library.
    make test: Compiles and tests the ft_printf function with the provided main.c.

Contributing 🤝

Contributions are welcome! Feel free to fork the repository and submit a pull request if you’d like to improve or add functionality.
How to Contribute:

    Fork the repository.
    Create a new branch (git checkout -b feature-branch).
    Make your changes and commit them (git commit -am 'Add new feature').
    Push to the branch (git push origin feature-branch).
    Open a pull request.

License 📜

This project is open-source and available under the MIT License.
