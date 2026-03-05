#include <stdio.h>

int main() {
    int numero;
    int d1, d2, d3, d4, d5;

    printf("Digite um numero de cinco digitos: ");
    scanf("%d", &numero);

    d1 = numero / 10000;
    d2 = (numero % 10000) / 1000;
    d3 = (numero % 1000) / 100;
    d4 = (numero % 100) / 10;
    d5 = numero % 10;

    printf("%d   %d   %d   %d   %d\n", d1, d2, d3, d4, d5);

    return 0;
}

