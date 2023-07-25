#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

int main(void) {
    int num = 42;
    _printf("Number with precision: %.5d\n", num); // Output: "Number with precision: 00042"
    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int written_chars = 0;
    const char *ptr = format;

    while (*ptr) {
        if (*ptr == '%') {
            // Process conversion specifier
            ptr++;
            if (*ptr == '.') {
                // Handle precision
                ptr++;
                int precision = 0;
                while (*ptr >= '0' && *ptr <= '9') {
                    precision = precision * 10 + (*ptr - '0');
                    ptr++;
                }
                
                // Process the conversion specifier (in this example, only %d)
                if (*ptr == 'd') {
                    int num = va_arg(args, int);
                    // Apply precision for %d (decimal)
                    char buffer[20]; // Adjust buffer size accordingly
                    int num_chars = snprintf(buffer, sizeof(buffer), "%0*d", precision, num);
                    written_chars += write(1, buffer, num_chars);
                }
            } else {
                // Handle other conversion specifiers (if needed)
            }
        } else {
            // Write regular characters to output
            written_chars += write(1, ptr, 1);
        }
        ptr++;
    }

    va_end(args);
    return written_chars;
}
