 #include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file;
    int number, countNumbers = 0, biggestNumber = 0;

    file = fopen("C:\\Users\\pedro\\OneDrive\\Área de Trabalho\\ALGORITIMO E PROGRAMACAO\\ATIVIDADE 10\\numeros.dat", "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fread(&number, sizeof(int), 1, file) == 1) {
        countNumbers++;
        if(number > biggestNumber) biggestNumber = number;
        printf("%d \n", number, countNumbers);
    }

    printf("Count: %d\n Biggest: %d \n", countNumbers, biggestNumber);

    fclose(file);
    return 0;
}