/*
    Nome: Ordenação Bubble Sort
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Programa que utiliza o algoritmo Bubble Sort para ordenar um vetor de inteiros em ordem crescente.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída

int main()
{
	int vet[] = {23,4,35,2, -2,3,-4,654}; // Vetor de inteiros a ser ordenado
	int tamanho = (sizeof(vet)/sizeof(int)) - 1; // Tamanho do vetor
	int aux = 0; // Variável auxiliar para a troca de elementos

	for(int j = tamanho; j > 0; j--)
	{
		for(int k = 0; k < j; k++)
		{
			if(vet[k] > vet[k+1]) // Verifica se o elemento atual é maior que o próximo
			{
				aux = vet[k];
				vet[k] = vet[k+1];
				vet[k+1] = aux;
			}
		}
	}

	for(int l = 0; l <= tamanho; l++)
	{
		printf("%d |" , vet[l]); // Imprime o vetor ordenado
	}
	
	return 0;
}

