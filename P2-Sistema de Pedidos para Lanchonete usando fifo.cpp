/*
    Nome: Sistema de Pedidos para Lanchonete usando fifo
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descri��o: Este programa simula um sistema de pedidos em uma lanchonete. 
	Os clientes podem fazer pedidos, que s�o adicionados a uma fila de pedidos.
	 Os pedidos s�o encaminhados para a cozinha e, quando conclu�dos, s�o exibidos no painel.
*/

#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <queue>    // Biblioteca para usar fila (queue)

// Fun��o para fazer um novo pedido
void fazerPedido(std::queue<int>& filaPedidos, int numeroPedido) {
    filaPedidos.push(numeroPedido);
    std::cout << "Pedido #" << numeroPedido << " feito com sucesso." << std::endl;
}

// Fun��o para encaminhar um pedido para a cozinha
void encaminharCozinha(std::queue<int>& filaPedidos) {
    if (!filaPedidos.empty()) {
        int numeroPedido = filaPedidos.front();
        filaPedidos.pop();
        std::cout << "Pedido #" << numeroPedido << " encaminhado para a cozinha." << std::endl;
    } else {
        std::cout << "N�o h� pedidos para encaminhar para a cozinha." << std::endl;
    }
}

// Fun��o para concluir um pedido e exibir o n�mero no painel
void concluirPedido(int numeroPedido) {
    std::cout << "Pedido #" << numeroPedido << " conclu�do. Por favor, pegue seu lanche no painel." << std::endl;
}

int main() {
    std::queue<int> filaPedidos;
    int opcao;

    do {
        std::cout << "\n--- LANCHONETE XBURG�O ---" << std::endl;
        std::cout << "1. Fazer pedido" << std::endl;
        std::cout << "2. Encaminhar pedido para a cozinha" << std::endl;
        std::cout << "3. Sair" << std::endl;
        std::cout << "Digite a op��o desejada: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                int numeroPedido;
                std::cout << "Digite o n�mero do pedido: ";
                std::cin >> numeroPedido;
                fazerPedido(filaPedidos, numeroPedido);
                break;
            }
            case 2: {
                encaminharCozinha(filaPedidos);
                break;
            }
            case 3: {
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            }
            default:
                std::cout << "Op��o inv�lida. Tente novamente." << std::endl;
                break;
        }

        // Verifica se h� pedidos conclu�dos para exibir no painel
        if (!filaPedidos.empty()) {
            int numeroPedidoConcluido = filaPedidos.front();
            concluirPedido(numeroPedidoConcluido);
        }
    } while (opcao != 3);

    return 0;
}

