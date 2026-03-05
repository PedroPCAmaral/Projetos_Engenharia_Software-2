#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    int a = 1, b = 1, c;

    printf("Digite um numero (n >= 3): ");
    scanf("%d", &n);

    for(i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    printf("O %d-esimo termo da serie de Fibonacci eh: %d\n", n, b);

    return 0;
}

