#include <stdio.h>

int main() {

    int primos[1000];
    int i, j;

    // passo 1: colocar 1 em todos
    for(i = 0; i < 1000; i++) {
        primos[i] = 1;
    }

    // ignorar 0 e 1
    primos[0] = 0;
    primos[1] = 0;

    // crivo de Eratóstenes
    for(i = 2; i < 1000; i++) {
        if(primos[i] == 1) {
            for(j = i * 2; j < 1000; j += i) {
                primos[j] = 0;
            }
        }
    }

    // mostrar os números primos
    printf("Numeros primos entre 2 e 999:\n");

    for(i = 2; i < 1000; i++) {
        if(primos[i] == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}

