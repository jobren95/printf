#include "main.h"

int _printf(const char* format, ...);

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

int _printf(const char* format, ...) {
    va_list args;
    int count = 0;
    const char* current = format;
    char c;
    char* str;
    int length;

    va_start(args, format);
    while (*current != '\0') {
        if (*current == '%') {
            current++;
            if (*current == '\0')
                break;
            else if (*current == 'c') {
                c = (char)va_arg(args, int);
                custom_putchar(c);
                count++;
            } else if (*current == 's') {
                str = va_arg(args, char*);
                length = custom_strlen(str);
                custom_write(str, length);
                count += length;
            } else if (*current == 'd' || *current == 'i') {
                print_formatted_integer(format, args);
                count++;
            } else if (*current == '%') {
                custom_putchar('%');
                count++;
            }
        } else {
            custom_putchar(*current);
            count++;
        }
        current++;
    }

    va_end(args);

    return count;
}
