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

void copyArray(int *src, int *dst, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void insertionSort(int *arry, int n, int showSteps) {
    int *arr = (int *)malloc(n * sizeof(int));
    copyArray(arry, arr, n);
    printf("Сортировка вставкой\n");
    int comparisons = 0, swaps = 0; 
    int j, key;
    
    if (showSteps) {
        printf("\tИсходный массив: ");
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
            printf("\tШаг %d: ", i);
            for (j = 0; j < n; j++) printf("%d ", arr[j]);
            printf("\n");
        }
    }
    
    if (showSteps) {
        printf("\tОтсортированный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    printf("\tКоличество сравнений: %d\n", comparisons);
    printf("\tКоличество перестановок: %d\n", swaps);
}


void bubbleSort(int *arry, int n, int showSteps) {
    int *arr = (int *)malloc(n * sizeof(int));
    copyArray(arry, arr, n);
    int i,j,buf;
    int comparisons = 0, swaps = 0;
    printf("Сортировка пузырьком\n");
    if(showSteps) {
        printf("\tИсходный массив: ");
        for(i = 0; i < n; i++)
            printf(" %d", arr[i]);
        printf("\n\n");
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swaps++;
                buf = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buf;
            }
        }
        if(showSteps) {
            printf("\tШаг %d: ", i + 1);
            for(j = 0; j < n; j++)
                printf("%d ", arr[j]);
            printf("\n");
        }
    }

    if (showSteps) {
        printf("\tОтсортированный массив: ");
        for (i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n\n");
    }
    printf("\tКоличество сравнений: %d\n", comparisons);
    printf("\tКоличество перестановок: %d\n", swaps);
}

void selectionSort(int *arry, int n, int showSteps) {
    int *arr = (int *)malloc(n * sizeof(int));
    copyArray(arry, arr, n);
    printf("Сортировка выбором \n");
    int temp;
    int comparisons = 0, swaps = 0;
    if (showSteps) {
        printf("\tИсходный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
        if (showSteps) {
            printf("\tШаг %d: ", i + 1);
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
    }
    
    if (showSteps) {
        printf("\tОтсортированный массив: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    printf("\tКоличество сравнений: %d\n", comparisons);
    printf("\tКоличество перестановок: %d\n", swaps);
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
    insertionSort(randomArr, n, 1); 
    bubbleSort(randomArr, n, 1);
    selectionSort(randomArr, n, 1);

}