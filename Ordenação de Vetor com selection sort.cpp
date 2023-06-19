/*
    Nome: Ordena��o de Vetor com selection sort
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa ordena um vetor de inteiros em ordem crescente 
	usando o algoritmo de ordena��o por sele��o (selection sort).
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da

int main()
{
    int vet[] = {2, 124, 46, 74, 123, 68, 8};
    int tamanho = (sizeof(vet) / sizeof(int)) - 1;
    int aux = 0;
    int menor = 0;
    
    for (int j = 0; j < tamanho; j++)
    {
        menor = j;
        
        for (int k = j; k <= tamanho; k++)
        {
            if (vet[menor] > vet[k])
            {
                menor = k;
            }
        }
        
        if (j != menor)
        {
            aux = vet[j];
            vet[j] = vet[menor];
            vet[menor] = aux;
        }
    }
    
    for (int l = 0; l <= tamanho; l++)
    {
        printf("%d |", vet[l]);
    }
    
    return 0;
}

