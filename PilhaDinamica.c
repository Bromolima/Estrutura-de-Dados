#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
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

void empilhar(Pilha *p, int dado){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave.chave = dado;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

int desempilhar(Pilha *p){
    if(isEmpty(p)){
        return -1;
    }
    No *aux = p->topo;
    int dado = aux->chave.chave;
    p->topo = aux->prox;
    free(aux);
    return dado;
}

int peek(Pilha *p){
    if((isEmpty(p))){
        return -1;
    }
    return p->topo->chave.chave;
}

void destruirPilha(Pilha *p){
    while (!isEmpty(p)){
        desempilhar(p);
    }
    free(p);
    
}

int main(){
    Pilha p; inicializarPilha(&p);
    empilhar(&p, 1);
    empilhar(&p, 2);
    printf("Elemento no topo-> %d", peek(&p));

}