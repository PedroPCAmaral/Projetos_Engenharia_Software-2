#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pediatria.h"


paciente_t *primeiro_paciente(char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *novo = (paciente_t *)malloc(sizeof(paciente_t));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        return NULL;
    }

    strncpy(novo->nome, nome, 100);
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->genero = genero;
    novo->prox = NULL;

    return novo;
}


void novo_paciente(paciente_t *primeiro, char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *atual = primeiro;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    paciente_t *novo = (paciente_t *)malloc(sizeof(paciente_t));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o novo paciente.\n");
        return;
    }

    strncpy(novo->nome, nome, 100);
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->genero = genero;
    novo->prox = NULL;

    atual->prox = novo;
}


IMCInfantil calcula_imc(paciente_t *crianca) {
    if (crianca->altura <= 0 || crianca->peso <= 0) {
        printf("Dados inválidos para cálculo do IMC.\n");
        return ABAIXO; 
    }

    float imc = crianca->peso / (crianca->altura * crianca->altura);


    if (crianca->idade >= 6 && crianca->idade <= 15) {
        if (imc < 15.0) {
            return ABAIXO;
        } else if (imc >= 15.0 && imc <= 22.0) {
            return NORMAL;
        } else if (imc > 22.0 && imc <= 27.0) {
            return SOBREPESO;
        } else {
            return OBESIDADE;
        }
    } else {
        printf("Idade fora do intervalo permitido (6 a 15 anos).\n");
        return ABAIXO; 
    }
}