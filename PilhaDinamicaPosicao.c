#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i,j;
    char chave;
} Dados;

typedef struct no{
    Dados chave;
    struct no *prox; 
}No;

typedef struct pilha{
    No *topo;
    int tam;
}Pilha;

int isEmpty(Pilha *p){
    return (p->topo == NULL);
}

void inicializarPilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

void empilhar(Pilha *p, int chave, int i, int j){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave.chave = chave;
    novo->chave.i = i;
    novo->chave.j = j; 
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

Dados desempilhar(Pilha *p){
    Dados vazio = {-1, -1, '\0'};
    if(isEmpty(p)){
        return vazio;
    }
    No *aux = p->topo;
    Dados dado = aux->chave;
    p->topo = aux->prox;
    free(aux);
    p->tam--;
    return dado;
}

Dados peek(Pilha *p){
    Dados vazio = {-1, -1, '\0'};
    if((isEmpty(p))){
        return vazio;
    }
    return p->topo->chave;
}

void destruirPilha(Pilha *p){
    while (!isEmpty(p)){
        desempilhar(p);
    }
    free(p);
    
}

int main(){
    Pilha p; inicializarPilha(&p);
    Dados topo;
    
    empilhar(&p, 'A', 1, 1);
    empilhar(&p, 'B', 1, 2);
    topo = peek(&p);
    
    if(isEmpty(&p)){
        printf("Esta vazia");
    }
    else{
        printf("Chave->%c, coordenada(%d,%d)", topo.chave, topo.i, topo.j);
    }
}