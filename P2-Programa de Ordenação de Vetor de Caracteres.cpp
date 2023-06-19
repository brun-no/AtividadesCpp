/*
    Nome: Programa de Ordena��o de Vetor de Caracteres
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descri��o: Este programa recebe um vetor de caracteres representando o nome de um aluno,
    imprime o vetor original, ordena o vetor em ordem crescente e decrescente
    ignorando diferen�as de mai�sculas e min�sculas, e imprime os vetores ordenados.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <algorithm> // Biblioteca para ordena��o

// Fun��o para imprimir o vetor de caracteres
void imprimirVetor(const char vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

// Fun��o de compara��o para ordena��o crescente
bool compararCrescente(char a, char b) {
    return std::tolower(a) < std::tolower(b);
}

// Fun��o de compara��o para ordena��o decrescente
bool compararDecrescente(char a, char b) {
    return std::tolower(a) > std::tolower(b);
}

// Fun��o para ordenar o vetor de caracteres em ordem crescente ou decrescente
void ordenarVetor(char vetor[], int tamanho, bool crescente) {
    if (crescente) {
        std::sort(vetor, vetor + tamanho, compararCrescente);
    } else {
        std::sort(vetor, vetor + tamanho, compararDecrescente);
    }
}

int main() {
    const int tamanho = 11; // Tamanho do vetor
    char nomeAluno[tamanho] = {'P', 'e', 'd', 'r', 'o', ' ', 'P', 'a', 'u', 'l', 'o'};

    std::cout << "Nome do aluno: ";
    imprimirVetor(nomeAluno, tamanho);

    std::cout << "\nVetor original:" << std::endl;
    imprimirVetor(nomeAluno, tamanho);

    std::cout << "\nVetor em ordem crescente:" << std::endl;
    ordenarVetor(nomeAluno, tamanho, true);
    imprimirVetor(nomeAluno, tamanho);

    std::cout << "\nVetor em ordem decrescente:" << std::endl;
    ordenarVetor(nomeAluno, tamanho, false);
    imprimirVetor(nomeAluno, tamanho);

    return 0;
}


