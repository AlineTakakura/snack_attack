#include "lanche.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

void initLanche(Lanche *l) {
    l->x = rand() % 68 + 1;  
    l->y = 1;
    l->simbolo = '*';
}


void atualizarLanche(Lanche *l, int *score, int jogadorX, int *gameOver) {
    l->y++;
    if (l->y >= 22) {
        if (l->x == jogadorX) {
            *gameOver = 1;
        } else {
            (*score)++;
            initLanche(l);
        }
    }
}

void desenharLanche(Lanche *l) {
    screenGotoxy(l->x, l->y);
    printf("%c", l->simbolo);
}