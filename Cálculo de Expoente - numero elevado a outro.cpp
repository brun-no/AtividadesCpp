/*
    Nome: C�lculo de Expoente
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa calcula a pot�ncia de um n�mero elevado 
	a um determinado expoente. O usu�rio informa o n�mero e o expoente,
	 e o programa exibe o resultado.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da

void expoente(int);

int numA, numB;

int main()
{
    puts("Digite um n�mero: ");
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
    
    printf("%d elevado a %d � %d", numA, numB, a);
}

