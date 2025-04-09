#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

class MatrizAdjacencia {
private:
    int nVertices;
    int** matriz;

public:
    MatrizAdjacencia(int v) {
        nVertices = v;

        matriz = new int*[nVertices];

        for (int i = 0; i < v; i++){
            matriz[i] = new int[v];
            for (int j = 0; j < v; j++){
                matriz[i][j] = 0;
            }
        }
    }

    void adicionarAresta(int origem, int destino, int dado) {
        matriz[origem][destino] = dado;
        matriz[destino][origem] = dado;
    }

    void exibir() {
        cout << "Matriz de Adjacência:\n";
        for (int i = 0; i < nVertices; i++) {
            for (int j = 0; j < nVertices; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~MatrizAdjacencia() {
        for (int i = 0; i < nVertices; i++) {
            delete[] matriz[i]; // desaloca cada linha
        }
        delete[] matriz; // desaloca o vetor de ponteiros
    }

};
