#include <stdio.h>  
#include <locale.h> 
int main() {
    setlocale(LC_ALL, "");
    int a, b;
    printf("Введите a и b: ");
    scanf("%d %d", &a, &b);
    printf("___________________\n");
    printf("| a*b | a+b | a-b |\n");
    printf("-------------------\n");
    printf("| %d*%d | %d+%d | %d-%d |\n", a, b, a, b, a, b);
    printf("-------------------\n");
    printf("|  %d  |  %d  |  %d  |\n", a * b, a + b, a - b);
    printf("-------------------\n"); 
    return 0;
}