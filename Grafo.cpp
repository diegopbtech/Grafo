#include <iostream>
#include <queue>
#include <vector>
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

    // Função para chamar a Busca em Largura
    void bfs(int origem, int destino) {
        vector<bool> visitado(nVertices, false);
        vector<int> pred(nVertices, -1);
        queue<int> fila;

        visitado[origem] = true;
        fila.push(origem);

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            No* vizinho = lista[atual].cabeca;
            while (vizinho != nullptr) {
                int v = vizinho->getIndice();
                if (!visitado[v]) {
                    visitado[v] = true;
                    pred[v] = atual;
                    fila.push(v);
                }
                vizinho = vizinho->getProximo();
            }
        }

        // Reconstruir o caminho
        if (!visitado[destino]) {
            cout << "Não há caminho entre os vértices " << origem << " e " << destino << "." << endl;
            return;
        }

        // Caminho encontrado: reconstruir usando pred
        vector<int> caminho;
        for (int v = destino; v != -1; v = pred[v]) {
            caminho.push_back(v);
        }

        // Imprimir o caminho na ordem correta
        cout << "Caminho de " << origem << " até " << destino << ": ";
        for (int i = caminho.size() - 1; i >= 0; i--) {
            cout << caminho[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

};