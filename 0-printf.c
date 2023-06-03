#include "main.h"

int _printf(const char* format, ...) {
    va_list args;
    int count = 0;
    const char* current = format;
    char c;
    char* str;
    int length;
    int is_negative = 0;

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
            } else if (*current == 'u' || *current == 'o' || *current == 'x' || *current == 'X') {
                handle_conversion_specifier(current, args);
                count++;
            } else if (*current == 'S') {
                str = va_arg(args, char*);
                handle_S_conversion_specifier(str);
                count++;
            } else if (*current == '+') {
                handle_plus_flag(&count, &is_negative);
            } else if (*current == ' ') {
                handle_space_flag(&count, is_negative);
            } else if (*current == '#') {
                handle_hash_flag(&count, current, args);
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
