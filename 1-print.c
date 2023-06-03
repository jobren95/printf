#include "main.h"

void print_formatted_integer(const char* format, va_list args) {
    int value, base, is_negative, temp, num_digits, index;
    char* buffer;

    (void)format;

    value = va_arg(args, int);
    base = 10;
    is_negative = 0;

    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    /* Count the number of digits */
    temp = value;
    num_digits = 0;
    do {
        temp /= base;
        num_digits++;
    } while (temp != 0);

    /* Allocate memory for the buffer */
    buffer = (char*)malloc((num_digits + is_negative + 1) * sizeof(char));
    if (buffer == NULL) {
        /* Handle memory allocation failure */
        return;
    }

    /* Store each digit in reverse order */
    index = num_digits + is_negative - 1;
    temp = value;
    do {
        int digit = temp % base;
        buffer[index--] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        temp /= base;
    } while (index >= is_negative);

    /* Handle negative sign */
    if (is_negative) {
        buffer[0] = '-';
    }

    /* Print the number */
    write(STDOUT_FILENO, buffer, num_digits + is_negative);

    /* Free dynamically allocated memory */
    free(buffer);
}
