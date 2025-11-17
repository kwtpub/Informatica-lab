# Блок-схема программы с циклом DO-WHILE

```mermaid
flowchart TD
    Start([Начало]) --> Init[Инициализация:<br/>A = 0, B = 0, DEL = 0<br/>a = 0, b = 0, c = 0<br/>x = 0, F = 0]
    Init --> InputA[Ввод A]
    InputA --> InputB[Ввод B]
    InputB --> InputDEL[Ввод DEL]
    InputDEL --> InputLowA[Ввод a]
    InputLowA --> InputLowB[Ввод b]
    InputLowB --> InputLowC[Ввод c]
    
    InputLowC --> CheckDEL{DEL = 0?}
    CheckDEL -->|Да| Error[Вывод: Шаг не должен<br/>быть равным 0]
    Error --> End1([Конец])
    
    CheckDEL -->|Нет| InitX[x = A]
    InitX --> PreCheck{x ≤ B?}
    PreCheck -->|Нет| End2([Конец])
    
    PreCheck -->|Да| DoStart[DO:]
    DoStart --> OutputX[Вывод x]
    
    OutputX --> Cond1{x < 0.6 AND<br/>b + c ≠ 0?}
    Cond1 -->|Да| Calc1[F = a×x³ + b² + c]
    Calc1 --> Output1[Вывод F,<br/>Номер формулы: 1]
    Output1 --> IncrementX
    
    Cond1 -->|Нет| Cond2{x > 0.6 AND<br/>b + c = 0?}
    Cond2 -->|Да| Calc2[F = x - a × x - c]
    Calc2 --> Output2[Вывод F,<br/>Номер формулы: 2]
    Output2 --> IncrementX
    
    Cond2 -->|Нет| Cond3{a ≠ 0 AND<br/>c ≠ 0?}
    Cond3 -->|Да| Calc3[F = x/c + x/a]
    Calc3 --> Output3[Вывод F,<br/>Номер формулы: 3]
    Output3 --> IncrementX
    
    Cond3 -->|Нет| Error3[Вывод: Деление на 0,<br/>Номер формулы: 3]
    Error3 --> IncrementX
    
    IncrementX[x = x + DEL] --> DoWhileCondition{WHILE:<br/>x ≤ B?}
    DoWhileCondition -->|Да| DoStart
    DoWhileCondition -->|Нет| End3([Конец])
```

## Как визуализировать:
1. Скопируйте код выше
2. Откройте https://mermaid.live/
3. Вставьте код в редактор
4. Экспортируйте в PNG или SVG

## Особенность DO-WHILE:
- Тело цикла выполняется минимум 1 раз
- Условие проверяется ПОСЛЕ выполнения тела цикла
- В коде есть предварительная проверка `if (x <= B)` перед входом в do-while

