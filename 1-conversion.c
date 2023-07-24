#include "main.h"
int _putchar(char c)
{
return write(1, &c, 1);
}
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++; /* Move to the next character after '%' */
/* Handle the conversion specifiers */
switch (*format)
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
int i = 0;
while (str[i] != '\0')
{
count += _putchar(str[i]);
i++;
}
break;
}
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(*format);
break;
}
}
else
{
count += _putchar(*format);
}
format++; // Move to the next character in the format string
}
va_end(args);
return count;
}
