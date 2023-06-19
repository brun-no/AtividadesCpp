/*
    Nome: Busca Logarítmica em Vetor Ordenado com Merge Sort
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa realiza a busca logarítmica em um vetor ordenado de caracteres.
	 Ele utiliza o algoritmo de ordenação Merge Sort para ordenar o vetor e, em seguida, 
	 realiza a busca logarítmica pelo caractere fornecido pelo usuário.
*/

#include <iostream> // Biblioteca padrão de entrada e saída
#include <locale.h> // Biblioteca para configuração do locale em português

// Função para realizar a ordenação do vetor usando o algoritmo Merge Sort
void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    // Vetores temporários para armazenar as partes divididas do vetor original
    int vetorEsquerdo[tamanho1], vetorDireito[tamanho2];

    // Copiar os dados para os vetores temporários
    for (int i = 0; i < tamanho1; i++) {
        vetorEsquerdo[i] = vetor[inicio + i];
    }
    for (int j = 0; j < tamanho2; j++) {
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    // Combinar os vetores temporários de volta ao vetor original de forma ordenada
    int i = 0, j = 0, k = inicio;
    while (i < tamanho1 && j < tamanho2) {
        if (vetorEsquerdo[i] <= vetorDireito[j]) {
            vetor[k] = vetorEsquerdo[i];
            i++;
        } else {
            vetor[k] = vetorDireito[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes, se houver, do vetorEsquerdo[]
    while (i < tamanho1) {
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes, se houver, do vetorDireito[]
    while (j < tamanho2) {
        vetor[k] = vetorDireito[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordenar a metade esquerda do vetor
        mergeSort(vetor, inicio, meio);
        
        // Ordenar a metade direita do vetor
        mergeSort(vetor, meio + 1, fim);

        // Combinar as duas metades ordenadas
        merge(vetor, inicio, meio, fim);
    }
}

// Função para realizar a busca logarítmica no vetor e retornar a posição do caractere
int buscaLogaritmica(char vetor[], char caractere, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verificar se o caractere está na posição do meio
        if (vetor[meio] == caractere) {
            return meio;
        }
        // Se o caractere for menor do que o do meio, buscar na metade esquerda do vetor
        else if (vetor[meio] > caractere) {
            return buscaLogaritmica(vetor, caractere, inicio, meio - 1);
        }
        // Se o caractere for maior do que o do meio, buscar na metade direita do vetor
        else {
            return buscaLogaritmica(vetor, caractere, meio + 1, fim);
        }
    }
    // Caractere não encontrado
    return -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para caracteres especiais em português

    char vetor[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
    char caractere;

    // Leitura do caractere a ser buscado
    std::cout << "Digite o caractere a ser buscado: ";
    std::cin >> caractere;

    // Ordenação do vetor usando o algoritmo Merge Sort
    mergeSort(vetor, 0, 19);

    // Realização da busca logarítmica
    int posicao = buscaLogaritmica(vetor, caractere, 0, 19);

    if (posicao != -1) {
        std::cout << "O caractere '" << caractere << "' foi encontrado na posição " << posicao << std::endl;
    } else {
        std::cout << "O caractere '" << caractere << "' não foi encontrado no vetor." << std::endl;
    }

    return 0;
}

