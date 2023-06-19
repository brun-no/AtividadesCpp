/*
    Nome: Troca de Valores utilizando ponteiros e exibe os endere�os de mem�ria
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio dois valores A e B,
    exibe os endere�os de mem�ria de A e B, realiza a troca dos valores
    utilizando ponteiros e exibe os novos valores e endere�os de mem�ria.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console

void troca(int*, int*);

int main()
{
    int a, b;
	
    printf("Digite o conte�do para o valor A: ");
    scanf("%d", &a);
    printf("\nEndere�o de A: %d", &a);

    printf("\n\nDigite o conte�do para o valor B: ");
    scanf("%d", &b);
    printf("\nEndere�o de B: %d", &b);

    troca(&a, &b);

    printf("\n\nConte�do de A: %d. Conte�do de B: %d ap�s a troca", a, b);
    printf("\nEndere�o de A: %d", &a);
    printf("\nEndere�o de B: %d", &b);

    return 0;
}

void troca(int* a, int* b)
{
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

