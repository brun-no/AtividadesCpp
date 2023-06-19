/*
    Nome: Preenchimento de Matriz com 16 numeros
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário que digite 16 números inteiros.
    Em seguida, ele preenche uma matriz quadrada de tamanho 4x4 com os números fornecidos
    e imprime tanto o conteúdo do vetor quanto o conteúdo da matriz.
*/

#include <iostream> // Biblioteca padrão de entrada e saída
#include <locale.h> // Biblioteca para configuração do locale em português

int main() {
    setlocale(LC_ALL, ""); // Configuração do locale para suporte a caracteres especiais em português

    const int tamanho = 4; // Tamanho da matriz quadrada (4x4)
    const int tamanhoVetor = tamanho * tamanho;

    int vetor[tamanhoVetor]; // Vetor para armazenar os números
    int matriz[tamanho][tamanho]; // Matriz quadrada

    // Leitura dos números e armazenamento no vetor
    std::cout << "Digite 16 números inteiros:\n";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cin >> vetor[i];
    }

    // Preenchimento da matriz com os números do vetor
    int posicao = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = vetor[posicao];
            posicao++;
        }
    }

    // Impressão do conteúdo do vetor
    std::cout << "Vetor:\n";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    // Impressão do conteúdo da matriz
    std::cout << "Matriz:\n";
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

