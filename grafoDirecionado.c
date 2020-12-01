#include<stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;

//Aresta
typedef struct adjacencia{
    int vertice; // vertice de destino 
    int peso; // peso associado a aresta que leva ao vertice de destino
    struct adjacencia *next; // O próximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice{
    //Dados são armazenados aqui
    ADJACENCIA *head;  //possui apenas a cabeça da lista de adjacencia
}VERTICE;

typedef struct grafo{
    int vertices; // numero de vertice total do grafo
    int arestas; // numero de arestas totais do grafo
    VERTICE *adj; // Arranjo de vertices da estrutura (linha 10)
}GRAFO;

GRAFO *criaGrafo(int v){
     int i;
    GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO)); //aloca memoria para estrtura grafo
    g->vertices = v; //atualizo o numero de vertice
    g->arestas = 0;  //atualizo o numero de arestas
    g->adj = (VERTICE*)malloc(v*sizeof(VERTICE));
    //Dentro da estrturua tem só o arranjo para o ponteiro de vertice, não o arranjo em si 	
	//então aloco o arranjo com (v) o numero de vertice desejado
    for(i= 0;i < v; i++){
        g->adj[i].head = NULL; //coloco NULL em todas arestas
    }
    return g;
}

ADJACENCIA *criaAdj(int v,int peso){
    ADJACENCIA *adj = (ADJACENCIA*)malloc(sizeof(ADJACENCIA));
    adj->vertice = v;  //vertice alvo da adjacencia
    adj->peso = peso;  //peso da aresta (valor,distancia etc)
    adj->next = NULL;
    return adj;  //retorna endereço da adjacencia
}

int criaAresta(GRAFO* gr, int vi, int vf,int peso){
    if(gr == NULL)
    {
        return false;
    }
    if(vf < 0 || vf >= gr->vertices){ //validações se os valores não são menores que o numero de vertices
        return false;
    }
    if(vi < 0 || vi >= gr->vertices){ //ou maiores que o numero de vértices
        return false;
    }
    ADJACENCIA *nova = criaAdj(vf,peso);//cria adjacencia com o vértice final e o peso
    //coloca a adjacencia na lista do vértice inicial
    nova->next = gr->adj[vi].head;  //o campo next da adjacencia vai receber a cabeça da lista
    gr->adj[vi].head = nova; // e a cabeça da lista passa a ser o novo elemento
    gr->arestas++; //atualiza o numero de aresta no grafo
}

void imprimir(GRAFO *gr){
    if(gr != NULL){
        printf("Vertices: %d. Arestas: %d.\n",gr->vertices,gr->arestas);  //imprime numero de vértice e arestas
        int i;
        for(i = 0; i < gr->vertices; i++){
            printf("V%d -> ",i); //Imprime em qual aresta esta
            ADJACENCIA *adj = gr->adj[i].head;//chama a cabeça da lista de adjacencia desta aresta
            while(adj != NULL){//enquanto as adjacencias não forem null
                printf("V%d(peso %d) ",adj->vertice,adj->peso); //imprime a adjacencia e seu peso
                adj = adj->next; //aponta para proxima adjacencia
            }
            printf("\n");
        }
    }
    return false;
}


int main(){
    GRAFO *gr = criaGrafo(5);

    criaAresta(gr,0,1,2);
    criaAresta(gr,1,2,4);
    criaAresta(gr,2,4,6);
    criaAresta(gr,3,1,8);
    criaAresta(gr,4,3,9);
    
    imprimir(gr);

}
