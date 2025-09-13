#include <stdio.h>

int main() {
    int inteiro = 10;
    float real = 5.5;
    char caractere = 'A';

    int *ptr_inteiro = &inteiro;
    float *ptr_real = &real;
    char *ptr_caractere = &caractere;

    
    printf("Antes:\n");
    printf("Inteiro: %d, Real: %.2f, Char: %c\n", inteiro, real, caractere);

    
    *ptr_inteiro = 20;
    *ptr_real = 10.5;
    *ptr_caractere = 'B';

    
    printf("Depois:\n");
    printf("Inteiro: %d, Real: %.2f, Char: %c\n", inteiro, real, caractere);

    return 0;
}