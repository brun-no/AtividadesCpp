/*
    Nome: Contagem Regressiva - com função recursiva
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descrição: Este programa solicita ao usuário um número inteiro maior que zero e,
	 em seguida, realiza uma contagem regressiva a partir desse número utilizando
	  uma função recursiva.
*/

#include <iostream> // Biblioteca padrão de entrada e saída

// Função recursiva para a contagem regressiva
void contagemRegressiva(int numero) {
    // Caso base: número atinge o valor negativo
    if (numero < 0) {
        std::cout << numero << std::endl;
        return;
    }

    // Imprime o número atual e chama a função novamente com o próximo número
    std::cout << numero << std::endl;
    contagemRegressiva(numero - 1);
}

int main() {
    int numero;

    // Leitura do número
    std::cout << "Digite um número inteiro maior que zero: ";
    std::cin >> numero;

    // Chamada da função recursiva
    contagemRegressiva(numero);

    return 0;
}

