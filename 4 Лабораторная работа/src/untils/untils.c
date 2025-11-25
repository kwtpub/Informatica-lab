#include <stdlib.h>
#include "untils.h"

void generateArrays(int *randomArr, int *sortedArr, int *reverseArr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        randomArr[i] = rand() % 1000;
        sortedArr[i] = i;
        reverseArr[i] = n - i;
    }
}
