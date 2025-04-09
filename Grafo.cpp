#include <iostream>
using namespace std;

#include "ListaAdjacencia.cpp"
#include "MatrizAdjacencia.cpp"

class Grafo {
private:
    int nVertices; // Número de vértices
    ListaAdjacencia* lista;
    MatrizAdjacencia* matriz;

public:
    Grafo(int v) {
        nVertices = v;
        lista = new ListaAdjacencia[v];
        matriz = new MatrizAdjacencia(v);
    }

    void adicionarAresta(int origem, int destino, int dado) {
        // Preenchendo a lista
        lista[origem].adicionarVizinho(destino, dado);
        lista[destino].adicionarVizinho(origem, dado);

        // Preenchendo a matriz
        matriz->adicionarAresta(origem, destino, dado);
    }

    void exibir() {
        cout << "Número de Vértices: " << nVertices << endl;
        //Exibe a matriz
        matriz->exibir();
        //Exibe a lista
        for (int i = 0; i < nVertices; i++) {
            cout << "Vértice " << i << ":";
            lista[i].exibir();
        }
    }

    ~Grafo() {
        delete[] lista;
        delete matriz;
    }

};