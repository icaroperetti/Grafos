#include <stdio.h>
#include <stdlib.h>


int** criaMatriz(int nv){
   int** grafo;
   int i;
   grafo = (int **)malloc(sizeof(int *)*nv);

   for(i = 0; i < nv; i++){
    grafo[i] = (int *)malloc(sizeof(int)*nv);
   }
   return grafo;
}

 void zeraMatriz(int** grafo,int nv)
 {
    int i,j;
    for (i = 0; i < nv; i++)
    {
       for (j = 0; j < nv; j++)
       {
          grafo[i][j] = 0;
          printf("[%d][%d]= %d \t", i, j, grafo[i][j]);
       }
       printf("\n");
    }
}

void adicionaAresta(int** grafo,int nv){
   int vi,vf;
   printf("\n (-1) para encerrar\n");
   printf("\nVertice de partida: ");
   scanf("%d", &vi);
   while (vi != -1)
   {
      printf("\nVertice de chegada: ");
      scanf("%d", &vf);
      if (vf < 0 || vf >= nv)
      { 
         return 0;
      }
      grafo[vi][vf] = 1;

      printf("\nVertice de partida: ");
      scanf("%d", &vi);
   }
}

void imprimir(int** grafo,int nv){
   int i,j;
   if(grafo != NULL){
      for (i = 0; i < nv; i++)
      {
         for (j = 0; j < nv; j++)
         {
            printf("[%d][%d]= %d \t", i, j, grafo[i][j]);
         }
         printf("\n");
      }
   }
}

int liberaMemoria(int **grafo, int nv){
  int i;
  for (i = 0; i < nv; i++){
      free(grafo[i]); //Libera as linhas
  }
  free(grafo); //Libera a matriz;
  return NULL;
}

int main(){
   int nv;
   printf("Digite numero de vertices:");
   scanf("%d",&nv);

   int **grafo = criaMatriz(nv);

   zeraMatriz(grafo,nv);
   adicionaAresta(grafo,nv);
   imprimir(grafo,nv);

   grafo = liberaMemoria(grafo,nv);
   return 0;
}
