int a[] = {10, 11, 12, 13, 14, 15};
int b[] = {10, 11, 12, 13, 14, 15};

int *pa = a, *pb = &b[5];

printf("\n\n &a=%p\t &pb=%p", &a, &pb);

for (int i = 0; i < 6; i++) {
    printf("\n &a[%d] = %p\t a[%d] = %d\t &b[%d] = %p\t b[%d] = %d",
           i, &a[i], i, a[i], i, &b[i], i, b[i]);
}

while (*pa < *pb) {
    printf("\n *pa = %d\t *pb = %d\t pa = %p\t pb = %p",
            *pa, *pb, pa, pb);
    pa++;
    pb--;
}

printf("\n\n pa=%p\t pb=%p", pa, pb);

