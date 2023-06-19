/*
    Nome: Troca utilizando ponteiros exibe o conteúdo e o endereço antes e depois da troca
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa realiza a troca de valores entre duas variáveis utilizando ponteiros.
	 Ele exibe o conteúdo e o endereço das variáveis antes e depois da troca.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português

void troca(int *, int *); // Prototipação da Função

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para caracteres especiais em português

    int a, b;
    a = 5;
    b = 8;

    printf("Conteúdo A: %d", a);
    printf("\nEndereço de A: %p", &a);
    printf("\nConteúdo B: %d", b);
    printf("\nEndereço de B: %p", &b);

    troca(&a, &b); // Chama a Função

    printf("\n\nConteúdo A depois da troca: %d", a);
    printf("\nEndereço de A: %p", &a);
    printf("\nConteúdo B depois da troca: %d", b);
    printf("\nEndereço de B: %p", &b);

    return 0;
}

// Função para troca de valores utilizando ponteiros
void troca(int *a, int *b)
{
    printf("\nConteúdo apontado por *a: %d", *a);
    printf("\nConteúdo apontado por *b: %d", *b);
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

