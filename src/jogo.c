#include"jogo.h"
#include"jogador.h"
#include"lanche.h"
#include"screen.h"
#include"keyboard.h"
#include"timer.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Jogador jogador;
int score=0,gameOver=0;
Lanche *lanches=NULL;
int num_lanches=5;

#define LINHAS_CENARIO 23
#define COLUNAS_CENARIO 80

char cenario[LINHAS_CENARIO][COLUNAS_CENARIO];

void mostrarMenu(){
    screenClear();
    printf("\n\n");
    printf("========== SNACK ATTACK ==========\n");
    printf("Pressione ENTER para jogar\n");
    printf("Use setas do teclado ('A' e 'D') para mover o personagem\n");
    printf("Pressione Q para sair\n");
    while(1){
        if(keyhit()){
            char tecla=readch();
            if(tecla=='\n'||tecla=='\r')break;
            if(tecla=='q'||tecla=='Q')exit(0);
        }
    }
}

void carregarCenario(){
    FILE *f=fopen("assets/cenario/cenario.txt","r");
    if(!f)return;
    for(int y=0;y<LINHAS_CENARIO;y++){
        if(fgets(cenario[y],COLUNAS_CENARIO,f)==NULL){
            for(int x=0;x<COLUNAS_CENARIO-1;x++)cenario[y][x]=' ';
            cenario[y][COLUNAS_CENARIO-1]='\0';
        }
    }
    fclose(f);
}

void desenharCenario(){
    for(int y=0;y<LINHAS_CENARIO;y++){
        screenGotoxy(3,y+1);
        printf("%s",cenario[y]);
    }
}

void inicializarJogo(){
    screenInit(0);
    keyboardInit();
    timerInit(150);
    srand(time(NULL));
    initJogador(&jogador);
    carregarCenario();
    lanches=malloc(sizeof(Lanche));
    if(!lanches){
        fprintf(stderr,"Erro ao alocar lanches\n");
        exit(1);
    }
    initLanche(lanches);
    Lanche *atual=lanches;
    for(int i=1;i<num_lanches;i++){
        atual->prox=malloc(sizeof(Lanche));
        if(!atual->prox){
            fprintf(stderr,"Erro ao alocar lanches\n");
            exit(1);
        }
        atual=atual->prox;
        initLanche(atual);
    }
    atual->prox=NULL;
}

void finalizarJogo(){
    screenDestroy();
    keyboardDestroy();
    timerDestroy();
    Lanche *atual=lanches;
    while(atual){
        Lanche *prox=atual->prox;
        free(atual);
        atual=prox;
    }
    lanches=NULL;
    FILE *f=fopen("data/score.txt","a");
    if(f){
        fprintf(f,"Score: %d\n",score);
        fclose(f);
    }
}

void mostrarTopScores(){
    FILE *f=fopen("data/score.txt","r");
    if(!f){
        printf("Nenhum score salvo ainda.\n");
        return;
    }
    printf("\n=== Top Scores ===\n");
    char linha[100];
    while(fgets(linha,sizeof(linha),f)){
        printf("%s",linha);
    }
    printf("==================\n\n");
    fclose(f);
}

void jogoLoop(){
    while(!gameOver){
        if(timerTimeOver()){
            if(keyhit()){
                char tecla=readch();
                if(tecla=='q')break;
                moverJogador(&jogador,tecla);
            }
            for(Lanche *l=lanches;l!=NULL;l=l->prox){
                atualizarLanche(l,&score,jogador.x,jogador.y,jogador.largura,jogador.altura,&gameOver);
            }
            screenClear();
            desenharCenario();
            for(Lanche *l=lanches;l!=NULL;l=l->prox){
                desenharLanche(l);
            }
            desenharJogador(&jogador);
            screenGotoxy(2,0);
            printf("Score: %d",score);
            screenUpdate();
        }
    }
    screenClear();
    screenGotoxy(30,12);
    printf("Game Over! Pontuação final: %d\n",score);
    mostrarTopScores();
    screenUpdate();
}
