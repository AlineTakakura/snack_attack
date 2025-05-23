#ifndef LANCHE_H
#define LANCHE_H

typedef struct Lanche{
    int x,y;
    const char *simbolo;
    struct Lanche *prox;
}Lanche;

void initLanche(Lanche *l);
void atualizarLanche(Lanche *l,int *score,int jogadorX,int jogadorY,int jogadorLargura,int jogadorAltura,int *gameOver);
void desenharLanche(Lanche *l);

#endif

