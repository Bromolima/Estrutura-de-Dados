#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
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
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

No *buscaSequencial(Lista *l, int chave){
    No *aux = l->inicio;
    while (aux != NULL)
    {
        if(aux->chave == chave)
        {
            return aux;
        }
    }
    return NULL;
}

void inserirNoInicio(Lista *l, int chave)
{
    No *novo = (No*)malloc(sizeof(No));

    novo->chave = chave;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tam++;
}

int removerElemento(Lista *l, int chave){
    No *anterior = NULL;
    No *atual = l->inicio;
    while (atual != NULL){
        if(atual->chave == chave){
            if(anterior == NULL){
                l->inicio = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
        free(atual);
        l->tam--;
        return 1;
        }
    }
    anterior = atual;
    atual = atual->prox;
}


int primeiroElemento(Lista *l) {
    if (l->inicio != NULL) {
        return l->inicio->chave;
    } else {
        printf("A lista está vazia.\n");
        return 0;
    }
}

int main(){
    Lista lista;
    inicializarLista(&lista);
    inserirNoInicio(&lista, 20);
    inserirNoInicio(&lista, 10);
    removerElemento(&lista, 10);
    inserirNoInicio(&lista, 30);
    exibirLista(&lista);

    return 0;
}