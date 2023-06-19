/*
    Nome: Contagem Regressiva - com fun��o recursiva
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descri��o: Este programa solicita ao usu�rio um n�mero inteiro maior que zero e,
	 em seguida, realiza uma contagem regressiva a partir desse n�mero utilizando
	  uma fun��o recursiva.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da

// Fun��o recursiva para a contagem regressiva
void contagemRegressiva(int numero) {
    // Caso base: n�mero atinge o valor negativo
    if (numero < 0) {
        std::cout << numero << std::endl;
        return;
    }

    // Imprime o n�mero atual e chama a fun��o novamente com o pr�ximo n�mero
    std::cout << numero << std::endl;
    contagemRegressiva(numero - 1);
}

int main() {
    int numero;

    // Leitura do n�mero
    std::cout << "Digite um n�mero inteiro maior que zero: ";
    std::cin >> numero;

    // Chamada da fun��o recursiva
    contagemRegressiva(numero);

    return 0;
}

