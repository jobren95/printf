#include "main.h"

void handle_S_conversion_specifier(char* string) {
    int length = custom_strlen(string);
    int i;
    char* output = (char*)malloc(length * 4 + 1);
    int outputIndex = 0;

    for (i = 0; i < length; i++) {
        if ((unsigned char)string[i] < 32 || (unsigned char)string[i] >= 128) {
            output[outputIndex++] = '\\';
            output[outputIndex++] = 'x';
            custom_itoA((unsigned int)(unsigned char)string[i], output + outputIndex, 16);
            outputIndex += custom_strlen(output + outputIndex);
        } else {
            output[outputIndex++] = string[i];
        }
    }

    output[outputIndex] = '\0';
    custom_write(output, outputIndex);
    free(output);
}
