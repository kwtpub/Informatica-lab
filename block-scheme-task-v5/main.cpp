#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void inputMatrixFromKeyboard(vector<vector<int>>& A, int n, int m) {
    cout << "\nВведите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}

void generateRandomMatrix(vector<vector<int>>& A, int n, int m, int min = 1, int max = 100) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void printMatrix(const vector<vector<int>>& A, const string& name) {
    cout << "\n" << name << ":\n";
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << setw(6) << A[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    
    // Ввод размеров матрицы
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;
    
    if (n <= 0 || m <= 0) {
        cout << "Ошибка: размеры матрицы должны быть положительными числами\n";
        return 1;
    }
    
    // Выбор способа ввода
    int choice;
    cout << "\nВыберите способ ввода:\n";
    cout << "1 - с клавиатуры\n";
    cout << "2 - случайным образом\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    
    // Создание матрицы
    vector<vector<int>> A(n, vector<int>(m));
    
    if (choice == 1) {
        inputMatrixFromKeyboard(A, n, m);
    } else if (choice == 2) {
        generateRandomMatrix(A, n, m);
    } else {
        cout << "Неверный выбор, используется случайная генерация\n";
        generateRandomMatrix(A, n, m);
    }
    
    // Вывод исходной матрицы
    printMatrix(A, "Исходная матрица A");
    
    // Обработка строк
    vector<int> B(n);
    
    for (int i = 0; i < n; i++) {
        // Инициализация max и min первым элементом строки
        int max = A[i][0];
        int min = A[i][0];
        
        // Поиск максимального и минимального элементов в строке
        for (int j = 1; j < m; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
        
        // Вычисление разности
        B[i] = max - min;
        
        // Вывод промежуточного результата
        cout << "\nСтрока " << i << ": max = " << max 
             << ", min = " << min << ", B[" << i << "] = " << B[i] << "\n";
    }
    
    // Вывод итогового массива B
    cout << "\nИтоговый массив B:\n";
    for (int i = 0; i < n; i++) {
        cout << B[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "\n";
    
    return 0;
}

