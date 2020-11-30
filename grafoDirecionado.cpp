#include <iostream>
#include <list>
#include <algorithm>

/*
	Algoritmo para representação de grafos direcionados (digrafos)
*/

using namespace std;

class Grafo
{
	int v; //Numero de vertices
	list<int> *adj; //Ponteiro para um array contendo as listas de adjacencias
	
	public:
		Grafo(int v); //Construtor
		void adicionarAresta(int v1,int v2); //Adiciona aresta no grafo, conecta v1 com v2 
		
		//Obtem o grau de saida de um vertice (nodo)
		//numero de arestas que saem de V
		int obterGrauSaida(int v);
		
		//Verifica se um vertice é vizinho de outro
		bool existeVizinho(int v1,int v2); //Verifica se v2 é vizinho de v1
};

Grafo::Grafo(int v)
{
	this->v = v; //atribui o numero de vertices 
	adj = new list<int>[v]; //Cria as listas, cada vértice possui uma lista
}

void Grafo::adicionarAresta(int v1,int v2)
{
	//adicionar vertice v2 a lista de vertices adjacentes de v1
	adj[v1].push_back(v2);
}

int Grafo::obterGrauSaida(int v)
{
	//Basta retornar o tamanho da lista que e a quantidade de vizinhos
	return adj[v].size();
}

bool Grafo::existeVizinho(int v1,int v2)
{
	if(find(adj[v1].begin(),adj[v1].end(),v2) != adj[v1].end())
	{
		return true;
	}
	return false;
}



int main()
{
	//Cria um grafo com 4 vertices
	Grafo grafo(4);
	
	grafo.adicionarAresta(0,1);
	grafo.adicionarAresta(0,3);
	grafo.adicionarAresta(1,2);
	grafo.adicionarAresta(3,1);
	grafo.adicionarAresta(3,2);
	
	cout << "Grau de saida do vertice 1: " << grafo.obterGrauSaida(1);
	cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauSaida(3);
	cout << "\nGrau de saida do vertice 0: " << grafo.obterGrauSaida(0);
	
	//Verifica se existe vizinho
	if(grafo.existeVizinho(0,1))
	{
		cout << "\n1 e vizinho de 0\n";
	}
	else 
	{
		cout << "1 nao e vizinho de 0";
	}

	if(grafo.existeVizinho(1,0))
	{
		cout << "\n0 e vizinho de 1\n";
	}
	else
	{
		cout << "0 nao e vizinho de 1\n";
	}

	
	if(grafo.existeVizinho(2,0))
	{
		cout << "\n2 e vizinho de 0\n";
	}
	else
	{
		cout << "2 nao e vizinho de 0\n";
	}


	return 0;
}
