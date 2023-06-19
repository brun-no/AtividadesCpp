/*
    Nome: Troca utilizando ponteiros exibe o conte�do e o endere�o antes e depois da troca
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa realiza a troca de valores entre duas vari�veis utilizando ponteiros.
	 Ele exibe o conte�do e o endere�o das vari�veis antes e depois da troca.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

void troca(int *, int *); // Prototipa��o da Fun��o

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para caracteres especiais em portugu�s

    int a, b;
    a = 5;
    b = 8;

    printf("Conte�do A: %d", a);
    printf("\nEndere�o de A: %p", &a);
    printf("\nConte�do B: %d", b);
    printf("\nEndere�o de B: %p", &b);

    troca(&a, &b); // Chama a Fun��o

    printf("\n\nConte�do A depois da troca: %d", a);
    printf("\nEndere�o de A: %p", &a);
    printf("\nConte�do B depois da troca: %d", b);
    printf("\nEndere�o de B: %p", &b);

    return 0;
}

// Fun��o para troca de valores utilizando ponteiros
void troca(int *a, int *b)
{
    printf("\nConte�do apontado por *a: %d", *a);
    printf("\nConte�do apontado por *b: %d", *b);
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

