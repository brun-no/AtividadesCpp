/*
    Nome: Lista Duplamente Encadeada
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa implementa uma lista duplamente encadeada, 
	permitindo a inser��o de n�s no in�cio da lista e exibindo os dados armazenados
	 em cada n�, juntamente com os endere�os dos n�s adjacentes.
*/

#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <conio.h> // Biblioteca para manipula��o de entrada no console
#include <stdlib.h> // Biblioteca padr�o do sistema

typedef struct node{
	
	char nome[100];
	node* proximo = NULL;
	node* anterior = NULL;
	
};

// In�cio da lista:
node* listaInicio = NULL;

// Criar novo n�:
node* novoNode = NULL;

// Prototipa��o:
void inserirNovoNode();
void lerValoresNode();
void exibirLista();

int main(){
	
	inserirNovoNode();
	inserirNovoNode();
	inserirNovoNode();
	
	exibirLista();
	
}

void inserirNovoNode(){
	
	novoNode = (node*) malloc(sizeof(node));
	
	lerValoresNode();
	
	if(listaInicio == NULL){
		
		listaInicio = novoNode;
		novoNode->anterior = NULL;
		novoNode->proximo = NULL;
		
	}else{
		
		novoNode->proximo = listaInicio;
		listaInicio->anterior = novoNode;
		novoNode->anterior = NULL;
		listaInicio = novoNode;
		
	}
	
}

void lerValoresNode(){

	printf("Digite seu nome: ");
	fgets(novoNode->nome, 100, stdin);
	
}

void exibirLista(){
	
	for(node* nodeAtual = listaInicio; nodeAtual != NULL; nodeAtual = nodeAtual->proximo){
		
		printf("\nNome: %s", nodeAtual->nome);
		printf("Endereco atual: %p\n", nodeAtual);
		printf("Endereco anterior: %p\n", nodeAtual->anterior);
		printf("Endereco proximo: %p\n\n", nodeAtual->proximo);
		
	}
	
}

