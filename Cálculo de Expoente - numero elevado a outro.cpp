/*
    Nome: Cálculo de Expoente
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa calcula a potência de um número elevado 
	a um determinado expoente. O usuário informa o número e o expoente,
	 e o programa exibe o resultado.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída

void expoente(int);

int numA, numB;

int main()
{
    puts("Digite um número: ");
    scanf("%d", &numA);
    
    puts("Digite o expoente: ");
    scanf("%d", &numB);
    
    expoente(numA);
    
    return 0;
}

void expoente(int a)
{
    for (int i = 1; i < numB; i++)
    {
        a = a * numA;
    }
    
    printf("%d elevado a %d é %d", numA, numB, a);
}

