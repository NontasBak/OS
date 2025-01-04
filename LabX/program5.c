#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x = 1, y = 2, z = 3;
    int sum;

    sum = add(&x, &y, &z);
    printf("Sum: %d\n", sum);

    return 0;
}