#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    mostrarMenu(); 
    inicializarJogo();
    jogoLoop();
    finalizarJogo();
    return 0;
}