#include "main.h"

void handle_S_conversion_specifier(char* string) {
    /* Get the length of the string. */
    int length = custom_strlen(string);
    int i;
    char hex[3];
    /* Allocate a buffer to hold the output. */
    char* output = (char*)malloc(length * 4 + 1);

    /* Loop through the string, converting each character to hexadecimal. */
    int outputIndex = 0;
    for (i = 0; i < length; i++) {
        if ((unsigned char)string[i] < 32 || (unsigned char)string[i] >= 128) {
            output[outputIndex++] = '\\';
            output[outputIndex++] = 'x';
            sprintf(hex, "%02X", (unsigned char)string[i]);
            output[outputIndex++] = hex[0];
            output[outputIndex++] = hex[1];
        } else {
            output[outputIndex++] = string[i];
        }
    }

    /* Write the output to stdout. */
    custom_write(output, outputIndex);

    /* Free the buffer. */
    free(output);
}
