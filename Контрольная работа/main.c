#include <stdio.h>


int main() {
// вариант 2   ЗАДАЧА 1
int x[4] = {11, 22, 33, 44};
int *p;
int y;
printf("\n adress x=%p", x);
printf("\n\n Адреса и значения элементов массива:\n\n");
for (int i = 0; i < 4; i++) {
    printf("\n &x[%d] = %p\t x[%d] = %d", i, &x[i], i, x[i]);
}

printf("\n\n3) adress &p = %p", &p);
p = &x[0];   // p равно адресу элемента x[0]
printf("\n значение *p = %d", *p);
printf("\n\n3) значение указателя p=*p;  p = %p", p);
printf("\n\n1) значение y = (*p)++;  p равно %p", p);
y = (*p)++;
printf("\n y = %d", y);
printf("\n p = %p", p);
printf("\n *p = %d", *p);

// printf("\n\n2) значение y = *(++p)++;   p равно %p", p);
// y = *((++p)++);
printf("\n y = %d", y);

printf("\n\n3) значение y = ++*p++;   p равно %p", p);
y = ++*p++;
printf("\n y = ???");

printf("\n p = %p", p);
printf("\n *p = %d", *p);

printf("\n\n4) значение y = *p;   p равно %p", p);
y = *p;
printf("\n y = %d", y);
printf("\n p = %p", p);
printf("\n *p = %d", *p);

printf("\n\n5) значение y = *p--;   p равно %p", p);
y = *p--;
printf("\n y = %d", y);
printf("\n p = %p", p);
printf("\n *p = %d", *p);

printf("\n\n6) значение y = *p++;   p равно %p", p);
y = *p++;
printf("\n y = %d", y);
printf("\n p = %p", p);
printf("\n *p = %d", *p);

printf("\n\n7) значение y = --(*p);   p равно %p", p);
y = --(*p);
printf("\n y = %d", y);
printf("\n p = %p", p);
printf("\n *p = %d", *p);

printf("\n\nАдреса и значения элементов массива:");
for (int i = 0; i < 4; i++) {
    printf("\n &x[%d] = %p\t x[%d] = %d", i, &x[i], i, x[i]);
}
}
