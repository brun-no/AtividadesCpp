/*
    Nome: Manipula��o de Vetor
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa permite ao usu�rio digitar 10 n�meros inteiros 
	e realiza diferentes manipula��es com o vetor, como exibir os n�meros �mpares, 
	exibir os n�meros nas posi��es pares, e criar um novo vetor apenas com 
	os n�meros maiores que 10.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema
#include <locale.h> // Biblioteca para configura��o do locale em portugu�s

// Vari�veis globais:
int numeros[10];
int tamanho = (sizeof(numeros) / sizeof(int));

// Prototipa��o das fun��es:
void exibirNumerosImpares();
void indicePares();
void vetorNovoMaiorQueDez();

int main(){
    setlocale(LC_ALL, "Portuguese"); // Configura��o do locale em portugu�s
	
	for(int i = 0; i < tamanho; i++){
		printf("Digite o seu %d� n�mero: ", i + 1);
		scanf("%d", &numeros[i]);	
	}
	
	vetorNovoMaiorQueDez();
	
}

void exibirNumerosImpares(){
	for(int i = 0; i < tamanho; i++){
		if(numeros[i] % 2 != 0){
			printf("\nN�mero �mpar: %d", numeros[i]);
		}
	}
}

void indicePares(){
	for(int i = 0; i < tamanho; i = i + 2){
		printf("\nN�mero: %d || �ndice: %d", numeros[i], i);
	}	
}

void vetorNovoMaiorQueDez(){
	
	int novoVetor[10];
	int indiceNovoVetor = 0;
	
	for(int i = 0; i < tamanho; i++){
		if(numeros[i] > 10){
			novoVetor[indiceNovoVetor] = numeros[i];
			indiceNovoVetor++;
		}	
	}
	
	for(int i = 0; i <= indiceNovoVetor; i++){
		printf("N�mero novo vetor: %d\n", novoVetor[i]);
	}
	
}

