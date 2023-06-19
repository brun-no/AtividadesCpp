/*
    Nome: Ordena��o de Vetor com Bubble Sort
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa implementa o algoritmo de ordena��o Bubble Sort para ordenar um vetor de inteiros em ordem crescente.
*/

#include <iostream> // Biblioteca para entrada e sa�da padr�o
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

#define TAM 8 // Tamanho do vetor

// Fun��o para imprimir o vetor na tela
void imprimeVetor(int vetor[])
{
    int i;
    std::cout << "\n";
    for(i = 0; i < TAM; i++)
        std::cout << "  |" << vetor[i] << "|  ";
}

int main()
{
    int vetor[TAM] = {63, 7, 18, 95, -2, 4, 9, 40};
    int x, y, aux;

    for(x = 0; x < TAM; x++)
    {
        for(y = x + 1; y < TAM; y++)
        {
            imprimeVetor(vetor);

            if(vetor[x] > vetor[y])
            {
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }

    imprimeVetor(vetor);

    return 0;
}

