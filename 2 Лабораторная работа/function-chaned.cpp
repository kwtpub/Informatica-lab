#include <stdio.h>
#include <locale.h>

void calculateF(double x, double a, double b, double c) {
    if (x < 0.6 && b + c != 0) {
        printf("F(x) = %lf, Номер формулы: 1", a*x*x*x + b*b + c);
    } else if (x > 0.6 && b + c == 0) {
        printf("F(x) = %lf, Номер формулы: 2", (x - a)*(x - c));
    } else {
        if (a != 0 && c != 0) {
            printf("F(x) = %lf, Номер формулы: 3", x/c + x/a);
        } else {
            printf("Деление на 0, Номер формулы: 3");
        }
    }
}


int main() {
    setlocale(LC_CTYPE, "");
    double A, B, DEL, a, b, c;

    printf("\nBвeдитe A: ");
    scanf("%lf", &A);
    printf("A = %lf", A);

    printf("\nBвeдитe B: ");
    scanf("%lf", &B);
    printf("B = %lf", B);

    printf("\nBвeдитe DEL: ");
    scanf("%lf", &DEL);
    printf("DEL = %lf", DEL);

    printf("\nBвeдитe a: ");
    scanf("%lf", &a);
    printf("a = %lf", a);

    printf("\nBвeдитe b: ");
    scanf("%lf", &b);
    printf("b = %lf", b);

    printf("\nBвeдитe c: ");
    scanf("%lf", &c);
    printf("c = %lf", c);

    if (DEL == 0.0){
        printf("\nШаг не должен быть равным 0");
        return 1;
    }

    printf("\nВыполняется while: ");
    double x = A;
    while (x <= B){
        printf("\nx = %lf, ", x);
        calculateF(x, a, b, c);
        x += DEL;
    }
    printf("\nВыполняется do while: ");
    x = A;
    if (x <= B){
    do{
        printf("\nx = %lf, ", x);
        calculateF(x, a, b, c);
        x += DEL;
    } while(x <= B);
    }

    printf("\nВыполняется for: ");
    for (x = A; x <= B; x += DEL){
        printf("\nx = %lf, ", x);
        calculateF(x, a, b, c);
    }
    return 0;
}