/*
    Nome: Matriz Triangular Superior
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário a quantidade de linhas e colunas
	 de uma matriz quadrada. Em seguida, o usuário insere os valores para a matriz, 
	 porém, apenas os elementos localizados acima da diagonal principal são solicitados.
	  A matriz resultante, que é a matriz triangular superior, é exibida na tela.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português

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
                printf("Digite o valor da Matriz para a posição linha %d e coluna %d: ", linha + 1, coluna + 1);
                scanf("%d", &Matriz[linha][coluna]);	
            } 
            else
            {
                Matriz[linha][coluna] = 0;
            }
        }
    }
    
    printf("\nSua Matriz triangular superior será:\n\n");
    
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

