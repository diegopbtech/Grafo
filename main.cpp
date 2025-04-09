#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "Grafo.cpp"

Grafo carregar(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    string line;
    getline(file, line); // Insere o valor da primeira linha a variável line
    int n = stoi(line); // Converte o valor dessa linha para um inteiro e atribui a variável que irá determinar o número de vértices
    Grafo g(n); //Inicializa um grafo com n vértices

    int l = 0;
    // Loop para pegar todas as linhas após a primeira
    while (getline(file, line) && l < n) {
        stringstream ss(line);
        string token;
        int c = 0;

        while (getline(ss, token, '\t') && c < n) {
            int valor = stoi(token);
            if (valor != 0 && c < n && l < n) {
                if (c > l) {
                    g.adicionarAresta(l, c, valor);
                }
            }
            c++;
        }
        l++;
    }

    return g;
}

int main() {

    int menu = 0;

    do {
        cout << "\nMENU DE TESTES\n";
        cout << "1. Abrir arquivo pcv4\n";
        cout << "2. Abrir arquivo pcv10\n";
        cout << "3. Abrir arquivo pcv50\n";
        cout << "4. Abrir arquivo pcv177\n";
        cout << "0. Finalizar programa\n";
        cout << "\nSelecione uma opção: ";
        cin >> menu;

        if (menu == 1) {
            system("clear");
            Grafo g = carregar("pcv4.txt");
            g.exibir();
        }

        else if (menu == 2){
            system("clear");
            Grafo g = carregar("pcv10.txt");
            g.exibir();
        }

        else if (menu == 3){
            system("clear");
            Grafo g = carregar("pcv50.txt");
            g.exibir();
        }

        else if (menu == 4){
            system("clear");
            Grafo g = carregar("pcv177.txt");
            g.exibir();
        }

        else {
            system("clear");
            cout << "Opção inválida!" << endl;
        }

    } while (menu != 0);

    system("clear");

    return 0;

}