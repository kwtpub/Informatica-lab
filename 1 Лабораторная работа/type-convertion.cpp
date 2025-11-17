#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() 
{
    // Переменные для преобразования 1 
    char ch1;
    short int sh1;
    int i1;

    // Переменные для преобразования 2 
    unsigned char uch2;
    unsigned short int ush2;
    unsigned int ui2;

    // Преобразование signed
    ch1 = CHAR_MAX;
    sh1 = ch1;
    i1 = sh1;
    printf("CHAR -> SHORT_INT -> INT\n");
    printf("%d \t %d \t %d\n", ch1, sh1, i1);

    // Преобразование unsigned
    uch2 = UCHAR_MAX;
    ush2 = uch2;
    ui2 = ush2;
    printf("UNSIGNET CHAR -> UNSIGNET SHORT_INT -> UNSIGNET INT\n");
    printf("%u \t %u \t %u\n", uch2, ush2, ui2);
    // Преобразование больших signed
    i1 = INT_MAX;
    sh1 = i1;
    ch1 = sh1;
    printf("INT -> SHORT_INT -> CHAR\n");
    printf("%d \t %d \t %d\n", i1, sh1, ch1);

    // Преобразование больших unsigned
    ui2 = UINT_MAX;
    ush2 = ui2;
    uch2 = ush2;
    printf("UNSIGNET INT -> UNSIGNET SHORT_INT -> UNSIGNET CHAR\n");
    printf(" %u \t %u \t %u\n", ui2, ush2, uch2);

    printf("\n=== МИНИМАЛЬНЫЕ ЗНАЧЕНИЯ ===\n\n");

    // Преобразование минимальных signed
    ch1 = CHAR_MIN;
    sh1 = ch1;
    i1 = sh1;
    printf("CHAR_MIN -> SHORT_INT -> INT\n");
    printf("%d \t %d \t %d\n", ch1, sh1, i1);

    // Преобразование минимальных unsigned
    uch2 = 0;
    ush2 = uch2;
    ui2 = ush2;
    printf("UNSIGNET CHAR (0) -> UNSIGNET SHORT_INT -> UNSIGNET INT\n");
    printf("%u \t %u \t %u\n", uch2, ush2, ui2);

    // Преобразование минимальных больших signed
    i1 = INT_MIN;
    sh1 = i1;
    ch1 = sh1;
    printf("INT_MIN -> SHORT_INT -> CHAR\n");
    printf("%d \t %d \t %d\n", i1, sh1, ch1);

    // Преобразование минимальных больших unsigned
    ui2 = 0;
    ush2 = ui2;
    uch2 = ush2;
    printf("UNSIGNET INT (0) -> UNSIGNET SHORT_INT -> UNSIGNET CHAR\n");
    printf("%u \t %u \t %u\n", ui2, ush2, uch2);

    printf("\n=== ПРОИЗВОЛЬНЫЕ ЗНАЧЕНИЯ ===\n\n");

    // Преобразование произвольных signed
    ch1 = 50;
    sh1 = ch1;
    i1 = sh1;
    printf("CHAR (50) -> SHORT_INT -> INT\n");
    printf("%d \t %d \t %d\n", ch1, sh1, i1);

    // Преобразование произвольных unsigned
    uch2 = 200;
    ush2 = uch2;
    ui2 = ush2;
    printf("UNSIGNET CHAR (200) -> UNSIGNET SHORT_INT -> UNSIGNET INT\n");
    printf("%u \t %u \t %u\n", uch2, ush2, ui2);

    // Преобразование произвольных больших signed
    i1 = 100000;
    sh1 = i1;
    ch1 = sh1;
    printf("INT (100000) -> SHORT_INT -> CHAR\n");
    printf("%d \t %d \t %d\n", i1, sh1, ch1);

    // Преобразование произвольных больших unsigned
    ui2 = 70000;
    ush2 = ui2;
    uch2 = ush2;
    printf("UNSIGNET INT (70000) -> UNSIGNET SHORT_INT -> UNSIGNET CHAR\n");
    printf("%u \t %u \t %u\n", ui2, ush2, uch2);

    return 0;
}
