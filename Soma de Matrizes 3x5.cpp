/*
    Nome: Soma de Matrizes 3x5
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa lê duas matrizes 3x5 do usuário, realiza a soma elemento por elemento
    e exibe a matriz resultante.
*/

#include <iostream>  // Biblioteca de entrada e saída padrão.
using namespace std; // usando o namespace

int main()
{
    int matriz[3][5];
    int matriz2[3][5];
    int Msoma[3][5];
    int l, c; // l = linha / c = coluna

    // Preencher as matrizes
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            cout << "Digite os valores da primeira matriz [" << l << "][" << c << "]: ";
            cin >> matriz[l][c];

            cout << "Digite os valores da segunda matriz [" << l << "][" << c << "]: ";
            cin >> matriz2[l][c];
        }
    }

    // Somar as matrizes e exibir o resultado
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            Msoma[l][c] = matriz[l][c] + matriz2[l][c];
            cout << "\n[" << l << "][" << c << "] = " << Msoma[l][c];
        }
    }

    return 0;
}

