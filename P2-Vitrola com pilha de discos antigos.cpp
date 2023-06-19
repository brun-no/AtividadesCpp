#include <iostream> // Biblioteca padr�o de entrada e sa�da
#include <string.h> // Biblioteca para manipula��o de strings
#include <stack>  // Biblioteca para implementa��o da estrutura de pilha (stack)
#include <locale.h> // Biblioteca para suporte a caracteres em portugu�s

/*
    Nome: Vitrola Automatizada
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descri��o: Este programa simula uma vitrola automatizada, onde o usu�rio pode adicionar
    m�sicas a uma pilha, remover m�sicas da pilha, verificar se a pilha est� vazia
    e obter a pr�xima m�sica a ser tocada.
*/

// Fun��o para adicionar uma m�sica � pilha (push)
void adicionarMusica(std::stack<std::string>& pilhaMusicas, const std::string& musica) {
    pilhaMusicas.push(musica);
    std::cout << "M�sica adicionada: " << musica << std::endl;
}

// Fun��o para remover a m�sica que ser� tocada (pop)
void removerMusica(std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        std::string musica = pilhaMusicas.top();
        pilhaMusicas.pop();
        std::cout << "M�sica removida: " << musica << std::endl;
    } else {
        std::cout << "A pilha de m�sicas est� vazia." << std::endl;
    }
}

// Fun��o para verificar se a pilha de m�sicas est� vazia
bool pilhaVazia(const std::stack<std::string>& pilhaMusicas) {
    return pilhaMusicas.empty();
}

// Fun��o para verificar se a pilha de m�sicas est� cheia
bool pilhaCheia() {
    // Como a pilha � implementada dinamicamente, n�o � necess�rio verificar se est� cheia
    return false;
}

// Fun��o para obter a pr�xima m�sica a ser tocada
std::string proximaMusica(const std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        return pilhaMusicas.top();
    } else {
        return "N�o h� m�sicas na pilha.";
    }
}

// Fun��o para exibir a m�sica atualmente sendo tocada
void exibirMusicaAtual(const std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        std::string musica = pilhaMusicas.top();
        std::cout << "M�sica atualmente sendo tocada: " << musica << std::endl;
    } else {
        std::cout << "N�o h� m�sicas sendo tocadas no momento." << std::endl;
    }
}

int main() {
    std::stack<std::string> pilhaMusicas;
    int opcao;

    setlocale(LC_ALL, "Portuguese"); // Define o locale para suportar caracteres em portugu�s

    do {
        std::cout << "\n--- VITROLA AUTOMATIZADA ---" << std::endl;
        std::cout << "1. Adicionar m�sica" << std::endl;
        std::cout << "2. Remover m�sica" << std::endl;
        std::cout << "3. Verificar pilha vazia" << std::endl;
        std::cout << "4. Verificar pr�xima m�sica a ser tocada" << std::endl;
        std::cout << "5. Exibir m�sica atualmente sendo tocada" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Digite a op��o desejada: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string musica;
                std::cout << "Digite o nome da m�sica: ";
                std::cin.ignore();
                std::getline(std::cin, musica);
                adicionarMusica(pilhaMusicas, musica);
                break;
            }
            case 2: {
                removerMusica(pilhaMusicas);
                break;
            }
            case 3: {
                bool vazia = pilhaVazia(pilhaMusicas);
                if (vazia) {
                    std::cout << "A pilha de m�sicas est� vazia." << std::endl;
                } else {
                    std::cout << "A pilha de m�sicas n�o est� vazia." << std::endl;
                }
                break;
            }
            case 4: {
                std::string proxima = proximaMusica(pilhaMusicas);
                std::cout << "Pr�xima m�sica a ser tocada: " << proxima << std::endl;
                break;
            }
            case 5: {
                exibirMusicaAtual(pilhaMusicas);
                break;
            }
            case 6: {
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            }
            default:
                std::cout << "Op��o inv�lida. Tente novamente." << std::endl;
                break;
        }
    } while (opcao != 6);

    return 0;
}

