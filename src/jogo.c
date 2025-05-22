#include "jogo.h" 
#include "jogador.h"
#include "lanche.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Jogador jogador;
int score = 0, gameOver = 0;
Lanche *lanches = NULL;   
int num_lanches = 5;      

void mostrarMenu() {
    screenClear();

    printf("\n\n");
    printf("========== SNACK ATTACK ==========\n");
    printf("Pressione ENTER para jogar\n");
    printf("Use setas do teclado (<- e ->) para mover o personagem\n");
    printf("Pressione Q para sair\n");

    while (1) {
        if (keyhit()) {
            char tecla=readch();
            if (tecla=='\n'||tecla=='\r') {
                break;
            }
            if (tecla=='q'||tecla=='Q') {
                exit(0);
            }
        }
    }
}

void desenharCenario() {
    FILE *f = fopen("assets/cenario/cenario.txt", "r");
    if (!f) return;
    char linha[100];
    int y = 1;
    while (fgets(linha, sizeof(linha), f) && y <= 23) {
        screenGotoxy(3, y++);
        printf("%s", linha);
    }
    fclose(f);
}

void inicializarJogo() {
    screenInit(0);
    keyboardInit();
    timerInit(150);
    srand(time(NULL));
    initJogador(&jogador);

    lanches = malloc(sizeof(Lanche) * num_lanches);
    if (!lanches) {
        fprintf(stderr, "Erro ao alocar memória para lanches\n");
        exit(1);
    }

    for (int i = 0; i < num_lanches; i++) {
        initLanche(&lanches[i]);
    }
}

void finalizarJogo() {
    screenDestroy();
    keyboardDestroy();
    timerDestroy();

    if (lanches) {
        free(lanches);
        lanches = NULL;
    }

    FILE *f = fopen("data/score.txt", "a");
    if (f) {
        fprintf(f, "Score: %d\n", score);
        fclose(f);
    }
}

void jogoLoop() {
    while (!gameOver) {
        if (timerTimeOver()) {
            if (keyhit()) {
                char tecla = readch();
                if (tecla == 'q') break;
                moverJogador(&jogador, tecla);
            }

            for (int i = 0; i < num_lanches; i++) {
                atualizarLanche(&lanches[i], &score, jogador.x, jogador.y, jogador.largura, jogador.altura, &gameOver);
            }

            screenClear();
            desenharCenario();

            for (int i = 0; i < num_lanches; i++) {
                desenharLanche(&lanches[i]);
            }

            desenharJogador(&jogador);

            screenGotoxy(2, 0);
            printf("Score: %d", score);

            screenUpdate();
        }
    }

    screenClear();
    screenGotoxy(30, 12);
    printf("Game Over! Pontuação final: %d", score);
    screenUpdate();
}
