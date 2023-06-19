/*
    Nome: Busca Logar�tmica em Vetor Ordenado com Merge Sort
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa realiza a busca logar�tmica em um vetor ordenado de caracteres.
	 Ele utiliza o algoritmo de ordena��o Merge Sort para ordenar o vetor e, em seguida, 
	 realiza a busca logar�tmica pelo caractere fornecido pelo usu�rio.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

// Fun��o para realizar a ordena��o do vetor usando o algoritmo Merge Sort
void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    // Vetores tempor�rios para armazenar as partes divididas do vetor original
    int vetorEsquerdo[tamanho1], vetorDireito[tamanho2];

    // Copiar os dados para os vetores tempor�rios
    for (int i = 0; i < tamanho1; i++) {
        vetorEsquerdo[i] = vetor[inicio + i];
    }
    for (int j = 0; j < tamanho2; j++) {
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    // Combinar os vetores tempor�rios de volta ao vetor original de forma ordenada
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

// Fun��o para realizar a busca logar�tmica no vetor e retornar a posi��o do caractere
int buscaLogaritmica(char vetor[], char caractere, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verificar se o caractere est� na posi��o do meio
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
    // Caractere n�o encontrado
    return -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para caracteres especiais em portugu�s

    char vetor[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
    char caractere;

    // Leitura do caractere a ser buscado
    std::cout << "Digite o caractere a ser buscado: ";
    std::cin >> caractere;

    // Ordena��o do vetor usando o algoritmo Merge Sort
    mergeSort(vetor, 0, 19);

    // Realiza��o da busca logar�tmica
    int posicao = buscaLogaritmica(vetor, caractere, 0, 19);

    if (posicao != -1) {
        std::cout << "O caractere '" << caractere << "' foi encontrado na posi��o " << posicao << std::endl;
    } else {
        std::cout << "O caractere '" << caractere << "' n�o foi encontrado no vetor." << std::endl;
    }

    return 0;
}

