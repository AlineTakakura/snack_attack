#include "lanche.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

void initLanche(Lanche *l) {
    l->x = rand() % 68 + 1;
    l->y = 1;
    l->simbolo = "🍔";  
}

void atualizarLanche(Lanche *l, int *score, int jogadorX, int jogadorY, int *gameOver) {
    l->y++;
    if (l->y == jogadorY) {
        if (l->x == jogadorX) {
            *gameOver = 1;
        } else {
            (*score)++;
            initLanche(l);
        }
    }
    if (l->y > jogadorY) {
        (*score)++;
        initLanche(l);
    }
}

void desenharLanche(Lanche *l) {
    screenGotoxy(l->x, l->y);
    printf("%s", l->simbolo);
}
