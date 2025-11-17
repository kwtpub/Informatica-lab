#include <stdio.h>
#include <limits.h>

int main() 
{
    int si1, si2;
    unsigned int ui1, ui2;

    printf("=== ЗАДАНИЕ 4: Переполнение при операциях ===\n\n");

    // signed int MAX -> signed int MAX+1
    si1 = INT_MAX;
    si2 = si1 + 1;
    printf("signed int MAX -> signed int MAX+1\n");
    printf("%d \t %d\n\n", si1, si2);

    // unsigned int MAX -> unsigned int MAX+1
    ui1 = UINT_MAX;
    ui2 = ui1 + 1;
    printf("unsigned int MAX -> unsigned int MAX+1\n");
    printf("%u \t %u\n\n", ui1, ui2);

    // signed int MIN -> signed int MIN-1
    si1 = INT_MIN;
    si2 = si1 - 1;
    printf("signed int MIN -> signed int MIN-1\n");
    printf("%d \t %d\n\n", si1, si2);

    // unsigned int MIN -> unsigned int MIN-1
    ui1 = 0;
    ui2 = ui1 - 1;
    printf("unsigned int MIN -> unsigned int MIN-1\n");
    printf("%u \t %u\n\n", ui1, ui2);

    return 0;
}

