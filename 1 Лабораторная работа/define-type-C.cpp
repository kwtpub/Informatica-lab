#include <stdio.h>

int main() 
{
  int intType;
  char charType;
  float floatType;
  double doubleType;

  printf("\nВведите значение переменной типа int: ");
  scanf("%d", &intType);
  printf("\nВведите значение переменной типа char: ");
  scanf(" %c", &charType);
 
  printf("\nВведите значение переменной типа float: ");
  scanf("\n%f", &floatType);
  printf("\nВведите значение переменной типа double: ");
  scanf("%lf", &doubleType);

  printf("\nВес переменной int: %lu ", sizeof(intType));
  printf("\nЗначение перменной int в как символ: %c", intType);
  printf("\nЗначение перменной int в дестиричной системме: %d", intType);
  printf("\nЗначение перменной int в восмеичной системме: %o", intType);
  printf("\nЗначение перменной int в шестнадцатиричной системме: %x", intType);
  
  printf("\nВес переменной char: %lu ", sizeof(charType));
  printf("\nЗначение перменной char в как символ: %c", charType);
  printf("\nЗначение перменной char в дестиричной системме: %d", charType);
  printf("\nЗначение перменной char в восмеичной системме: %o", charType);
  printf("\nЗначение перменной char в шестнадцатиричной системме: %x", charType);

  printf("\nВес переменной float: %lu ", sizeof(floatType));
  printf("\nВес переменной float: %f ", floatType);
  printf("\nВес переменной float: %e ", floatType);

  printf("\nВес переменной float: %.2f ", floatType);
  printf("\nВес переменной float: %.2e ", floatType);

  printf("\nВес переменной double: %lu \n", sizeof(doubleType));
  printf("\nВес переменной double: %f ", doubleType);
  printf("\nВес переменной double: %e ", doubleType);

  printf("\nВес переменной double: %.2f ", doubleType);
  printf("\nВес переменной double: %.2e ", doubleType);
  // %lu — это форматный спецификатор для вывода/ввода беззнакового целого типа unsigned long в C.
  return 0;
}
