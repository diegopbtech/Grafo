#include <stdio.h>
#include <iostream>

using namespace std;

class FilaSequencial { 
    private:
        int* dados;
        int tamMax;
        int inicio;
        int fim;
        int nElementos;

    public:
        // Criar uma fila vazia
        FilaSequencial(){
            inicio = 0;
            fim = -1;
            nElementos = 0;
            tamMax = 100;
            dados = new int[tamMax];
        }

        // Destructor da classe para liberar a memória alocada
        ~FilaSequencial() {
            delete[] dados;
        }

        //Testar se a fila está vazia
        bool vazia(){
            if(nElementos==0){
                return true;
            }else{
                return false;
            }
        }

        //Verificar se a fila está cheia
        bool cheia(){
            if(nElementos==tamMax){
                return true;
            }else{
                return false;
            }
        }

        //Obter o tamanho da fila
        int getTamanho(){
            return nElementos;
        }

        //Consultar o elemento da frente da fila
        int primeiro(){
            if(vazia()){
                return -1; // FILA VAZIA
            }else{
                return dados[inicio];
            }
        }

        //Inserir um novo elemento no fundo da fila
        bool insere(int valor){
            if(cheia()){
                return false;
            }
                fim = (fim + 1) % tamMax; // APLICANDO O CONCEITO DE CIRCULARIDADE PARA NÃO PERDER OS ESPAÇOS SOBRANDO
                dados[fim] = valor;
                nElementos++;
                return true;
            
        }

        //Remover o elemento da frente da fila
        int remove(){
            if(vazia()){
                return -1;
            }

            int res = primeiro();
            inicio = (inicio + 1) % tamMax; // APLICANDO O CONCEITO DE CIRCULARIDADE PARA NÃO PERDER OS ESPAÇOS SOBRANDO
            nElementos--;
            return res;
        }

};