import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function question(query: string): Promise<string> {
  return new Promise((resolve) => {
    rl.question(query, resolve);
  });
}

function getRandomInt(min: number, max: number): number {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

async function inputMatrixFromKeyboard(n: number, m: number): Promise<number[][]> {
  const matrix: number[][] = [];
  console.log('\nВведите элементы матрицы:');
  
  for (let i = 0; i < n; i++) {
    matrix[i] = [];
    for (let j = 0; j < m; j++) {
      const input = await question(`A[${i}][${j}] = `);
      matrix[i][j] = parseFloat(input);
    }
  }
  
  return matrix;
}

function generateRandomMatrix(n: number, m: number, min: number = 1, max: number = 100): number[][] {
  const matrix: number[][] = [];
  
  for (let i = 0; i < n; i++) {
    matrix[i] = [];
    for (let j = 0; j < m; j++) {
      matrix[i][j] = getRandomInt(min, max);
    }
  }
  
  return matrix;
}

function printMatrix(matrix: number[][], name: string): void {
  console.log(`\n${name}:`);
  for (let i = 0; i < matrix.length; i++) {
    console.log(matrix[i].join('\t'));
  }
}

async function main(): Promise<void> {
  try {
    // Ввод размеров матрицы
    const nInput = await question('Введите количество строк n: ');
    const mInput = await question('Введите количество столбцов m: ');
    const n = parseInt(nInput, 10);
    const m = parseInt(mInput, 10);
    
    if (isNaN(n) || isNaN(m) || n <= 0 || m <= 0) {
      console.log('Ошибка: размеры матрицы должны быть положительными числами');
      rl.close();
      return;
    }
    
    // Выбор способа ввода
    const choice = await question('\nВыберите способ ввода:\n1 - с клавиатуры\n2 - случайным образом\nВаш выбор: ');
    
    let A: number[][];
    
    if (choice === '1') {
      A = await inputMatrixFromKeyboard(n, m);
    } else if (choice === '2') {
      A = generateRandomMatrix(n, m);
    } else {
      console.log('Неверный выбор, используется случайная генерация');
      A = generateRandomMatrix(n, m);
    }
    
    // Вывод исходной матрицы
    printMatrix(A, 'Исходная матрица A');
    
    // Обработка строк
    const B: number[] = [];
    
    for (let i = 0; i < n; i++) {
      // Инициализация max и min первым элементом строки
      let max = A[i][0];
      let min = A[i][0];
      
      // Поиск максимального и минимального элементов в строке
      for (let j = 1; j < m; j++) {
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
      console.log(`\nСтрока ${i}: max = ${max}, min = ${min}, B[${i}] = ${B[i]}`);
    }
    
    // Вывод итогового массива B
    console.log('\nИтоговый массив B:');
    console.log(B.join(', '));
    
  } catch (error) {
    console.error('Ошибка:', error);
  } finally {
    rl.close();
  }
}

main();
