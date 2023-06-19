/*
    Nome: Troca de Valores utilizando ponteiros
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio dois valores A e B,
    exibe os valores originais e, em seguida, troca os valores de A e B
    utilizando ponteiros.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema

// Prototipa��o:
void troca(int*, int*);

int main()
{
    int a, b;
    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Valor de A: %d || Valor de B: %d", a, b);

    troca(&a, &b);

    printf("\n\nValor de A: %d || Valor de B: %d", a, b);
}

void troca(int* ponteiroA, int* ponteiroB)
{
    int aux;
    aux = *ponteiroA;
    *ponteiroA = *ponteiroB;
    *ponteiroB = aux;
}

