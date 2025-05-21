#ifndef JOGO_H
#define JOGO_H
#include "lanche.h"
#define MAX_LANCHES 5

void mostrarMenu();
void inicializarJogo();
void jogoLoop();
void finalizarJogo();

extern Lanche lanches[MAX_LANCHES];

#endif