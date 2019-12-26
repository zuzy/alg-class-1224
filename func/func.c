#include <stdio.h>
#include "func.h"

void dump(int list[], int size)
{
    int i;
    for(i = 0; i < size; ++i) {
        printf("\t%d", list[i]);
    }
    printf("\n");
}