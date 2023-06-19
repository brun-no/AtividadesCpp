/*
    Nome: Autenticação de Usuário
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa verifica a autenticação de um usuário através de um login e senha.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão do sistema

// Declaração de variáveis globais
char usuario[20] = "adm";
int senha = 12345;

// Prototipação de funções
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

