#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateArrays(int *randomArr, int *sortedArr, int *reverseArr, int n) {
    for (int i = 0; i < n; i++) {
        randomArr[i] = rand() % 1000;
        sortedArr[i] = i;
        reverseArr[i] = n - i;
    }
}


void insertionSort(int *arr, int n, int showSteps) {
    printf("Сортировка вставкой\n");
    int comparisons = 0, swaps = 0; 
    int j, key;
    
    if (showSteps) {
        printf("    Исходный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (showSteps) {
            printf("    Шаг %d: ", i);
            for (j = 0; j < n; j++) printf("%d ", arr[j]);
            printf("\n");
        }
    }
    
    if (showSteps) {
        printf("    Отсортированный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    printf("    Количество сравнений: %d\n", comparisons);
    printf("    Количество перестановок: %d\n", swaps);
}


// void bubbleSort(int *arr, int n, int showSteps) {
//     int i,j,temp, swapped;
//     if(showSteps) {
//         printf("Исходный массив: ");
//         for(i = 0)
//     }
// }



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
    insertionSort(randomArr, n, 1); 

}