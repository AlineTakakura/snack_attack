#ifndef LANCHE_H
#define LANCHE_H

typedef struct {
    int x, y;
    const char *simbolo;  
} Lanche;

void initLanche(Lanche *l);
void atualizarLanche(Lanche *l, int *score, int jogadorX, int jogadorY, int jogadorLargura, int jogadorAltura, int *gameOver);
void desenharLanche(Lanche *l);

#endif
