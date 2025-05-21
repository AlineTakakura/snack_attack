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
        if ((l->x == jogadorX)||(l->x == jogadorX - 1)||(l->x == jogadorX + 1)) {
            *gameOver = 1;
            return;
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
