#include "main.h"

void custom_write(const char* str, int length) {
    write(STDOUT_FILENO, str, length);
}

void custom_putchar(char c) {
    write(STDOUT_FILENO, &c, 1);
}

int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void custom_puts(const char* str) {
    int length = custom_strlen(str);
    custom_write(str, length);
    custom_putchar('\n');
}

void custom_putstr(const char* str) {
    int length = custom_strlen(str);
    custom_write(str, length);
}

void custom_reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void custom_itoA(unsigned int value, char* str, int base) {
    int i = 0;
    while (value != 0) {
        int digit = value % base;
        str[i++] = digit < 10 ? digit + '0' : digit + 'A' - 10;
        value /= base;
    }
    str[i] = '\0';
    custom_reverse(str, i);
}

void custom_sprintf(char* buffer, const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == '\0')
                break;
            else if (*format == 'x') {
                unsigned int value = va_arg(args, unsigned int);
                int i = 0;
                while (value != 0) {
                    int digit = value % 16;
                    buffer[i++] = digit < 10 ? digit + '0' : digit + 'A' - 10;
                    value /= 16;
                }
                buffer[i] = '\0';
                custom_reverse(buffer, i);
            }
        } else {
            *buffer++ = *format;
        }
        format++;
    }

    va_end(args);
}
