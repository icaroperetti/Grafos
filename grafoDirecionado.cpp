#include <bits/stdc++.h>
#include <iostream>
#include <list> //lib para usar list
#include <algorithm> //lib para usar funcao find

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
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Add edge
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
			cout << "Vertice de partida invalido";
			return false;
		}
		if (vf < 0 || vf >= Grafo::V)
		{
			cout << "Vertice de chegada invalido";
			return false;
		}

		//Função pronta do C++ que adiciona uma lista ao final da outra
		adj[vi].push_back(vf);

		cout << "Digite o vertice de partida:";
		cin >> vi;
	}
	
}

// Print the graph
void Grafo::printGraph(list<int> adj[], int V) {
  for (int i = 0; i < V; ++i) {
    cout << "\n Vertice "
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

  // Add edges
  grafo.addEdge(adj);
  grafo.printGraph(adj,V);

	if(grafo.neighborExists(adj,1,2))
	{
		cout << "\n1 e vizinho de 2\n";
	}

	if(grafo.neighborExists(adj,2,1))
	{
		cout << "2 e vizinho de 1\n";
	}else{
		cout << "2 nao e vizinho de 1\n";
	}
	
}
