#include <stdio.h>


void frac(float num, int *inteiro, float *frac) {
    *inteiro = (int)num;
    *frac = num - *inteiro;
}

int main() {
    float num = 5.75;
    int parte_inteira;
    float parte_fracionaria;

    frac(num, &parte_inteira, &parte_fracionaria);

    printf("Numero: %.2f\n", num);
    
	printf("Parte inteira: %d\n", parte_inteira);
    
	printf("Parte fracionaria: %.2f\n", parte_fracionaria);

    
	return 0;
}
