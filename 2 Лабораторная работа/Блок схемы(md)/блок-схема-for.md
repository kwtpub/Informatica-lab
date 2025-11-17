# Блок-схема программы с циклом FOR

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
    
    CheckDEL -->|Нет| ForInit[FOR: x = A]
    ForInit --> ForCondition{x ≤ B?}
    
    ForCondition -->|Нет| End2([Конец])
    ForCondition -->|Да| OutputX[Вывод x]
    
    OutputX --> Cond1{x < 0.6 AND<br/>b + c ≠ 0?}
    Cond1 -->|Да| Calc1[F = a×x³ + b² + c]
    Calc1 --> Output1[Вывод F,<br/>Номер формулы: 1]
    Output1 --> ForIncrement
    
    Cond1 -->|Нет| Cond2{x > 0.6 AND<br/>b + c = 0?}
    Cond2 -->|Да| Calc2[F = x - a × x - c]
    Calc2 --> Output2[Вывод F,<br/>Номер формулы: 2]
    Output2 --> ForIncrement
    
    Cond2 -->|Нет| Cond3{a ≠ 0 AND<br/>c ≠ 0?}
    Cond3 -->|Да| Calc3[F = x/c + x/a]
    Calc3 --> Output3[Вывод F,<br/>Номер формулы: 3]
    Output3 --> ForIncrement
    
    Cond3 -->|Нет| Error3[Вывод: Деление на 0,<br/>Номер формулы: 3]
    Error3 --> ForIncrement
    
    ForIncrement[FOR: x = x + DEL] --> ForCondition
```

## Как визуализировать:
1. Скопируйте код выше
2. Откройте https://mermaid.live/
3. Вставьте код в редактор
4. Экспортируйте в PNG или SVG

## Особенность FOR:
- Инициализация, условие и инкремент объединены в заголовке цикла
- `for (x = A; x <= B; x += DEL)`
- Условие проверяется ДО выполнения тела цикла

