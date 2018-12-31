#include "roman_numerals.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Numeral {
    char symbol;
    struct Numeral *prefix;
    int val;
};

struct Numeral numerals[] = {
    { .symbol = 'I', .prefix = 0, .val = 1 },
    { .symbol = 'V', .prefix = &numerals[0], .val = 5 },
    { .symbol = 'X', .prefix = &numerals[0], .val = 10},
    { .symbol = 'L', .prefix = &numerals[2], .val = 50},
    { .symbol = 'C', .prefix = &numerals[2], .val = 100},
    { .symbol = 'D', .prefix = &numerals[4], .val = 500},
    { .symbol = 'M', .prefix = &numerals[4], .val = 1000},
    { .symbol = 'Z', .prefix = 0, .val = 999999}
};

char *to_roman_numeral(int i) {

    char *result = (char *)calloc(10, sizeof(char));
    char *ptr = result;

    while (i > 0) {
        for (size_t n = 1; n < sizeof(numerals); n++) {
            struct Numeral *num = &numerals[n];
            struct Numeral *prev = &numerals[n-1];

            // scan until we find a numeral larger than target
            if (num->val <= i) {
                continue;
            }

            // see if adding a prefix creates a value in the target range
            if (num->prefix != 0 && (num->val - num->prefix->val <= i)) {
                *ptr++ = num->prefix->symbol;
                *ptr++ = num->symbol;
                i -= num->val - num->prefix->val;
                break;
            }

            // else use the previous numeral and continue
            *ptr++ = prev->symbol;
            i -= prev->val;
            break;
        }
    }

    return result;
}

