#include "jogador.h"
#include "screen.h"
#include <stdio.h>
// manipular o arquivo puxar o png


void initJogador(Jogador *j) {
    j->x = 40;
    j->y = 22;
    j->sprite = 'A'; 
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
