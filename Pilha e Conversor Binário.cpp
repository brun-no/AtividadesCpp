/*
    Nome: Pilha e Conversor Binário
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Programa que implementa uma pilha e um conversor binário.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema
#include <windows.h> // Biblioteca para manipulação de funções do sistema Windows
#include <locale.h> // Biblioteca para configuração do locale em português

// Prototipação das funções
void empilhar(char); // Insere um elemento na pilha
char desempilhar(); // Remove um elemento da pilha
int estaVazia(); // Retorna 1 se a pilha estiver vazia, 0 caso contrário
int estaCheia(); // Retorna 1 se a pilha estiver cheia, 0 caso contrário
char topo(); // Retorna o elemento no topo da pilha
void listarPilha(); // Mostra os elementos da pilha
void converterBinario(); // Converte um número para sua representação binária
void exibirNumeroBinario(); // Exibe o número binário convertido

int topoVazio = -1; // A pilha começa em -1 quando o topo é -1, a pilha está vazia
char pilha[5]; // Vetor de 5 elementos para armazenar os dados da pilha

int main()
{
    while (1)
    {
        setlocale(LC_ALL, "Portuguese"); // Configuração do locale para português

        int menu = 0; // A variável menu recebe zero
        printf("1 - Inserir na pilha\n2 - Retirar da pilha\n3 - Exibir a pilha\n4 - Conversor binário\n5 - Sair");
        printf("\nOpção: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                char elemento; // Variável elemento
                printf("Digite o elemento que deseja inserir: ");
                scanf(" %c", &elemento); // Lê o caractere
                empilhar(elemento); // A função empilhar faz a verificação para inserir o elemento na pilha
                break;

            case 2:
                desempilhar(); // A função desempilhar remove um elemento da pilha
                break;

            case 3:
                listarPilha(); // Função para listar a pilha
                break;

            case 4:
                converterBinario();
                break;

            case 5:
                exit(0); // Para o funcionamento é necessário a inclusão da biblioteca stdlib
                break;

            default:
                puts("Opção inválida"); // Caso a opção seja diferente de 1, 2, 3, 4
                break;
        } // Fim do switch

        puts("\nPressione qualquer tecla para continuar");
        getch(); // Pausa e espera por um caractere
        system("cls"); // Comando para limpar a tela, para funcionar é necessário a biblioteca windows.h
    } // Fim do while

    return 0;
}

// Funções
void empilhar(char elem)
{
    // Se o retorno for 1, a pilha está cheia
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
    // Testa se a pilha está vazia
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
    // Retorna o elemento que está no topo da pilha
    return pilha[topoVazio];
}

void listarPilha()
{
    for (int i = 0; i <= topoVazio; i++)
        printf("%c|", pilha[i]);
}

void converterBinario()
{
    int numBaseDez = 0; // Número na base dez a ser convertido para a base dois (binário)
    int quoc, resto; // Variáveis quociente e resto
    printf("Digite um número na base 10: ");
    scanf("%d", &numBaseDez);

    while (numBaseDez >= 2)
    {
        quoc = numBaseDez / 2; // Quociente recebe o número base dividido por dois
        resto = numBaseDez - (quoc * 2); // O resto guarda zero ou um
        empilhar(resto); // Guarda o resto na pilha
        numBaseDez = quoc;
    }
    empilhar(numBaseDez);
    exibirNumeroBinario();
}

void exibirNumeroBinario()
{
    puts("Equivalente binário:");
    while (estaVazia() == 0)
    {
        int elemento = desempilhar();
        printf("%d", elemento);
    }
}

