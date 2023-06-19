/*
    Nome: Contagem Regressiva com fun��o recursiva
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa faz uma contagem regressiva a partir de um n�mero maior 
	at� um n�mero menor, digitados pelo usu�rio. Ele utiliza uma fun��o recursiva 
	para realizar a contagem regressiva.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema

// Prototipa��o da fun��o
void regressiva(int, int);

// Fun��o principal
int main()
{
    int numeroUm, numeroDois;
    
    printf("Digite o primeiro n�mero: ");
    scanf("%d", &numeroUm);
    
    printf("Digite o segundo n�mero: ");
    scanf("%d", &numeroDois);
    
    if (numeroUm == numeroDois)
    {
        printf("Imposs�vel fazer contagem regressiva pois os n�meros s�o iguais!");
    }
    else if (numeroUm > numeroDois)
    {
        regressiva(numeroUm, numeroDois);
    }
    else
    {
        regressiva(numeroDois, numeroUm);
    }
    
    return 0;
}

// Fun��o recursiva para contagem regressiva
void regressiva(int numeroUm, int numeroDois)
{
    if (numeroUm >= numeroDois)
    {
        printf("%d\n", numeroUm);
        regressiva(numeroUm - 1, numeroDois);
    }
}

