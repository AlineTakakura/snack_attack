#include "jogador.h"
#include "screen.h"
#include <stdio.h>


void initJogador(Jogador *j) {
    j->x = 35;            
    j->y = 20;            
    j->largura = 3;
    j->altura = 3;
}


void moverJogador(Jogador *j, char tecla) {
    if (tecla == 'a' && j->x > 3) j->x--;
    if (tecla == 'd' && j->x < 75) j->x++;
}

void desenharJogador(Jogador *j) {
    FILE *f = fopen("assets/sprites/jogador.txt", "r");
    if (!f) return;

    char linha[100];
    int yy = 0;
    while (fgets(linha, sizeof(linha), f)) {
        screenGotoxy(j->x, j->y + yy++);
        printf("%s", linha);
    }
    fclose(f);
}
