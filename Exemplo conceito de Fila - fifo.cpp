/*
    Nome: Exemplo conceito de Fila - fifo
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa implementa um gerenciador de fila usando um vetor. 
	Ele permite inserir elementos na fila, retirar elementos da fila e verifica se a 
	fila está vazia ou cheia.
*/

// Bibliotecas
#include <iostream>  // Biblioteca padrão de entrada e saída
using namespace std;

// Prototipação das funções
void inserir(int);
int retirar();
int isEmpty();
int isFull();

// Variáveis Globais
int inicio, fim, total;

// Vetor
int senhas[5]; 

int main() {
    inicio = 0;
    fim = 0;
    total = 0;
    
    inserir(300);
    inserir(258);
    inserir(417);
    inserir(171);
    inserir(555);    
    
    cout << "Conteudo da Fila:" << endl;
    while (isEmpty() == 0)
        cout << "Elemento " << retirar() << endl;
    
    retirar();
    
    return 0;
}

void inserir(int elem) {
    if (isFull() == 1)
        cout << "A fila está cheia!" << endl << endl;
    else {
        senhas[fim] = elem;
        fim++;
        total++;
    }
}

int retirar() {
    if (isEmpty() == 1) {
        cout << "A fila está vazia" << endl;
        return -1;
    } else {
        int elemento = senhas[inicio];
        inicio++;
        total--;
        return elemento;
    }
}

int isEmpty() {
    if (total == 0)
        return 1;
    else 
        return 0;
}

int isFull() {
    if (total == 5)
        return 1;
    else 
        return 0;
}

