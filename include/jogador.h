#ifndef JOGAGOR_H
#define JOGADOR_H

typedef struct {
    int x,y;
    char sprite;
} Jogador;

void initJogador(Jogador *j);
void moverJogador(Jogador *j, char tecla);
void desenharJogador(Jogador *j);


#endif