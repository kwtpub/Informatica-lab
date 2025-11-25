#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateArrays(int *randomArr, int *sortedArr, int *reverseArr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        randomArr[i] = rand() % 1000;
        sortedArr[i] = i;
        reverseArr[i] = n - i;
    }
}



// Пузырьковая сортировка

void bubbleSort(int *arr, int n, int showSteps) {
    int i,j,buf, swapped, counter1 = 0, counter2 = 0;
    printf("Сортировка пузырьком\n");
    if(showSteps) {
        printf("\tИсходный массив: ");
        for(i = 0; i < n; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            counter1++;
            if(arr[j] > arr[j+1]) {
                counter2++;
                buf = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buf;
            }
            if(showSteps) {
                printf("\tШаг %d: ", i + 1);
                for(j = 0; j < n; j++)
                    printf("%d ", arr[j]);
                printf("\n");
            }
        }
    }

    if (showSteps) {
        printf("\tОтсортированный массив: ");
        for (i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
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
    bubbleSort(randomArr, n, 1);
    return 0;
}