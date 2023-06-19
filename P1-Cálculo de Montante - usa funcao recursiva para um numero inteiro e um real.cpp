/*
    Nome: C�lculo de Montante
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descri��o: Este programa solicita ao usu�rio o valor investido, a taxa de acr�scimo mensal 
	e a quantidade de meses.
    Em seguida, ele calcula o valor total do montante ap�s o per�odo informado, 
	utilizando uma fun��o recursiva.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da

// Fun��o recursiva para calcular o valor total do montante
double calcularMontante(double valorInvestido, double taxaAcrescimoMensal, int meses) {
    // Caso base: nenhum m�s restante
    if (meses == 0) {
        return valorInvestido;
    }

    // C�lculo do novo montante ap�s um m�s
    double montante = valorInvestido + (valorInvestido * taxaAcrescimoMensal);
    
    // Chamada recursiva para o pr�ximo m�s
    return calcularMontante(montante, taxaAcrescimoMensal, meses - 1);
}

int main() {
    double valorInvestido, taxaAcrescimoMensal;
    int meses;

    // Leitura dos valores
    std::cout << "Digite o valor investido: ";
    std::cin >> valorInvestido;
    std::cout << "Digite a taxa de acr�scimo mensal: ";
    std::cin >> taxaAcrescimoMensal;
    std::cout << "Digite a quantidade de meses: ";
    std::cin >> meses;

    // Chamada da fun��o recursiva
    double montanteFinal = calcularMontante(valorInvestido, taxaAcrescimoMensal, meses);

    // Impress�o do resultado
    std::cout << "O valor total do montante ap�s " << meses << " meses �: " << montanteFinal << std::endl;

    return 0;
}

