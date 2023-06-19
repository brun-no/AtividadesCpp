/*
    Nome: C�lculo de D�gito Verificador
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa calcula o d�gito verificador de um valor informado pelo usu�rio.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s
#include <string.h> // Biblioteca para manipula��o de strings

int calculaDV(int computa); // Fun��o para calcular o d�gito verificador

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
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para Portugu�s

    printf("================================================================================\n");
    printf("Desenvolvido Por:\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("NOME, RA: XXXXXXXX\n");
    printf("=================================================================================\n\n");
    printf("Termo de Uso e Responsabilidade\n");
    printf("O programa a seguir n�o salva nem armazena senhas,\nSendo seu uso de total responsabilidade do usu�rio.\n");
    printf("\n");
    printf("Ao iniciar voc� informa que leu e concorda com os termos de uso e responsabilidade.\n");
    system("pause");
    system("cls");

    char defini[3000], texto[30], fim[] = "FIM", converte[2] = {'\0', '\0'};
    int texto2 = 0, texto1 = 0, i, variavel = 9, valor = 0, valor1 = 0, dvCalculado, digito;

    do
    {
        printf("\nMENU:\n");
        printf(" -> Digite um valor de at� 30 n�meros\n");
        printf(" -> Digite 'FIM' para encerrar o programa\n\n");
        fgets(defini, 3000, stdin);
        defini[strlen(defini) - 1] = '\0';
        texto2 = strlen(defini);
        strcpy(texto, defini);
        strupr(texto);
        
        if (texto2 > 30)
        {
            printf("\n\nVoc� digitou mais de 30 caracteres\n");
            return 0;
        }

        texto1 = atoi(texto);
        
        if (texto1 == 0 && strcmp(texto, fim) != 0)
        {
            printf("\nAten��o!!! Valor informado inv�lido.\n");
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

