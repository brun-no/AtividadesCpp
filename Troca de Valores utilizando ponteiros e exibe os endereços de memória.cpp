/*
    Nome: Troca de Valores utilizando ponteiros e exibe os endereços de memória
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário dois valores A e B,
    exibe os endereços de memória de A e B, realiza a troca dos valores
    utilizando ponteiros e exibe os novos valores e endereços de memória.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console

void troca(int*, int*);

int main()
{
    int a, b;
	
    printf("Digite o conteúdo para o valor A: ");
    scanf("%d", &a);
    printf("\nEndereço de A: %d", &a);

    printf("\n\nDigite o conteúdo para o valor B: ");
    scanf("%d", &b);
    printf("\nEndereço de B: %d", &b);

    troca(&a, &b);

    printf("\n\nConteúdo de A: %d. Conteúdo de B: %d após a troca", a, b);
    printf("\nEndereço de A: %d", &a);
    printf("\nEndereço de B: %d", &b);

    return 0;
}

void troca(int* a, int* b)
{
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

