/*
    Nome: Regressiva
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio um n�mero e,
    em seguida, realiza uma contagem regressiva a partir desse
    n�mero at� o n�mero negativo correspondente.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <locale> // Biblioteca para configura��o do locale

using namespace std;

// Prototipa��o
void regressiva(int);

// Declara��o de vari�vel global
int num;

int main()
{
    num = 0; // Atribui 0 � vari�vel num

    // Configura��o do locale em portugu�s
    setlocale(LC_ALL, "Portuguese");

    cout << "Digite um n�mero: ";
    cin >> num;

    regressiva(num); // Chama a fun��o regressiva

    return 0;
}

void regressiva(int x)
{
    if (x < -num)
        return;

    cout << "\n" << x;
    regressiva(--x);
}

