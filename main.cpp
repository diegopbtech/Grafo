#include <stdio.h>
#include <iostream>

#include "Fila.cpp"

using namespace std;

int main() {

    int menu = 0;
    FilaSequencial* filaSeq = new FilaSequencial();
    bool nFila = false; // APENAS PARA SIMULAR QUE É NECESSÁRIO CRIAR UMA FILA VAZIA

    do {
        cout << "\nMENU DE OPERAÇÕES\n";
        cout << "1. Criar fila vazia\n";
        cout << "2. Testar se a fila está vazia\n";
        cout << "3. Verificar se a fila está cheia\n";
        cout << "4. Obter o tamanho da fila\n";
        cout << "5. Consultar o elemento da frente da fila\n";
        cout << "6. Inserir um novo elemento no fundo da fila\n";
        cout << "7. Remover o elemento da frente da fila\n";
        cout << "0. Finalizar programa\n";
        cout << "\nSelecione uma opção: ";
        cin >> menu;

        if (menu == 1) {
            system("clear");
            cout << "Fila vazia criada com sucesso!" << endl;
            nFila = true;
        }
        
        else if (menu == 2 && nFila) {
            system("clear");
            if(filaSeq->vazia()){
                cout << "A fila está vazia" << endl;
            }else{
                cout << "A fila não está vazia" << endl;
            }
        }
        
        else if (menu == 3 && nFila) {
            system("clear");
            if(filaSeq->cheia()){
                cout << "A fila está cheia" << endl;
            }else{
                cout << "A fila não está cheia" << endl;
            }
        }
        
        else if (menu == 4 && nFila) {
            system("clear");
            cout << "O tamanho da fila é: " << filaSeq->getTamanho() << endl;
        }
        
        else if (menu == 5 && nFila) {
            system("clear");
            if(filaSeq->vazia()){
                cout << "A fila está vazia" << endl;
            }else {
                cout << "O elemento que se encontra no início da fila é " << filaSeq->primeiro() << endl;
            }
        }

        else if (menu == 6 && nFila) {
            system("clear");
           cout << "Adiciona um valor no fim da fila: ";
           int valor;
           cin >> valor;
           filaSeq->insere(valor);
           cout << "O valor " << valor << " foi inserido ao fim da lista com sucesso!" << endl;
        }

        else if (menu == 7 && nFila) {
            system("clear");
            cout << "O valor " << filaSeq->primeiro() << " foi removido com sucesso!" << endl;
            filaSeq->remove();
        }

        else if (!nFila){
            system("clear");
            cout << "Você precisa criar uma fila primeiro" << endl;
        }

        else {
            system("clear");
            cout << "Opção inválida!" << endl;
        }

    } while (menu != 0);

    system("clear");

    return 0;

}