#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "untils/untils.h"



void bubbleSort(int *arr, int n, int showSteps) {
    int i,j,temp, swapped;
    if(showSteps) {
        printf("Исходный массив: ");
        for(i = 0)
    }
}



int main()
{
    srand(time(NULL)); // Создание сида рандомной генерации
    int n;
    printf("Введите n: "); // Ввод n
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("\nОшибка: размерность должна быть положительным числом!\n"); //Обработка ошибки ввода
        return 1;
    }
    // Создание массивов
    int *randomArr = (int *)malloc(n * sizeof(int));
    int *sortedArr = (int *)malloc(n * sizeof(int));
    int *reverseArr = (int *)malloc(n * sizeof(int));
    generateArrays(randomArr, sortedArr, reverseArr, n);
}