#include <stdio.h>
#include <iostream>

using namespace std;

class No {
    private:

        int indice; // índice do vértice vizinho
        int dado; // valor do indice
        No* proximo;

    public:
        No(int indice, int dado) {
            this->indice = indice;
            this->dado = dado;
            proximo = nullptr;
        }

        int getIndice(){
            return indice;
        }

        void setIndice(int cont){
            this->indice = cont;
        }

        int getDado(){
            return dado;
        }

        void setDado(int dado){
            this->dado = dado;
        }

        No* getProximo() {
            return proximo;
        }

        void setProximo(No* proximo) {
            this->proximo = proximo;
        }
};
