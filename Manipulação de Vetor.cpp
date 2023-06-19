/*
    Nome: Manipulação de Vetor
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa permite ao usuário digitar 10 números inteiros 
	e realiza diferentes manipulações com o vetor, como exibir os números ímpares, 
	exibir os números nas posições pares, e criar um novo vetor apenas com 
	os números maiores que 10.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português

// Variáveis globais:
int numeros[10];
int tamanho = (sizeof(numeros) / sizeof(int));

// Prototipação das funções:
void exibirNumerosImpares();
void indicePares();
void vetorNovoMaiorQueDez();

int main(){
    setlocale(LC_ALL, "Portuguese"); // Configuração do locale em português
	
	for(int i = 0; i < tamanho; i++){
		printf("Digite o seu %dº número: ", i + 1);
		scanf("%d", &numeros[i]);	
	}
	
	vetorNovoMaiorQueDez();
	
}

void exibirNumerosImpares(){
	for(int i = 0; i < tamanho; i++){
		if(numeros[i] % 2 != 0){
			printf("\nNúmero ímpar: %d", numeros[i]);
		}
	}
}

void indicePares(){
	for(int i = 0; i < tamanho; i = i + 2){
		printf("\nNúmero: %d || Índice: %d", numeros[i], i);
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
		printf("Número novo vetor: %d\n", novoVetor[i]);
	}
	
}

