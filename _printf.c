#include "main.h"
/**
 * print_binary - Prints an unsigned integer in binary format.
 * @n: The unsigned int to be printed in binary.
 */
void print_binary(unsigned int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
						printed_chars += _putchar(*(str++));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'b':
					print_binary(va_arg(args, unsigned int));
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
