#include <stdio.h>
#include "main.h"

int main(void) {
    int count1, count2;

    /* Test %c specifier */
    count1 = _printf("Character: %c\n", 'A');
    count2 = printf("Character: %c\n", 'A');
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %s specifier */
    count1 = _printf("String: %s\n", "Hello");
    count2 = printf("String: %s\n", "Hello");
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %d specifier */
    count1 = _printf("Decimal: %d\n", 12345);
    count2 = printf("Decimal: %d\n", 12345);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %i specifier */
    count1 = _printf("Integer: %i\n", -54321);
    count2 = printf("Integer: %i\n", -54321);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %% specifier */
    count1 = _printf("Percent sign: %%\n");
    count2 = printf("Percent sign: %%\n");
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %u specifier */
    count1 = _printf("Unsigned Decimal: %u\n", 4294967295);
    count2 = printf("Unsigned Decimal: %u\n", 4294967295);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %o specifier */
    count1 = _printf("Octal: %o\n", 01234567);
    count2 = printf("Octal: %o\n", 01234567);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %x specifier */
    count1 = _printf("Hexadecimal (lowercase): %x\n", 0xABCDEF);
    count2 = printf("Hexadecimal (lowercase): %x\n", 0xABCDEF);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %X specifier */
    count1 = _printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
    count2 = printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    /* Test %S specifier */
    count1 = _printf("Special String: %S\n", "Best\tSchool");
    count2 = printf("Special String: %S\n", "Best\tSchool");
    printf("Count1: %d\nCount2: %d\n", count1, count2);

    return 0;
}
