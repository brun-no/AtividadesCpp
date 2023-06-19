/*
    Nome: Contagem Regressiva com função recursiva
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa faz uma contagem regressiva a partir de um número maior 
	até um número menor, digitados pelo usuário. Ele utiliza uma função recursiva 
	para realizar a contagem regressiva.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema

// Prototipação da função
void regressiva(int, int);

// Função principal
int main()
{
    int numeroUm, numeroDois;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &numeroUm);
    
    printf("Digite o segundo número: ");
    scanf("%d", &numeroDois);
    
    if (numeroUm == numeroDois)
    {
        printf("Impossível fazer contagem regressiva pois os números são iguais!");
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

// Função recursiva para contagem regressiva
void regressiva(int numeroUm, int numeroDois)
{
    if (numeroUm >= numeroDois)
    {
        printf("%d\n", numeroUm);
        regressiva(numeroUm - 1, numeroDois);
    }
}

