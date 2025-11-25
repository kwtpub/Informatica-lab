#include <stdio.h>


int main()
{
    double A, B, DEL;
    double a, b, c;
    double F;
    printf("Введите число A:\n");
    scanf("%lf", &A);
    printf("Введите число B:\n");
    scanf("%lf", &B);
    printf("Введите число DEL:\n");
    scanf("%lf", &DEL);
    printf("Введите число a:\n");
    scanf("%lf", &a);
    printf("Введите число b:\n");
    scanf("%lf", &b);
    printf("Введите число c:\n");
    scanf("%lf", &c);
    printf("Результаты цикла for:\n");
    for (double x = A; x < B; x += DEL)
    {
        if (x + c < 0 && a != 0)
        {
            F = -a * x * x * x - b;
            printf("1. F(%lf) = %lf\n", x, F);
        }
        else if (x + c > 0 && a == 0 && x - c != 0)
        {
            F = (x - a) / (x - c);
            printf("2. F(%lf) = %lf\n", x, F);
        }
        else
        {
            F = x * c + x * b;
            printf("3. F(%lf) = %lf\n", x, F);
        }
    }
    printf("Результаты цикла while:\n");
    double x = A;
    while (x < B)
    {
        if (x + c < 0 && a != 0)
        {
            F = -a * x * x * x - b;
            printf("1. F(%lf) = %lf\n", x, F);
        }
        else if (x + c > 0 && a == 0 && x - c != 0)
        {
            F = (x - a) / (x - c);
            printf("2. F(%lf) = %lf\n", x, F);
        }
        else
        {
            F = x * c + x * b;
            printf("3. F(%lf) = %lf\n", x, F);
        }
        x += DEL;
    }
    printf("Результаты цикла do while:\n");
    x = A;
    do
    {
        if (x + c < 0 && a != 0)
        {
            F = -a * x * x * x - b;
            printf("1. F(%lf) = %lf\n", x, F);
        }
        else if (x + c > 0 && a == 0 && x - c != 0)
        {
            F = (x - a) / (x - c);
            printf("2. F(%lf) = %lf\n", x, F);
        }
        else
        {
            F = x * c + x * b;
            printf("3. F(%lf) = %lf\n", x, F);
        }
        x += DEL;
    } while (x < B);
    return 0;
}