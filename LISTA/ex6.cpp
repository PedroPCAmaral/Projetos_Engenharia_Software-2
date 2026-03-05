#include <stdio.h>
#include <math.h>

int main() {
    int inicio, fim, num, temp, digito, soma, n;

    printf("Digite o inicio do intervalo: ");
    scanf("%d", &inicio);

    printf("Digite o fim do intervalo: ");
    scanf("%d", &fim);

    for(num = inicio; num <= fim; num++) {
        temp = num;
        n = 0;
        soma = 0;

        // contar quantidade de digitos
        while(temp != 0) {
            temp = temp / 10;
            n++;
        }

        temp = num;

        // calcular soma das potencias
        while(temp != 0) {
            digito = temp % 10;
            soma = soma + pow(digito, n);
            temp = temp / 10;
        }

        // verificar se é Armstrong
        if(soma == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}

