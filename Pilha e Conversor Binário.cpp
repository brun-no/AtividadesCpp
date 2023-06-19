/*
    Nome: Pilha e Conversor Bin�rio
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Programa que implementa uma pilha e um conversor bin�rio.
*/

#include <string.h> // Biblioteca para manipula��o de strings
#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <windows.h> // Biblioteca para manipula��o de fun��es do sistema Windows
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

// Prototipa��o das fun��es
void empilhar(char); // Insere um elemento na pilha
char desempilhar(); // Remove um elemento da pilha
int estaVazia(); // Retorna 1 se a pilha estiver vazia, 0 caso contr�rio
int estaCheia(); // Retorna 1 se a pilha estiver cheia, 0 caso contr�rio
char topo(); // Retorna o elemento no topo da pilha
void listarPilha(); // Mostra os elementos da pilha
void converterBinario(); // Converte um n�mero para sua representa��o bin�ria
void exibirNumeroBinario(); // Exibe o n�mero bin�rio convertido

int topoVazio = -1; // A pilha come�a em -1 quando o topo � -1, a pilha est� vazia
char pilha[5]; // Vetor de 5 elementos para armazenar os dados da pilha

int main()
{
    while (1)
    {
        setlocale(LC_ALL, "Portuguese"); // Configura��o do locale para portugu�s

        int menu = 0; // A vari�vel menu recebe zero
        printf("1 - Inserir na pilha\n2 - Retirar da pilha\n3 - Exibir a pilha\n4 - Conversor bin�rio\n5 - Sair");
        printf("\nOp��o: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                char elemento; // Vari�vel elemento
                printf("Digite o elemento que deseja inserir: ");
                scanf(" %c", &elemento); // L� o caractere
                empilhar(elemento); // A fun��o empilhar faz a verifica��o para inserir o elemento na pilha
                break;

            case 2:
                desempilhar(); // A fun��o desempilhar remove um elemento da pilha
                break;

            case 3:
                listarPilha(); // Fun��o para listar a pilha
                break;

            case 4:
                converterBinario();
                break;

            case 5:
                exit(0); // Para o funcionamento � necess�rio a inclus�o da biblioteca stdlib
                break;

            default:
                puts("Op��o inv�lida"); // Caso a op��o seja diferente de 1, 2, 3, 4
                break;
        } // Fim do switch

        puts("\nPressione qualquer tecla para continuar");
        getch(); // Pausa e espera por um caractere
        system("cls"); // Comando para limpar a tela, para funcionar � necess�rio a biblioteca windows.h
    } // Fim do while

    return 0;
}

// Fun��es
void empilhar(char elem)
{
    // Se o retorno for 1, a pilha est� cheia
    if (estaCheia() == 1)
        puts("\n\n ===> Pilha cheia - stack overflow");
    else
    {
        topoVazio++;
        pilha[topoVazio] = elem;
    }
}

char desempilhar()
{
    // Testa se a pilha est� vazia
    if (estaVazia() == 1)
        puts("===> Pilha vazia!");
    else
    {
        char elemento;
        elemento = pilha[topoVazio];
        topoVazio--;
        return elemento;
    }
}

int estaVazia()
{
    // Se topoVazio for igual a -1, retorna 1 (verdadeiro)
    if (topoVazio == -1)
        return 1; // Retorna verdadeiro
    else
        return 0; // Retorna falso
}

int estaCheia()
{
    // Se topoVazio for igual a 4, retorna 1 (verdadeiro)
    if (topoVazio == 4)
        return 1; // Retorna verdadeiro
    else
        return 0; // Retorna falso
}

char topo()
{
    // Retorna o elemento que est� no topo da pilha
    return pilha[topoVazio];
}

void listarPilha()
{
    for (int i = 0; i <= topoVazio; i++)
        printf("%c|", pilha[i]);
}

void converterBinario()
{
    int numBaseDez = 0; // N�mero na base dez a ser convertido para a base dois (bin�rio)
    int quoc, resto; // Vari�veis quociente e resto
    printf("Digite um n�mero na base 10: ");
    scanf("%d", &numBaseDez);

    while (numBaseDez >= 2)
    {
        quoc = numBaseDez / 2; // Quociente recebe o n�mero base dividido por dois
        resto = numBaseDez - (quoc * 2); // O resto guarda zero ou um
        empilhar(resto); // Guarda o resto na pilha
        numBaseDez = quoc;
    }
    empilhar(numBaseDez);
    exibirNumeroBinario();
}

void exibirNumeroBinario()
{
    puts("Equivalente bin�rio:");
    while (estaVazia() == 0)
    {
        int elemento = desempilhar();
        printf("%d", elemento);
    }
}

