/*
    Nome: Lista Duplamente Encadeada
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa implementa uma lista duplamente encadeada, 
	permitindo a inserção de nós no início da lista e exibindo os dados armazenados
	 em cada nó, juntamente com os endereços dos nós adjacentes.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema

typedef struct node{
	
	char nome[100];
	node* proximo = NULL;
	node* anterior = NULL;
	
};

// Início da lista:
node* listaInicio = NULL;

// Criar novo nó:
node* novoNode = NULL;

// Prototipação:
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

