#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct lista
{
    int tam;
    int dado[MAX];
} Lista;

void inicializar(Lista *l){
    l->tam = 0;
}

int tamanho(Lista *l){
    return l->tam;
}

int exibirLista(Lista *l){
    int i;
    printf("Lista:\n");
    for (i = 0; i < l->tam; i++){
        printf("%d ", l->dado[i]);
    }
    printf("\n");
}

int buscaSequencial(Lista *l, int d){
    int i = 0;
    while (i < l->tam){
        if(d == l->dado[i]){
            return i;
        }
        else{
            i++;
        }
    }
    return -1;
}

int inserirNaLista(Lista *l, int d, int n){
    int i;

    if((l->tam >= MAX) || (n < 0) || (n > l->tam))
    {
        return 0;
    }
    for(i = l->tam; i > n; i--){
        l->dado[i] = l->dado[i - 1];
    }
    l->dado[i] = d;
    l->tam++;

    return 1;
}

int inserirNoInicio(Lista *l, int d){
    int i;

    if(l->tam >= MAX){
        printf("\nTamanho maximo atingido");
        return -1;
    }
    for(i = l->tam; i > 0; i--){
        l->dado[i] = l->dado[i - 1];
    }
    l->dado[0] = d;
    l->tam++;
    return 1;
}

int removerDaLista(Lista *l, int d){
    int pos, i;
    pos = buscaSequencial(l, d);
    if(pos = -1){
        return -1;
    }
    for(i = pos; i < l->tam - 1; i++){
        l->dado[i] = l->dado[i+1];
    }
    l->tam--;
    return 1;
}

int main(){
    Lista *l;
    inicializar(l);
    inserirNoInicio(l, 2);
    inserirNoInicio(l ,3);
    printf("Posicao do dado %d na lista-> %d", 3, buscaSequencial(l, 3));
    printf("\nTamanho da lista -> %d\n", tamanho(l));
    exibirLista(l);
}