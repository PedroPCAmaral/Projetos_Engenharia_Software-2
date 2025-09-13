#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

typedef struct SnakePart {
    int x, y;
    struct SnakePart *next;
} SnakePart;

typedef struct Food {
    int x, y;
} Food;

char board[MAX_HEIGHT][MAX_WIDTH];
int currentLevel = 1;
int score = 0;
int gameOver = 0;
SnakePart *snake = NULL;
Food food;

// Função para inicializar a cobra e a comida
void initializeGame() {
    snake = (SnakePart *)malloc(sizeof(SnakePart));
    snake->x = MAX_WIDTH / 2;
    snake->y = MAX_HEIGHT / 2;
    snake->next = NULL;

    food.x = rand() % MAX_WIDTH;
    food.y = rand() % MAX_HEIGHT;
}

// Função para carregar uma fase de arquivo
void loadLevel(int level) {
    char filename[20];
    sprintf(filename, "level%d.txt", level);  // Arquivos chamados "level1.txt", "level2.txt", etc.
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Erro ao carregar o nível %d\n", level);
        gameOver = 1;
        return;
    }

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            board[i][j] = fgetc(file);
            if (board[i][j] == '\n') {
                board[i][j] = fgetc(file);  // Ignorar caracteres de nova linha
            }
        }
    }
    fclose(file);
}

// Função para movimentar a cobra
void moveSnake(char direction) {
    int newX = snake->x;
    int newY = snake->y;

    // Atualizar posição com base na direção
    switch (direction) {
        case 'w': newY--; break;  // Cima
        case 's': newY++; break;  // Baixo
        case 'a': newX--; break;  // Esquerda
        case 'd': newX++; break;  // Direita
    }

    // Verificar colisão com o limite do tabuleiro
    if (newX < 0 || newX >= MAX_WIDTH || newY < 0 || newY >= MAX_HEIGHT || board[newY][newX] == '#') {
        gameOver = 1;
        return;
    }

    // Mover a cobra (você pode precisar adicionar lógica para lidar com partes da cobra aqui)
    SnakePart *newHead = (SnakePart *)malloc(sizeof(SnakePart));
    newHead->x = newX;
    newHead->y = newY;
    newHead->next = snake;
    snake = newHead;

    // Atualizar o tabuleiro e verificar a comida
    if (newX == food.x && newY == food.y) {
        score += 10;
        food.x = rand() % MAX_WIDTH;
        food.y = rand() % MAX_HEIGHT;
    } else {
        // Remover a cauda se nenhuma comida foi comida
        SnakePart *temp = snake;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Função para exibir o tabuleiro
void displayBoard() {
    system("cls");  // Limpar a tela
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (i == snake->y && j == snake->x) {
                printf("O");  // Cabeça da cobra
            } else if (i == food.y && j == food.x) {
                printf("*");  // Comida
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Pontuação: %d\n", score);
}

// Função principal
int main() {
    initializeGame();
    loadLevel(currentLevel);

    while (!gameOver) {
        displayBoard();
        if (_kbhit()) {  // Se uma tecla foi pressionada
            char direction = _getch();
            moveSnake(direction);
        }
        Sleep(100);  // Controla a velocidade da cobra
    }

    printf("Game Over! Pontuação final: %d\n", score);
    return 0;
}
