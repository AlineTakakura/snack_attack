#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    inicializarJogo();
    jogoLoop();
    finalizarJogo();
    return 0;
}