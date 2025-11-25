#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>


#define SIZE 5  // определение размерности массива (макрос)


int main() 
{
    // настройка кодировки консоли для корректного отображения
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);


    int arr[SIZE];
    int i, j, choice, A, INC_A, sum, min_nechet, temp;
    int *ptr = arr; // объявление указателя на массив (ptr хранит адрес первого элемента)
    
    // Установка начального значения для генерации псевдослучайных чисел
    srand(time(NULL));
    
    printf("=== ARRAY PROCESSING PROGRAM (POINTERS) ===\n\n");
    
    // Определение метода ввода данных в массив
    printf("Select array filling method:\n");
    printf("1 - Keyboard input\n");
    printf("2 - Random numbers\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    // Инициализация массива посредством указателя
    //ptr = arr; // Присвоение адреса начала массива (аналогично &arr[0]) 
    
    if (choice == 1) 
    {
        // Режим пользовательского ввода с применением указателей
        printf("\nEnter %d numbers:\n", SIZE);
        for (i = 0; i < SIZE; i++) 
        {
            printf("Number %d: ", i + 1);
            scanf("%d", ptr + i); // запись по адресу (ptr + i) соответствует &arr[i]
        }
        printf("\n");
        
        // Отображение введенных значений посредством указателей
        printf("Array address: %p\n", ptr); // вывод базового адреса массива через указатель
        printf("Original array: \n");
        for (i = 0; i < SIZE; i++) 
        {
            printf("arr[%d] = %d, address: %p\n", i, *(ptr + i), ptr + i); // доступ к значению через разыменование
        }
        printf("\n");
    } 
    else 
    {
        // Автоматическая генерация значений с использованием указателей
        printf("Generating random numbers.......\n");
        for (i = 0; i < SIZE; i++) 
        {
            *(ptr + i) = rand() % 100;  // присваивание через операцию разыменования
        }
        
        // Отображение сгенерированных данных через указатели
        printf("Array address: %p\n", ptr);  







    
        printf("\nOriginal array: \n");
        for (i = 0; i < SIZE; i++) 
        {
            printf("arr[%d] = %d, address: %p\n", i, *(ptr + i), ptr + i);
        }
    }
    
    // Завершение этапа вывода исходных данных


    // Шаг 1: Получение искомого значения от пользователя
    printf("\nEnter number A: ");
    scanf("%d", &A);
    
    // Алгоритм поиска заданного числа посредством указателей
    INC_A = -1;  // инициализация индикатора отсутствия элемента
    for (i = 0; i < SIZE; i++) 
    {
        if (*(ptr + i) == A)  // сравнение через операцию разыменования
        {
            INC_A = i;  // сохранение индекса обнаруженного элемента
            break;      // прерывание итерации при успешном обнаружении
        }
    }
    
    // Шаг 2: Выполнение операций в зависимости от результата поиска
    if (INC_A != -1) 
    {
        printf("Number %d found at position %d\n", A, INC_A);
        
        // Подсчет суммы элементов, следующих за найденным (через указатели)
        sum = 0;
        for (i = INC_A + 1; i < SIZE; i++) // старт с позиции, следующей за обнаруженной
        {
            sum += *(ptr + i);  // добавление значения через разыменование
        }
        printf("Sum of elements after found A: %d\n", sum);
    } 
    else 
    {
        printf("Number %d not found in array\n", A);
        
        // Определение наименьшего нечетного элемента с применением указателей
        char flag = 0;
        min_nechet = 1000000;
        for (i = 0; i < SIZE; i++) 
        {
            if (*(ptr + i) % 2 != 0)  // проверка нечетности через разыменование
            {  
                if (*(ptr + i) < min_nechet)  // сравнение значений через указатель
                {
                    min_nechet = *(ptr + i);  // обновление минимума через разыменование
                    flag = 1;
                }
            }
        }
        
        // Анализ флага для определения наличия нечетных чисел
        if (flag == 1)  
        {
            printf("Minimum odd element: %d\n", min_nechet);    
        }
        else 
        {
            printf("No odd elements\n");
        }
    }
    
    // Шаг 3: Упорядочивание массива методом "пузырька" с использованием указателей
    for (i = 0; i < SIZE - 1; i++) 
    {
        for (j = 0; j < SIZE - i - 1; j++) 
        {
            if (*(ptr + j) > *(ptr + j + 1))  // сопоставление соседних элементов через разыменование
            {
                // Процесс обмена значений между смежными элементами
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    
    printf("\n");
    // Отображение упорядоченного массива посредством указателей
    printf("Array address: %p\n", ptr);
    printf("Sorted array: \n");
    for (i = 0; i < SIZE; i++) 
    {
        printf("arr[%d] = %d, address: %p\n", i, *(ptr + i), ptr + i);
    }
    printf("\n");
    
    return 0;
}
