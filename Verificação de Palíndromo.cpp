/*
    Nome: Verificação de Palíndromo
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa verifica se uma palavra digitada pelo usuário é um palíndromo, ou seja, se pode ser lida da mesma forma tanto da esquerda para a direita quanto da direita para a esquerda.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // Declaração de variáveis
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
    
    // Verificação de palíndromo
    for (inicio; inicio <= fim; inicio++)
    {
        if (palavra[inicio] != palavra[fim])
        {
            printf("\nNão é um palíndromo!!");
            palindromo = false;
            break;
        }
        else
        {
            fim--;
        }
    }	
    
    // Resultado da verificação
    if (palindromo == true)
    {
        printf("\nÉ um palíndromo!!!");
    }
    
    return 0;
}

