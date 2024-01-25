#include <stdlib.h>
#include <stdio.h>

typedef struct posicao
{
    int i,j;
    char chave;
}Posicao;

typedef struct no{
    Posicao dados;
    struct no *prox;
}No;

typedef struct lista{
    int tam;
    No *inicio;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void exibirLista(Lista *l){
    No *aux = l->inicio;
    printf("Lista:\n");
    while(aux != NULL){
        printf("Chave->%c, coordenada (%d,%d) ", aux->dados.chave, aux->dados.i, aux->dados.j);
        aux = aux->prox;
    }
}

No *buscaSequencial(Lista *l, char chave){
    No *aux = l->inicio;
    while (aux != NULL)
    {
        if(aux->dados.chave == chave)
        {
            return aux;
        }
    }
    return NULL;
}

void inserirNoInicio(Lista *l, char chave, int i, int j)
{
    No *novo = (No*)malloc(sizeof(No));

    novo->dados.chave = chave;
    novo->dados.i = i;
    novo->dados.j = j;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tam++;
}

int removerElemento(Lista *l, char chave) {
    No *anterior = NULL;
    No *atual = l->inicio;
    
    while (atual != NULL) {
        if (atual->dados.chave == chave) {
            if (anterior == NULL) {
                l->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            l->tam--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    return 0;
}

Posicao primeiroElemento(Lista *l) {
    Posicao posicaoVazia = {0, 0, '\0'};
    if (l->inicio != NULL){
        return l->inicio->dados;
    } 
    else{
        return posicaoVazia;
    }
}

int main(){
    Lista lista; inicializarLista(&lista);
    
    inserirNoInicio(&lista, 'A', 1, 1);
    exibirLista(&lista);

    return 0;
}