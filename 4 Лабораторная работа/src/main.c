#include <stdio.h> // для функций printf, scanf
#include <stdlib.h> // для функций malloc, free, rand, srand
#include <time.h> // для функции time

typedef struct { 
    long long comparisons; // для подсчета количества сравнений
    long long swaps; // для подсчета количества перестановок
} SortStats;

// Прототипы функций
void copyArray(int *src, int *dst, int n);
void simpleSort(int *arr, int n);

// Пузырьковая сортировка
SortStats bubbleSort(int *arr, int n, int showSteps) {
    SortStats stats = {0, 0}; 
    int i, j, temp, swapped; 
    
    if (showSteps) {
        printf("\nИсходный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; 
        for (j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats.swaps++;
                swapped = 1;
            }
        }
        if (showSteps) {
            printf("Шаг %2d: ", i + 1);
            for (j = 0; j < n; j++) printf("%4d ", arr[j]);
            printf("\n");
        }
        if (!swapped) break;
    }
    
    if (showSteps) {
        printf("Отсортированный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    return stats;
}

// Сортировка выбором
SortStats selectionSort(int *arr, int n, int showSteps) { 
    SortStats stats = {0, 0};
    int i, j, minIndex, temp;
    
    if (showSteps) {
        printf("\nИсходный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            stats.comparisons++;
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            stats.swaps++;
        }
        if (showSteps) {
            printf("Шаг %2d: ", i + 1);
            for (j = 0; j < n; j++) printf("%4d ", arr[j]); 
            printf("\n");
        }
    }
    
    if (showSteps) {
        printf("Отсортированный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    return stats;
}

// Сортировка вставкой
SortStats insertionSort(int *arr, int n, int showSteps) {
    SortStats stats = {0, 0};
    int i, j, key;
    
    if (showSteps) {
        printf("\nИсходный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (showSteps) {
            printf("Шаг %2d: ", i);
            for (j = 0; j < n; j++) printf("%4d ", arr[j]);
            printf("\n");
        }
    }
    
    if (showSteps) {
        printf("Отсортированный массив: ");
        for (i = 0; i < n; i++) printf("%4d ", arr[i]);
        printf("\n");
    }
    
    return stats;
}

// Простая сортировка для подготовки массивов (без подсчета статистики) 
void simpleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Генерация массивов 
void generateArrays(int *randomArr, int *sortedArr, int *reverseArr, int n) {
    int i;
    // Генерируем случайный массив
    for (i = 0; i < n; i++) {
        randomArr[i] = rand() % 1000;
    }
    // Копируем и сортируем для получения отсортированного массива
    copyArray(randomArr, sortedArr, n);
    simpleSort(sortedArr, n);
    // Создаем обратный массив из отсортированного
    for (i = 0; i < n; i++) {
        reverseArr[i] = sortedArr[n - 1 - i];
    }
}

// Копирование массива
void copyArray(int *src, int *dst, int n) {
    int i;
    for (i = 0; i < n; i++) dst[i] = src[i];
}

// Тестирование одного алгоритма
typedef SortStats (*SortFunc)(int*, int, int);

void testSort(const char *name, SortFunc sortFunc, int *src, int n, int showSteps) {
    int *arr = (int*)malloc(n * sizeof(int));
    copyArray(src, arr, n);
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║ %-58s ║\n", name);
    printf("╚════════════════════════════════════════════════════════════╝\n");
    SortStats stats = sortFunc(arr, n, showSteps);
    
    printf("\n┌──────────────────────────────────────────────────────────┐\n");
    printf("│ Статистика:                                                │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ Количество сравнений:    %20lld │\n", stats.comparisons);
    printf("│ Количество перестановок: %20lld │\n", stats.swaps);
    printf("└──────────────────────────────────────────────────────────┘\n");
    
    free(arr);
}

// Тестирование для одного размера
void testSize(int n) {
    int *randomArr, *sortedArr, *reverseArr;
    int showSteps = (n == 10);
    
    randomArr = (int*)malloc(n * sizeof(int));
    sortedArr = (int*)malloc(n * sizeof(int));
    reverseArr = (int*)malloc(n * sizeof(int));
    
    generateArrays(randomArr, sortedArr, reverseArr, n);
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                    РАЗМЕР МАССИВА: %-5d                    ║\n", n);
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    // Пузырьковая сортировка 
    testSort("Пузырьковая сортировка - Случайная последовательность", 
             bubbleSort, randomArr, n, showSteps);
    testSort("Пузырьковая сортировка - Отсортированная (возрастание)", 
             bubbleSort, sortedArr, n, showSteps);
    testSort("Пузырьковая сортировка - Отсортированная (убывание)", 
             bubbleSort, reverseArr, n, showSteps);
    
    // Выбором
    testSort("Сортировка выбором - Случайная последовательность", 
             selectionSort, randomArr, n, showSteps);
    testSort("Сортировка выбором - Отсортированная (возрастание)", 
             selectionSort, sortedArr, n, showSteps);
    testSort("Сортировка выбором - Отсортированная (убывание)", 
             selectionSort, reverseArr, n, showSteps);
    
    // Вставкой
    testSort("Сортировка вставкой - Случайная последовательность", 
             insertionSort, randomArr, n, showSteps);
    testSort("Сортировка вставкой - Отсортированная (возрастание)", 
             insertionSort, sortedArr, n, showSteps);
    testSort("Сортировка вставкой - Отсортированная (убывание)", 
             insertionSort, reverseArr, n, showSteps);
    
    free(randomArr);
    free(sortedArr);
    free(reverseArr);
}

// Быстрое тестирование (без шагов)
void quickTest(const char *name, SortFunc sortFunc, int *src, int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    copyArray(src, arr, n);
    SortStats stats = sortFunc(arr, n, 0);
    printf("│ %-25s │ сравнений: %12lld │ перестановок: %12lld │\n", 
           name, stats.comparisons, stats.swaps);
    free(arr);
}

// Дополнительное тестирование для больших размеров
void testAdditionalSizes(int originalN) {
    if (originalN == 100 || originalN == 1000 || originalN == 10000) return;
    
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║              ДОПОЛНИТЕЛЬНОЕ ТЕСТИРОВАНИЕ                  ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    int sizes[] = {100, 1000, 10000};
    int i, j, n;
    
    for (i = 0; i < 3; i++) {
        n = sizes[i];
        int *randomArr = (int*)malloc(n * sizeof(int));
        int *sortedArr = (int*)malloc(n * sizeof(int));
        int *reverseArr = (int*)malloc(n * sizeof(int));
        
        generateArrays(randomArr, sortedArr, reverseArr, n);
        
        printf("\n");
        printf("╔════════════════════════════════════════════════════════════╗\n");
        printf("║                    РАЗМЕР МАССИВА: %-5d                    ║\n", n);
        printf("╠════════════════════════════════════════════════════════════╣\n");
        printf("║ Алгоритм              │ Сравнений        │ Перестановок    ║\n");
        printf("╠════════════════════════╪══════════════════╪═════════════════╣\n");
        quickTest("Пузырьковая - Случайная", bubbleSort, randomArr, n);
        quickTest("Пузырьковая - Возрастание", bubbleSort, sortedArr, n);
        quickTest("Пузырьковая - Убывание", bubbleSort, reverseArr, n);
        quickTest("Выбором - Случайная", selectionSort, randomArr, n);
        quickTest("Выбором - Возрастание", selectionSort, sortedArr, n);
        quickTest("Выбором - Убывание", selectionSort, reverseArr, n);
        quickTest("Вставкой - Случайная", insertionSort, randomArr, n);
        quickTest("Вставкой - Возрастание", insertionSort, sortedArr, n);
        quickTest("Вставкой - Убывание", insertionSort, reverseArr, n);
        printf("╚════════════════════════════════════════════════════════════╝\n");
        
        free(randomArr);
        free(sortedArr);
        free(reverseArr);
    }
}

int main() {
    int n;
    
    srand(time(NULL)); 
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║         ПРОГРАММА ТЕСТИРОВАНИЯ АЛГОРИТМОВ СОРТИРОВКИ       ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\nВведите размерность массива n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("\n╔════════════════════════════════════════════════════════════╗\n");
        printf("║  ОШИБКА: размерность должна быть положительным числом!     ║\n");
        printf("╚════════════════════════════════════════════════════════════╝\n");
        return 1;
    }
    
    testSize(n);
    testAdditionalSizes(n);
    
    return 0;
}
