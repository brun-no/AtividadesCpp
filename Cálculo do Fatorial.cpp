/*
    Nome: Cálculo do Fatorial
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa calcula o fatorial utilizando função recursiva 
	para um número inteiro fornecido pelo usuário.
*/

#include <iostream>  // Biblioteca padrão de entrada e saída
using namespace std;

// Protótipo da função fatorial
double fatorial(int n);

int main()
{
    int numero;
    double f;
  
    cout << "Digite o número que deseja calcular o fatorial: ";
    cin >> numero;
  
    // Chamada da função fatorial
    f = fatorial(numero);
  
    cout << "Fatorial de " << numero << " = " << f;
  
    return 0;
}

// Função recursiva que calcula o fatorial
// de um número inteiro n
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

