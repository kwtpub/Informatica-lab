#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>



const int SIZE =  5;  // количество элементов в массиве (константа)


int main() 
{



    int arr[SIZE];

    int i;           // переменная-итератор основного цикла
    int j;           // переменная-итератор внутреннего цикла
    int choice;      // переменная для хранения выбора режима работы
    int A;           // искомое значение для поиска
    int INC_A;       // позиция найденного элемента в массиве
    int sum;         // накопитель суммы элементов
    int min_nechet;  // наименьшее нечетное значение
    int sort_pr;     // буферная переменная для обмена элементов


    // Установка начального значения для генерации псевдослучайных чисел
    srand(time(NULL));
    
    printf("────────── Working with one-dimensional array ──────────\n\n");
    
    // Определение метода заполнения массива данными
    printf("Specify array filling method:\n");
    printf("[1] Manual keyboard input\n");
    printf("[2] Random value generation\n");
    printf("Enter number: ");
    scanf("%d", &choice);
    
    // Процесс заполнения массива
    if (choice == 1) 
    {
        // Режим ручного ввода значений
        printf("\nEnter %d numbers:\n", SIZE);
        for (i = 0; i < SIZE; i++) 
        {
            printf("Number %d: ", i + 1); // i+1 для удобства пользователя (нумерация с единицы)
            scanf("%d", &arr[i]); // сохранение введенного значения в ячейку массива
        }
        printf("\n");
        // Отображение введенных данных
        printf("Array address: %p\n", arr);
        printf("Original array: \n");
        for (i = 0; i < SIZE; i++) 
        {
            printf("arr[%d] = %d, address: %p\n", i, arr[i], &arr[i]); // вывод значения и адреса каждого элемента
        }
        printf("\n");
    } 
    else 
    {
        // Режим автоматической генерации
        printf("Generating random numbers.......\n");
        for (i = 0; i < SIZE; i++) 
        {
            arr[i] = rand() % 100;  // получение случайного числа в диапазоне 0-99
        }
        // Отображение сгенерированных значений 
        printf("Array address: %p\n", arr);
        printf("Array pointer, %d\n", *arr);
        printf("Size array %d\n", sizeof(arr));
        int *parr;
        parr = arr;
        printf("Pointer awrray: %p\n", parr);
        printf("link parr: %p\n", &parr);
        printf("link parr: %d\n", *parr);
        printf("size parr: %d", sizeof(parr));
        

        printf("\nOriginal array: ");
        for (i = 0; i < SIZE; i++) 
        {
            printf("arr[%d] = %d, address: %p\n", i, arr[i], &arr[i]); // вывод значения и адреса каждого элемента
        }
    }
    
    
    // Этап отображения исходных данных завершен




    // Шаг 1: Получение искомого значения
    printf("\nEnter number A: ");
    scanf("%d", &A);
    
    // Процесс поиска числа A в массиве
    INC_A = -1;  // установка начального значения (маркер отсутствия)
    for (i = 0; i < SIZE; i++) 
    {
        if (arr[i] == A) 
        {
            INC_A = i;  // фиксация индекса найденного элемента
            break;      // досрочное завершение цикла при успешном поиске
        }
    }
    
    // Шаг 2: Анализ результата поиска и дальнейшие действия
    if (INC_A != -1) 
    {
        printf("Number %d found at position %d\n", A, INC_A);
        
        // Вычисление суммы элементов, расположенных после найденного
        sum = 0;
        for (i = INC_A + 1; i < SIZE; i++) // итерация с элемента, следующего за найденным
        {
            sum += arr[i];
        }
        printf("Sum of elements after found A: %d\n", sum);
    } 
    else 
    {
        printf("Number %d not found in array\n", A);
        
        // Определение минимального нечетного элемента
        char flag = 0; // индикатор наличия нечетных чисел в массиве 
        min_nechet = 1000000;
        for (i = 0; i < SIZE; i++) 
        {
            if (arr[i] % 2 != 0) // определение нечетности через остаток деления
            {  
                if (arr[i] < min_nechet) // сравнение с текущим минимумом
                {
                    min_nechet = arr[i]; // обновление минимального значения
                    flag = 1; // активация флага при обнаружении нечетного числа
                }
            }
        }
        
        // Проверка результата поиска нечетных элементов
        if (flag == 1)  
        {
            printf("Minimum odd element: %d\n", min_nechet);    
        }
        else 
        {
            printf("No odd elements\n");
        }
    }
    
    // Шаг 3: Сортировка элементов массива по возрастанию (алгоритм "пузырька")
    for (i = 0; i < SIZE - 1; i++) 
    {
        for (j = 0; j < SIZE - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Обмен значениями между соседними элементами
                sort_pr = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = sort_pr;
            }
        }
    }
    printf("\n");
    // Отображение упорядоченного массива
    printf("Array address: %p\n", arr); // вывод начального адреса массива 
    printf("Sorted array: \n");
    for (i = 0; i < SIZE; i++) 
    {
        printf("arr[%d] = %d, address: %p\n", i, arr[i], &arr[i]); // вывод значения и адреса каждого элемента
    }
    printf("\n");
    
    return 0;
}

