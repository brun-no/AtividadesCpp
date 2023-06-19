/*
    Nome: C�lculo do Fatorial
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa calcula o fatorial utilizando fun��o recursiva 
	para um n�mero inteiro fornecido pelo usu�rio.
*/

#include <iostream>  // Biblioteca padr�o de entrada e sa�da
using namespace std;

// Prot�tipo da fun��o fatorial
double fatorial(int n);

int main()
{
    int numero;
    double f;
  
    cout << "Digite o n�mero que deseja calcular o fatorial: ";
    cin >> numero;
  
    // Chamada da fun��o fatorial
    f = fatorial(numero);
  
    cout << "Fatorial de " << numero << " = " << f;
  
    return 0;
}

// Fun��o recursiva que calcula o fatorial
// de um n�mero inteiro n
double fatorial(int n)
{
    double vfat;
  
    if (n <= 1)
    {
        // Caso base: fatorial de n <= 1 retorna 1
        return 1;
    }
    else
    {
        // Chamada recursiva
        vfat = n * fatorial(n - 1);
        return vfat;
    }
}

