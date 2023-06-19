/*
    Nome: Autentica��o de Usu�rio
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa verifica a autentica��o de um usu�rio atrav�s de um login e senha.
*/

#include <string.h> // Biblioteca para manipula��o de strings
#include <stdio.h> // Biblioteca padr�o de entrada e sa�da
#include <stdlib.h> // Biblioteca padr�o do sistema

// Declara��o de vari�veis globais
char usuario[20] = "adm";
int senha = 12345;

// Prototipa��o de fun��es
void verificarUsuario();
void verificarSenha(int);

int main()
{
	verificarUsuario();
	return 0;
}

void verificarUsuario()
{
	char user[20];
	int pwd = 0;

	printf("--|login|");
	fflush(stdin);
	gets(user);

	printf("--|senha|");
	scanf("%d", &pwd);

	if (strcmp(user, usuario) == 0)
		verificarSenha(pwd);
	else
	{
		printf("\n|usuario ou senha incorreta!|\n\n");
		verificarUsuario();
	}
}

void verificarSenha(int pwd)
{
	if (senha == pwd)
		puts("Login efetuado com SUCESSO!");
	else
	{
		printf("\n|usuario ou senha incorreta!|\n\n");
		verificarUsuario();
	}
}

