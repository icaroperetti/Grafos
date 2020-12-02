#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int nv)
{
   //1 ponteiro permite criar um vetor, 2 ponteiros permitem criar uma matriz (vetor para vetor)
   int **grafo;
   int i;

   //Cria um vetor de ponteiros(int*)
   grafo = (int **)malloc(nv * sizeof(int*)); //Cria as linhas da matriz

   for (i = 0; i < nv; i++)
   {  
      //cria um vetor de int
      grafo[i] = (int *)malloc(nv * sizeof(int)); //Cria as colunas da matriz
   }
   return grafo;
}

void zeraMatriz(int **grafo, int nv)
{
   int i, j;
   for (i = 0; i < nv; i++)
   {
      for (j = 0; j < nv; j++)
      {
         grafo[i][j] = 0;
         printf("%d  ",grafo[i][j]);
      }
      printf("\n");
   }
}

void adicionaAresta(int** grafo,int nv){
   int vi,vf,peso;

   printf("\n Digite um valor negativo para finalizar e imprimir\n");
   printf("Vertice de partida(valores entre 0 e %d): ",nv - 1 );
   scanf("%d", &vi);

   while (vi > -1 && vi < nv)
   {
      printf("Vertice de chegada(valores entre 0 e %d): ",nv - 1);
      scanf("%d", &vf);

      printf("Digite um valor associado a essa relacao:");
      scanf("%d",&peso);
      
      if (vf < 0 || vf >= nv)
      { 
         return 0;
      }
      grafo[vi][vf] = peso;

      //Se quiser transformar em um vertice nao direcionado
      //grafo[vf][vi] = peso;

      printf("\nVertice de partida(valores entre 0 e %d): ",nv - 1);
      scanf("%d", &vi);
   }
}

void imprimir(int **grafo, int nv)
{
   int i, j;
   for(i= 0; i < nv;i++){
      printf("  %d  ",i);
   }
   printf("\n");
   for (i = 0; i < nv; i++)
   {
      printf("%d  ",i);
      for (j = 0; j < nv; j++)
      {
         
         printf(" %d  ",grafo[i][j]);
      }
      printf("\n");
   }
}

void removerAresta(int** grafo,int nv)
{
   int vi,vf,i,j;
   printf("\n Digite um valor negativo para finalizar e imprimir\n");
   printf("Digite o vertice de saida da aresta que deseja remover:");
   scanf("%d",&vi);

   while (vi > -1 && vi < nv)
   {
      printf("Digite o vertice de chegada da aresta que deseja remover:");
      scanf("%d",&vf);

      grafo[vi][vf] = 0;

      printf("Digite o vertice de saida da aresta que deseja remover:");
      scanf("%d", &vi);
   }
}

void liberarMemoria(int **grafo, int nv)
{
   int i;
   for (i = 0; i < nv; i++)
   {
      free(grafo[i]); //Libera as linhas de cada coluna
   }
   free(grafo); //Libera a coluna;
}

int main()
{
   int nv; //Numero de vertices
   printf("Digite numero de vertices:");
   scanf("%d", &nv);

   int **grafo = criaMatriz(nv);

   zeraMatriz(grafo, nv);
   adicionaAresta(grafo, nv);
   imprimir(grafo, nv);

   removerAresta(grafo,nv);
   imprimir(grafo, nv);
   liberarMemoria(grafo, nv);
   return 0;
}
