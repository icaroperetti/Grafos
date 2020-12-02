#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Grafo
{
	int V; //Numero de vertices 
	list<int> *adj; //Ponteiro para um array contendo as listas de adjacencias

	public:
		Grafo(int V); //Construtor 

		//Prototipação das funcoes
		int addEdge(list<int> adj[]); 
		void printGraph(list<int> adj[], int V);
		bool neighborExists(list<int> adj[],int vi,int vf);
		int exitDegree(list<int>adj[],int V);
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//Adicionar arestas
int Grafo::addEdge(list<int> adj[])
{
	int vi, vf;
	cout << "Digite um numero negativo para finalizar e imprimir\n\n";
	cout << "Digite o vertice de partida:";
	cin >> vi;

	while (vi > -1)
	{
		cout << "Digite o vertice de chegada:";
		cin >> vf;

		if (vi < 0 || vi >= Grafo::V)
		{
			return false;
		}

		if (vf < 0 || vf >= Grafo::V)
		{
			return false;
		}

		//Função existente no C++ que adiciona uma lista ao final da outra
		adj[vi].push_back(vf);

		cout << "Digite o vertice de partida:";
		cin >> vi;
	}
	return 0;
}

//Para obter o grau de saida de um vertice, basta 
//retornar o tamanho da lista do vertice V
int Grafo::exitDegree(list<int>adj[],int V)
{
	return adj[V].size();
}

//Imprime o grafo
void Grafo::printGraph(list<int> adj[], int V)
{
	for (int i = 0; i < V; ++i)
	{
		cout << "\nVertice "
				 << i << ":";
		for (int x : adj[i])
			cout << "-> " << x;
		printf("\n");
	}
}

bool Grafo::neighborExists(list<int> adj[],int vi,int vf)
{
	if (find(adj[vi].begin(), adj[vi].end(), vf) != adj[vi].end())
	{
		return true;
	}
	return false;
}

int main() {
  int V;
  cout << "Digite o número de vertices:";
  cin >> V;

  //Constroi o grafo
  Grafo grafo(V);
  
 	list<int>adj[V]; //Cria uma lista de vertices de com o tamanho do grafo

  	//Adiciona as arestas
	grafo.addEdge(adj);
	grafo.printGraph(adj, V);

	cout<< "Grau de saida do vertice 1:" << grafo.exitDegree(adj,1);
	cout<< "\nGrau de saida do vertice 2:" << grafo.exitDegree(adj,2);
	cout<< "\nGrau de saida do vertice 3:" << grafo.exitDegree(adj,3);

	if(grafo.neighborExists(adj,1,2))
	{
		cout << "\n1 e vizinho de 2\n";
	}

	if(grafo.neighborExists(adj,2,1))
	{
		cout << "\n2 e vizinho de 1\n";
	}else{
		cout << "2 nao e vizinho de 1\n";
	}

	if(grafo.neighborExists(adj,0,1))
	{
		cout << "\n0 e vizinho de 1\n";
	}else{
		cout << "0 nao e vizinho de 1\n";
	}
}
