/*
    Nome: An�lise de dois N�meros inteiros
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio dois n�meros inteiros, 
	realiza uma an�lise dos n�meros e retorna um resultado com base nas seguintes regras:
    - Se o primeiro n�mero for maior que o segundo, retorna a diferen�a entre eles.
    - Se o primeiro n�mero for menor que o segundo, retorna o produto dos dois n�meros.
    - Se os n�meros forem iguais, retorna a soma deles.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da

// Fun��o para analisar os n�meros e retornar o resultado
int analisarNumeros(int num1, int num2) {
    if (num1 > num2) {
        return num1 - num2; // diferen�a entre num1 e num2
    } else if (num1 < num2) {
        return num1 * num2; // multiplica��o de num1 e num2
    } else {
        return num1 + num2; // soma de num1 e num2
    }
}

int main() {
    int num1, num2;

    // Leitura dos n�meros
    std::cout << "Digite o primeiro n�mero inteiro: ";
    std::cin >> num1;
    std::cout << "Digite o segundo n�mero inteiro: ";
    std::cin >> num2;

    // Chamada da fun��o e obten��o do resultado
    int resultado = analisarNumeros(num1, num2);

    // Impress�o do resultado
    std::cout << "O resultado �: " << resultado << std::endl;

    return 0;
}

