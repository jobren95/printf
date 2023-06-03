#include "main.h"

int handle_conversion_specifier(const char* format, va_list args) {
    int count = 0;
    char buffer[16];
    char* ptr = buffer;

    /* Check if the format specifier is one of the four specified. */
    if (*format == 'u') {
        /* Convert the value to an unsigned integer. */
        unsigned int value = va_arg(args, unsigned int);

        /* Print the value in decimal format. */
        do {
            int digit = value % 10;
            *ptr++ = digit + '0';
            value /= 10;
        } while (value != 0);

        /* Reverse the buffer */
        custom_reverse(buffer, ptr - buffer);

        /* Write the output to stdout. */
        custom_write(buffer, ptr - buffer);
        count += ptr - buffer;
    } else if (*format == 'o') {
        /* Convert the value to an unsigned integer. */
        unsigned int value = va_arg(args, unsigned int);

        /* Print the value in octal format. */
        do {
            int digit = value % 8;
            *ptr++ = digit + '0';
            value /= 8;
        } while (value != 0);

        /* Reverse the buffer */
        custom_reverse(buffer, ptr - buffer);

        /* Write the output to stdout. */
        custom_write(buffer, ptr - buffer);
        count += ptr - buffer;
    } else if (*format == 'x') {
        /* Convert the value to an unsigned integer. */
        unsigned int value = va_arg(args, unsigned int);

        /* Print the value in hexadecimal format, using lowercase letters. */
        do {
            int digit = value % 16;
            *ptr++ = (digit < 10) ? digit + '0' : digit + 'a' - 10;
            value /= 16;
        } while (value != 0);

        /* Reverse the buffer */
        custom_reverse(buffer, ptr - buffer);

        /* Write the output to stdout. */
        custom_write(buffer, ptr - buffer);
        count += ptr - buffer;
    } else if (*format == 'X') {
        /* Convert the value to an unsigned integer. */
        unsigned int value = va_arg(args, unsigned int);

        /* Print the value in hexadecimal format, using uppercase letters. */
        do {
            int digit = value % 16;
            *ptr++ = (digit < 10) ? digit + '0' : digit + 'A' - 10;
            value /= 16;
        } while (value != 0);

        /* Reverse the buffer */
        custom_reverse(buffer, ptr - buffer);

        /* Write the output to stdout. */
        custom_write(buffer, ptr - buffer);
        count += ptr - buffer;
    }

    return count;
}
