/*
    Nome: Verifica��o de Pal�ndromo
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa verifica se uma palavra digitada pelo usu�rio � um pal�ndromo, ou seja, se pode ser lida da mesma forma tanto da esquerda para a direita quanto da direita para a esquerda.
*/

#include <string.h> // Biblioteca para manipula��o de strings
#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // Declara��o de vari�veis
    char palavra[20];
    int inicio, fim, tam;
    inicio = 0;
    bool palindromo = true;
    
    // Entrada de dados
    printf("Digite uma palavra: ");
    fgets(palavra, 20, stdin);
    palavra[strlen(palavra) - 1] = '\0';
    fflush(stdin);
    
    tam = strlen(palavra);
    fim = tam - 1;
    
    // Verifica��o de pal�ndromo
    for (inicio; inicio <= fim; inicio++)
    {
        if (palavra[inicio] != palavra[fim])
        {
            printf("\nN�o � um pal�ndromo!!");
            palindromo = false;
            break;
        }
        else
        {
            fim--;
        }
    }	
    
    // Resultado da verifica��o
    if (palindromo == true)
    {
        printf("\n� um pal�ndromo!!!");
    }
    
    return 0;
}

