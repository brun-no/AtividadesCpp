/*
    Nome: Preenchimento de Matriz com 16 numeros
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio que digite 16 n�meros inteiros.
    Em seguida, ele preenche uma matriz quadrada de tamanho 4x4 com os n�meros fornecidos
    e imprime tanto o conte�do do vetor quanto o conte�do da matriz.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

int main() {
    setlocale(LC_ALL, ""); // Configura��o do locale para suporte a caracteres especiais em portugu�s

    const int tamanho = 4; // Tamanho da matriz quadrada (4x4)
    const int tamanhoVetor = tamanho * tamanho;

    int vetor[tamanhoVetor]; // Vetor para armazenar os n�meros
    int matriz[tamanho][tamanho]; // Matriz quadrada

    // Leitura dos n�meros e armazenamento no vetor
    std::cout << "Digite 16 n�meros inteiros:\n";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cin >> vetor[i];
    }

    // Preenchimento da matriz com os n�meros do vetor
    int posicao = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = vetor[posicao];
            posicao++;
        }
    }

    // Impress�o do conte�do do vetor
    std::cout << "Vetor:\n";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    // Impress�o do conte�do da matriz
    std::cout << "Matriz:\n";
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

