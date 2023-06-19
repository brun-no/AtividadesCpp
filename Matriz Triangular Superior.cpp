/*
    Nome: Matriz Triangular Superior
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio a quantidade de linhas e colunas
	 de uma matriz quadrada. Em seguida, o usu�rio insere os valores para a matriz, 
	 por�m, apenas os elementos localizados acima da diagonal principal s�o solicitados.
	  A matriz resultante, que � a matriz triangular superior, � exibida na tela.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

int main()
{
    int i, j, linha, coluna, l, c;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Informe a quantidade de linhas e colunas da matriz quadrada: ");
    scanf("%d", &i);
    printf("\n");
    
    j = i;
       
    int Matriz[i][j];
     
    for (linha = 0; linha < i; linha++)
    {    	
        for (coluna = 0; coluna < j; coluna++)
        {
            if (linha <= coluna)
            {
                printf("Digite o valor da Matriz para a posi��o linha %d e coluna %d: ", linha + 1, coluna + 1);
                scanf("%d", &Matriz[linha][coluna]);	
            } 
            else
            {
                Matriz[linha][coluna] = 0;
            }
        }
    }
    
    printf("\nSua Matriz triangular superior ser�:\n\n");
    
    for (l = 0; l < i; l++)
    {    	
        for (c = 0; c < j; c++)	
        {
            printf("%d  ", Matriz[l][c]);
        }
        
        printf("\n");
    }
    
    system("pause");
    return 0;
}

