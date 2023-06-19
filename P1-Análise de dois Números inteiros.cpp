/*
    Nome: Análise de dois Números inteiros
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário dois números inteiros, 
	realiza uma análise dos números e retorna um resultado com base nas seguintes regras:
    - Se o primeiro número for maior que o segundo, retorna a diferença entre eles.
    - Se o primeiro número for menor que o segundo, retorna o produto dos dois números.
    - Se os números forem iguais, retorna a soma deles.
*/

#include <iostream> // Biblioteca padrão de entrada e saída

// Função para analisar os números e retornar o resultado
int analisarNumeros(int num1, int num2) {
    if (num1 > num2) {
        return num1 - num2; // diferença entre num1 e num2
    } else if (num1 < num2) {
        return num1 * num2; // multiplicação de num1 e num2
    } else {
        return num1 + num2; // soma de num1 e num2
    }
}

int main() {
    int num1, num2;

    // Leitura dos números
    std::cout << "Digite o primeiro número inteiro: ";
    std::cin >> num1;
    std::cout << "Digite o segundo número inteiro: ";
    std::cin >> num2;

    // Chamada da função e obtenção do resultado
    int resultado = analisarNumeros(num1, num2);

    // Impressão do resultado
    std::cout << "O resultado é: " << resultado << std::endl;

    return 0;
}

