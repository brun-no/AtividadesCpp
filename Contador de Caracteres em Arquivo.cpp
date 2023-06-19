/*
    Nome: Contador de Caracteres em Arquivo
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa lê um arquivo especificado pelo usuário e conta o número 
	de caracteres presentes no arquivo, excluindo os espaços em branco. 
	Ele exibe o conteúdo do arquivo e o total de caracteres encontrados.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída

int main()
{
    FILE *fp;
    char arq[100];
    do
    {
        printf("\nDigite o nome do arquivo: ");
        fflush(stdin);
        gets(arq);
    } while (strlen(arq) == 0);

    fp = fopen(arq, "r+");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo");
        fclose(fp);
        return 0;
    }

    char ler;
    int var, total = 0;

    while ((ler = fgetc(fp)) != EOF)
    {
        printf(" %c", ler);
        if (ler != ' ')
        {
            var = ler;
            if (var >= 97 || var <= 122)
            {
                total++;
            }
        }
    }

    printf("\nNumero de caracteres encontrados: %d\n", total);
    rewind(fp);
    fclose(fp);

    return 0;
}
