/*
    Nome: Regressiva
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário um número e,
    em seguida, realiza uma contagem regressiva a partir desse
    número até o número negativo correspondente.
*/

#include <iostream> // Biblioteca padrão de entrada e saída
#include <locale> // Biblioteca para configuração do locale

using namespace std;

// Prototipação
void regressiva(int);

// Declaração de variável global
int num;

int main()
{
    num = 0; // Atribui 0 à variável num

    // Configuração do locale em português
    setlocale(LC_ALL, "Portuguese");

    cout << "Digite um número: ";
    cin >> num;

    regressiva(num); // Chama a função regressiva

    return 0;
}

void regressiva(int x)
{
    if (x < -num)
        return;

    cout << "\n" << x;
    regressiva(--x);
}

