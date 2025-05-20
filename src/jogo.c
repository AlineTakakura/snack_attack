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
Lanche lanche;
int score = 0, gameOver = 0;

void mostrarMenu() {
    screenClear();

    printf("\n\n");
    printf("========== SNACK ATTACK ==========\n");
    printf("Pressione ENTER para jogar\n");
    printf("Use W A S D para mover o personagem\n");
    printf("Pressione Q para sair\n");

        while (1) {
        if (keyhit()) {// ver se a tecla foi pressionada.
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
void desenharPersonagem(int x, int y) {
    FILE *f = fopen("assets/personagem/personagem.txt", "r");
    if (!f) return;
    char linha[100];
    int yy = 0;
    while (fgets(linha, sizeof(linha), f)) {
        screenGotoxy(x, y + yy++);
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
    initLanche(&lanche);
}

void finalizarJogo() {
    screenDestroy();
    keyboardDestroy();
    timerDestroy();

    // salvar score no arquivo
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

            atualizarLanche(&lanche, &score, jogador.x, &gameOver);

            screenClear();
            desenharCenario();
            desenharLanche(&lanche);
            desenharPersonagem(jogador.x, jogador.y);

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