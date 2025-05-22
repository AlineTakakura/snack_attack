#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    int x, y;           
    int largura;        
    int altura;         
} Jogador;

void initJogador(Jogador *j);
void moverJogador(Jogador *j, char tecla);
void desenharJogador(Jogador *j);

#endif
