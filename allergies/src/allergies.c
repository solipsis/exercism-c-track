#include "allergies.h"
#include <stdlib.h>
#include <stdio.h>

const int MAX_ALLERGEN = 8;

bool is_allergic_to(allergen_t a, int score) {
    return score >= 1 << a;
}

void get_allergens(int score, allergen_list_t *list) {

    if (score > 1 << MAX_ALLERGEN) {
        score -= 1 << MAX_ALLERGEN;
    }

    allergen_t *allergens = calloc(MAX_ALLERGEN+1, sizeof(allergen_t));
    list->allergens = allergens;
    list->count = 0;

    for (int i = MAX_ALLERGEN; i >= 0; i--) {
        if (is_allergic_to(i, score)) {
            score -= 1 << i;
            *allergens++ = i;
            list->count++;
        }
    }
}
