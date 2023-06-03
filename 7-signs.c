#include "main.h"

void handle_plus_flag(int* count, int* is_negative) {
    if (*is_negative) {
        custom_putchar('-');
        *count += 1;
    } else {
        custom_putchar('+');
        *count += 1;
    }
}

void handle_space_flag(int* count, int is_negative) {
    if (is_negative) {
        custom_putchar('-');
        *count += 1;
    } else {
        custom_putchar(' ');
        *count += 1;
    }
}

void handle_hash_flag(int* count, const char* format, va_list args) {
    if (*format == 'o') {
        int value = va_arg(args, int);
        if (value != 0) {
            custom_putchar('0');
            *count += 1;
        }
    } else if (*format == 'x' || *format == 'X') {
        custom_putstr(*format == 'x' ? "0x" : "0X");
        *count += 2;
    } else if (*format == 'f' || *format == 'F' || *format == 'e' || *format == 'E' ||
               *format == 'g' || *format == 'G') {
        if (strchr(format, '.') == NULL) {
            custom_putchar('.');
            *count += 1;
        }
    }
}
