/*
    Nome: Cardápio Dona Teteia
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa apresenta o cardápio de um estabelecimento chamado Dona Teteia e calcula o valor total de uma compra com base na quantidade de itens solicitados.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <locale.h> // Biblioteca para configuração do locale em português

int main(void){
	setlocale(LC_ALL,"");
	int quantidadeHamburguer, quantidadeCerveja, quantidadeDoces, quantidadeRefrigerante, quantidadeBatataFrita;
	float precoHamburguer, precoCerveja, precoDoces, precoRefrigerante, precoBatataFrita, valorTotal;
	precoHamburguer = 8.00; // Preço do hambúrguer
	precoCerveja = 5.00; // Preço da cerveja
	precoDoces = 3.00; // Preço do doce
	precoRefrigerante = 3.00; // Preço do refrigerante
	precoBatataFrita = 12.00; // Preço da batata frita
	printf("CARDAPIO DONA TETEIA:\n");
	printf("BATATA FRITA: R$%0.2f \n", precoBatataFrita);
	printf("HAMBURGUER: R$%0.2f \n", precoHamburguer);
	printf("CERVEJA: R$%0.2f \n", precoCerveja);
	printf("REFRIGERANTE: R$%0.2f \n", precoRefrigerante);
	printf("DOCES: R$%0.2f \n \n \n", precoDoces);
	printf("Digite a quantidade solicitada de batata frita: \n");
	scanf("%i", &quantidadeBatataFrita);
	printf("Digite a quantidade solicitada de hambúrguer: \n");
	scanf("%i", &quantidadeHamburguer);
	printf("Digite a quantidade solicitada de cerveja: \n");
	scanf("%i", &quantidadeCerveja);
	printf("Digite a quantidade solicitada de refrigerante: \n");
	scanf("%i", &quantidadeRefrigerante);
	printf("Digite a quantidade solicitada de doces: \n");
	scanf("%i", &quantidadeDoces);
	valorTotal = (quantidadeBatataFrita * precoBatataFrita) + (quantidadeRefrigerante * precoRefrigerante) + (quantidadeDoces * precoDoces) + (quantidadeHamburguer * precoHamburguer) + (quantidadeCerveja * precoCerveja); // Cálculo do valor total
	printf("\n ::VALOR TOTAL:: \n ::R$%0.2f::\n", valorTotal);
	system("pause");
	return 0;
}

