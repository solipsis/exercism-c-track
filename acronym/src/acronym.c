#include "acronym.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

char *abbreviate(const char *phrase) {

    if (phrase == NULL || strlen(phrase) == 0) {
        return NULL;
    }

    // Worst case result size is n/2 + 1 + null terminator
    int size = (strlen(phrase)/2) + 1 + 1;
    char *result = calloc(size, sizeof(char));

    int i = 0;
    bool append = true;
    for (;*phrase != '\0'; phrase++) {

        // detect separators
        if (*phrase == ' ' || *phrase == '-') {
            append = true;
            continue; // continue in case multiple spaces consecutively
        }

        // append first character of word
        if (append) {
            char c = toupper(*phrase);
            result[i++] = c;
            append = false;
        }
    }

    return result;
}
