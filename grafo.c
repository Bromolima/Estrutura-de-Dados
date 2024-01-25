#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia
{
    int vertice;
    int peso;
    struct adjacencia *prox; 
} Adjacencia;

typedef struct vertice
{
    char letra;
    Adjacencia *cab;
} Vertice;

typedef struct grafo
{
    int vertices;
    int arestas;
    Vertice *adj;
} Grafo;

Grafo *criarGrafo(int v){
    int i;

    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (Vertice*)malloc(v*sizeof(Vertice));
    for (i = 0; i < v; i++){
        g->adj[i].cab = NULL;
    }
    return (g);
}

Adjacencia *criarAdjacencia(int v, int peso){
    Adjacencia *adj = (Adjacencia*)malloc(sizeof(Adjacencia));
    adj->vertice = v;
    adj->peso = peso;
    adj->prox = NULL;
    
    return (adj);
}

int criarAresta(Grafo *g, int v, int peso){
    if(!g){
        return 0;
    }
    if((v<0) || (v >= g->vertices)){
        return 0;
    }

    Adjacencia *novo = criarAdjacencia(v, peso);
    novo->prox = g->adj[v].cab;
    g->adj[v].cab = novo;
    g->arestas++;

    return(1);
}

int main(){
    return 0;
}

