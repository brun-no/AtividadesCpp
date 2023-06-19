/*
    Nome: Cálculo de Montante
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa solicita ao usuário o valor investido, a taxa de acréscimo mensal 
	e a quantidade de meses.
    Em seguida, ele calcula o valor total do montante após o período informado, 
	utilizando uma função recursiva.
*/

#include <iostream> // Biblioteca padrão de entrada e saída

// Função recursiva para calcular o valor total do montante
double calcularMontante(double valorInvestido, double taxaAcrescimoMensal, int meses) {
    // Caso base: nenhum mês restante
    if (meses == 0) {
        return valorInvestido;
    }

    // Cálculo do novo montante após um mês
    double montante = valorInvestido + (valorInvestido * taxaAcrescimoMensal);
    
    // Chamada recursiva para o próximo mês
    return calcularMontante(montante, taxaAcrescimoMensal, meses - 1);
}

int main() {
    double valorInvestido, taxaAcrescimoMensal;
    int meses;

    // Leitura dos valores
    std::cout << "Digite o valor investido: ";
    std::cin >> valorInvestido;
    std::cout << "Digite a taxa de acréscimo mensal: ";
    std::cin >> taxaAcrescimoMensal;
    std::cout << "Digite a quantidade de meses: ";
    std::cin >> meses;

    // Chamada da função recursiva
    double montanteFinal = calcularMontante(valorInvestido, taxaAcrescimoMensal, meses);

    // Impressão do resultado
    std::cout << "O valor total do montante após " << meses << " meses é: " << montanteFinal << std::endl;

    return 0;
}

