/*
    Nome: Contador de Caracteres em Arquivo
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa l� um arquivo especificado pelo usu�rio e conta o n�mero 
	de caracteres presentes no arquivo, excluindo os espa�os em branco. 
	Ele exibe o conte�do do arquivo e o total de caracteres encontrados.
*/

#include <string.h> // Biblioteca para manipula��o de strings
#include <stdio.h> // Biblioteca padr�o de entrada e sa�da

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
