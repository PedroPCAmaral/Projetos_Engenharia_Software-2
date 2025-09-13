#include <stdio.h>
#include <stdlib.h>
#include "pediatria.h"

void exibir_classificacao(IMCInfantil imc) {
    switch (imc) {
        case ABAIXO:
            printf("Classificação: Abaixo do peso\n");
            break;
        case NORMAL:
            printf("Classificação: Peso normal\n");
            break;
        case SOBREPESO:
            printf("Classificação: Sobrepeso\n");
            break;
        case OBESIDADE:
            printf("Classificação: Obesidade\n");
            break;
        default:
            printf("Classificação: Desconhecida\n");
    }
}

int main() {
    paciente_t *lista = primeiro_paciente("João", 10, 30.5, 1.35, 'M');
    novo_paciente(lista, "Maria", 12, 42.0, 1.45, 'F');
    novo_paciente(lista, "Carlos", 8, 50.0, 1.30, 'M');

    paciente_t *atual = lista;
    while (atual != NULL) {
        printf("Paciente: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);
        printf("Peso: %.2f kg\n", atual->peso);
        printf("Altura: %.2f m\n", atual->altura);

        IMCInfantil imc_classificacao = calcula_imc(atual);
        exibir_classificacao(imc_classificacao);

        atual = atual->prox;
        printf("\n");
    }

    return 0;
}