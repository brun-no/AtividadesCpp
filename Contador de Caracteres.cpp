/*
    Nome: Contador de Caracteres
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Programa para contar a quantidade de n�meros, vogais, consoantes e s�mbolos em um arquivo.
*/

#include <string.h> // Biblioteca para manipula��o de strings
#include <stdio.h> // Biblioteca padr�o de entrada e sa�da

int main() 
{
	// Declara um ponteiro de arquivo:
	FILE *fp;
	
	// Declara uma vari�vel para guardar o nome do arquivo:
	char nomeArquivo[100];	
	
	// Vari�vel para passar caracter por caracter:
	char caractere;
	
	// Vari�veis para guardar a quantidade de letras/s�mbolos:
	int qtdNumeros = 0;
	int qtdVogais = 0;
	int qtdConsoantes = 0;
	int qtdSimbolos = 0;

	// La�o de repeti��o para garantir a entrada do nome do arquivo:
	do{
		// Faz a leitura do nome do arquivo:
		printf("Digite o nome do arquivo: ");
		fflush(stdin);
		gets(nomeArquivo);
		
	}while(strlen(nomeArquivo) == 0); // Fim do la�o
	
	// Abre o arquivo em modo leitura:
	fp = fopen(nomeArquivo, "r");
	
	// Faz um la�o para percorrer todo o arquivo:
	while((caractere = fgetc(fp)) != EOF){
		// Verifica se � um n�mero:
		if(caractere >= '0' && caractere <= '9'){
			qtdNumeros++;
		}
		// Verifica se � uma vogal (mai�scula ou min�scula):
		else if(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U' || caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
			qtdVogais++;
		}
		// Verifica se � uma letra (mai�scula ou min�scula):
		else if((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')){
			qtdConsoantes++;
		}
		// Conta a quantidade de s�mbolos (exceto quebras de linha):
		else if(caractere != '\n'){
			qtdSimbolos++;
		}
	}
	
	// Imprime o resultado na tela:
	printf("\nO seu arquivo tem:\n\n%d n�meros.\n%d vogais\n%d consoantes\n%d s�mbolos.", qtdNumeros, qtdVogais, qtdConsoantes, qtdSimbolos);
	
	// Fecha o arquivo:
	fclose(fp);
}

