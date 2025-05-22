#include "lanche.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

void initLanche(Lanche *l) {
    l->x = rand() % 68 + 1;
    l->y = 1;
    l->simbolo = "🍔";  
}
void atualizarLanche(Lanche *l, int *score, int jogadorX, int jogadorY, int jogadorLargura, int jogadorAltura, int *gameOver){
    l->y++;
    int dentroX = l->x >= jogadorX && l->x < jogadorX + jogadorLargura;
    int dentroY = l->y >= jogadorY && l->y < jogadorY + jogadorAltura;

    if (dentroX && dentroY) {
        *gameOver = 1;
        return;
    }

    if (l->y > 23) { 
        (*score)++;
        initLanche(l);
    }
}

void desenharLanche(Lanche *l) {
    screenGotoxy(l->x, l->y);
    printf("%s", l->simbolo);
}
