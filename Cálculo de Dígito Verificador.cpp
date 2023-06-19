/*
    Nome: Cálculo de Dígito Verificador
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa calcula o dígito verificador de um valor informado pelo usuário.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português
#include <string.h> // Biblioteca para manipulação de strings

int calculaDV(int computa); // Função para calcular o dígito verificador

int calculaDV(int computa)
{
    int dez, mediano, onze, solucao;

    dez = computa * 10;
    mediano = dez / 11;
    onze = mediano * 11;
    solucao = dez - onze;

    return solucao;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para Português

    printf("================================================================================\n");
    printf("Desenvolvido Por:\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("=================================================================================\n\n");
    printf("Termo de Uso e Responsabilidade\n");
    printf("O programa a seguir não salva nem armazena senhas,\nSendo seu uso de total responsabilidade do usuário.\n");
    printf("\n");
    printf("Ao iniciar você informa que leu e concorda com os termos de uso e responsabilidade.\n");
    system("pause");
    system("cls");

    char defini[3000], texto[30], fim[] = "FIM", converte[2] = {'\0', '\0'};
    int texto2 = 0, texto1 = 0, i, variavel = 9, valor = 0, valor1 = 0, dvCalculado, digito;

    do
    {
        printf("\nMENU:\n");
        printf(" -> Digite um valor de até 30 números\n");
        printf(" -> Digite 'FIM' para encerrar o programa\n\n");
        fgets(defini, 3000, stdin);
        defini[strlen(defini) - 1] = '\0';
        texto2 = strlen(defini);
        strcpy(texto, defini);
        strupr(texto);
        
        if (texto2 > 30)
        {
            printf("\n\nVocê digitou mais de 30 caracteres\n");
            return 0;
        }

        texto1 = atoi(texto);
        
        if (texto1 == 0 && strcmp(texto, fim) != 0)
        {
            printf("\nAtenção!!! Valor informado inválido.\n");
        }

        if (variavel != 0)
        {
            valor1 = 0;
            variavel = 9;
        }

        for (i = strlen(texto) - 1; i >= 0; i--)
        {
            converte[0] = texto[i];
            valor = atoi(converte) * variavel;
            variavel--;
            valor1 = valor + valor1;

            if (variavel <= 1)
            {
                variavel = 9;
            }
        }

        digito = calculaDV(valor1);

        if (digito == -1)
        {
            printf("\nDV calculado com sucesso: %s - 1\n\n", texto);
        }
        else if (digito > 0)
        {
            printf("\nDV calculado com sucesso: %s - %d\n\n", texto, digito);
        }
        else if (digito == 0 && strcmp(texto, fim) != 0 && texto1 != 0)
        {
            printf("\nDV calculado com sucesso: %s - 0\n\n", texto);
        }

    } while (strcmp(texto, fim) != 0);

    printf("\n--------------------------------\n");
    printf("\nPrograma finalizado com sucesso!\n");

    return 0;
}

