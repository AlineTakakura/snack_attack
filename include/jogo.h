#ifndef JOGO_H
#define JOGO_H

#include "lanche.h"

extern Lanche *lanches;      

void mostrarMenu();
void inicializarJogo();
void jogoLoop();
void finalizarJogo();

#endif
