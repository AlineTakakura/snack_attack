#include "jogador.h"
#include "screen.h"
#include <stdio.h>

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
    screenGotoxy(j->x, j->y);
    printf("%c", j->sprite);
}