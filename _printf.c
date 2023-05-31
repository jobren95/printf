#include "main.h"
void custom_write(const char* str, int length)
{
    int i;
    for (i = 0; i < length; i++) {
        char c = str[i];
        write(STDOUT_FILENO, &c, 1);
    }
}
void custom_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

int custom_strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void custom_puts(const char* str)
{
    int length = custom_strlen(str);
    custom_write(str, length);
    custom_putchar('\n');
}

int _printf(const char* format, ...)
{
    va_list args;

    int count = 0;
    int i = 0;
    va_start(args, format);

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            if (format[i] == '\0')
                break;
            else if (format[i] == 'c') {
                char c = (char)va_arg(args, int);
                custom_putchar(c);
                count++;
            } else if (format[i] == 's') {
                char* str = va_arg(args, char*);
                int length = custom_strlen(str);
                custom_write(str, length);
                count += length;
            } else if (format[i] == '%') {
                custom_putchar('%');
                count++;
            }
        } else {
            custom_putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);

    return count;
}
