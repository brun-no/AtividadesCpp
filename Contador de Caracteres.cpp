/*
    Nome: Contador de Caracteres
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Programa para contar a quantidade de números, vogais, consoantes e símbolos em um arquivo.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída

int main() 
{
	// Declara um ponteiro de arquivo:
	FILE *fp;
	
	// Declara uma variável para guardar o nome do arquivo:
	char nomeArquivo[100];	
	
	// Variável para passar caracter por caracter:
	char caractere;
	
	// Variáveis para guardar a quantidade de letras/símbolos:
	int qtdNumeros = 0;
	int qtdVogais = 0;
	int qtdConsoantes = 0;
	int qtdSimbolos = 0;

	// Laço de repetição para garantir a entrada do nome do arquivo:
	do{
		// Faz a leitura do nome do arquivo:
		printf("Digite o nome do arquivo: ");
		fflush(stdin);
		gets(nomeArquivo);
		
	}while(strlen(nomeArquivo) == 0); // Fim do laço
	
	// Abre o arquivo em modo leitura:
	fp = fopen(nomeArquivo, "r");
	
	// Faz um laço para percorrer todo o arquivo:
	while((caractere = fgetc(fp)) != EOF){
		// Verifica se é um número:
		if(caractere >= '0' && caractere <= '9'){
			qtdNumeros++;
		}
		// Verifica se é uma vogal (maiúscula ou minúscula):
		else if(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U' || caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
			qtdVogais++;
		}
		// Verifica se é uma letra (maiúscula ou minúscula):
		else if((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')){
			qtdConsoantes++;
		}
		// Conta a quantidade de símbolos (exceto quebras de linha):
		else if(caractere != '\n'){
			qtdSimbolos++;
		}
	}
	
	// Imprime o resultado na tela:
	printf("\nO seu arquivo tem:\n\n%d números.\n%d vogais\n%d consoantes\n%d símbolos.", qtdNumeros, qtdVogais, qtdConsoantes, qtdSimbolos);
	
	// Fecha o arquivo:
	fclose(fp);
}

