#include<stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;

/*
    Grafo direcionado utilizando lista de adjacencia
*/

typedef struct adjacencia{
    int vertice;
    struct adjacencia *next;
}ADJACENCIA;

typedef struct vertice{
    ADJACENCIA *head;
}VERTICE;

typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *adj;
}GRAFO;

GRAFO *criaGrafo(int v){
    GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE*)malloc(v*sizeof(VERTICE));
    int i;
    for(i= 0;i < v; i++){
        g->adj[i].head = NULL;
    }
    return g;
}

ADJACENCIA *criaAdj(int v){
    ADJACENCIA *adj = (ADJACENCIA*)malloc(sizeof(ADJACENCIA));
    adj->vertice = v;
    adj->next = NULL;
    return adj;
}

int criaAresta(GRAFO* gr, int vi, int vf){
    if(vf < 0 || vf >= gr->vertices){
        return false;
    }
    if(vi < 0 || vi >= gr->vertices){
        return false;
    }
    ADJACENCIA *nova = criaAdj(vf);
    nova->next = gr->adj[vi].head;
    gr->adj[vi].head = nova;
    gr->arestas++;
    return true;
}

void imprimir(GRAFO *gr){
    if(gr != NULL){
        printf("Vertices: %d. Arestas: %d.\n",gr->vertices,gr->arestas);
        int i;
        for(i = 0; i < gr->vertices; i++){
            printf("V%d -> ",i);
            ADJACENCIA *adj = gr->adj[i].head;
            while(adj){
                printf("V%d ",adj->vertice);
                adj = adj->next;
            }
            printf("\n");
        }
    }
    return false;
}

int main(){
    GRAFO *gr = criaGrafo(5);

    criaAresta(gr,0,1);
    criaAresta(gr,1,2);
    criaAresta(gr,2,4);
    criaAresta(gr,3,1);
    criaAresta(gr,4,3);

    imprimir(gr);
}
