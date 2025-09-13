#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Antes da troca: A = %d, B = %d\n", a, b);
    troca(&a, &b);
    printf("Depois da troca: A = %d, B = %d\n", a, b);

    return 0;
}
