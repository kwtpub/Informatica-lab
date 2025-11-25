flowchart TD
    %% --- Первое фото ---
    A[начало] --> B[size = 5
arr #91;size#93;
i = 0
j = 0
choice = 0
A = 0
INC_A = 0
sum = 0
min_nechet = 0
sort_pr = 0]
    B --> C[choice]
    C --> D["ввод"]
    C --> E{choice == 1}
    E --> |нет|F[ arr #91;i#93; = rand % 100]
    F --> G["генерация случайных чисел"]
    E -->|да| H[arr#91;#93;]
    H --> I["ввод"]
    F --> J[A]
    H --> J
    J --> K["ввод"]
    K --> L[INC_A = -1]
    L --> M["-1 значит 'не найдено'"]

    %% --- Третье фото: Поиск A в массиве ---
    subgraph Поиск_A
        N[i < SIZE] -->|нет| O
        N -->|да| P[arr#91;i#93; == A]
        P -->|нет| Q[i = i + 1]
        P -->|да| R[INC_A = i]
        Q --> N
        R --> O
    end

    %% --- Второе фото: Суммирование и поиск min нечётного ---
    L --> S{INC_A != -1}
    S -->|да| T[sum = 0]
    T --> U[i < SIZE]
    U -->|да| V[sum += arr#91;i#93;]
    V --> W[i = i + 1]
    W --> U
    U -->|нет| X
    S -->|нет| Y[flag = 0
min_nechet = 1000000]
    Y --> Z[i < SIZE]
    Z -->|да| AA[arr#91;i#93; % 2 != 0]
    AA -->|нет| AB[i = i + 1]
    AA -->|да| AC[arr#91;i#93; < min_nechet]
    AC -->|нет| AD[i = i + 1]
    AC -->|да| AE[min_nechet = arr#91;i#93;
flag = 1]
    AB --> Z
    AD --> Z
    AE --> Z
    Z -->|нет| AF

    %% --- Четвертое фото: Выводы и сортировка ---
    AF --> AG[flag == 1]
    AG -->|да| AH[min_nechet]
    AG -->|нет| AI["Нечетных элементов нет"]
    AH --> AJ["вывод"]
    AI --> AJ
    AF --> AK[i < SIZE - 1]
    AK -->|нет| AL[arr]
    AK -->|да| AM[j < SIZE - i - 1]
    AM -->|нет| AN[arr]
    AM -->|да| AO[arr#91;j#93; > arr#91;j + 1#93;]
    AO -->|нет| AP[j = j + 1]
    AO -->|да| AQ[sort_pr = arr#91;j#93;
arr#91;j#93; = arr#91;j + 1#93
arr#91;j + 1#93; = sort_pr
]
    AP --> AM
    AQ --> AM
    AM --> AK
    AL --> AR["вывод отсортированного массива"]
    AR --> AS[конец]


