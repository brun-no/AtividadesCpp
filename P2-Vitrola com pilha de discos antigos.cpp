#include <iostream> // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings
#include <stack>  // Biblioteca para implementação da estrutura de pilha (stack)
#include <locale.h> // Biblioteca para suporte a caracteres em português

/*
    Nome: Vitrola Automatizada
    Autor: @brunno_u
    Data: 19 de junho de 2023
    Descrição: Este programa simula uma vitrola automatizada, onde o usuário pode adicionar
    músicas a uma pilha, remover músicas da pilha, verificar se a pilha está vazia
    e obter a próxima música a ser tocada.
*/

// Função para adicionar uma música à pilha (push)
void adicionarMusica(std::stack<std::string>& pilhaMusicas, const std::string& musica) {
    pilhaMusicas.push(musica);
    std::cout << "Música adicionada: " << musica << std::endl;
}

// Função para remover a música que será tocada (pop)
void removerMusica(std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        std::string musica = pilhaMusicas.top();
        pilhaMusicas.pop();
        std::cout << "Música removida: " << musica << std::endl;
    } else {
        std::cout << "A pilha de músicas está vazia." << std::endl;
    }
}

// Função para verificar se a pilha de músicas está vazia
bool pilhaVazia(const std::stack<std::string>& pilhaMusicas) {
    return pilhaMusicas.empty();
}

// Função para verificar se a pilha de músicas está cheia
bool pilhaCheia() {
    // Como a pilha é implementada dinamicamente, não é necessário verificar se está cheia
    return false;
}

// Função para obter a próxima música a ser tocada
std::string proximaMusica(const std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        return pilhaMusicas.top();
    } else {
        return "Não há músicas na pilha.";
    }
}

// Função para exibir a música atualmente sendo tocada
void exibirMusicaAtual(const std::stack<std::string>& pilhaMusicas) {
    if (!pilhaMusicas.empty()) {
        std::string musica = pilhaMusicas.top();
        std::cout << "Música atualmente sendo tocada: " << musica << std::endl;
    } else {
        std::cout << "Não há músicas sendo tocadas no momento." << std::endl;
    }
}

int main() {
    std::stack<std::string> pilhaMusicas;
    int opcao;

    setlocale(LC_ALL, "Portuguese"); // Define o locale para suportar caracteres em português

    do {
        std::cout << "\n--- VITROLA AUTOMATIZADA ---" << std::endl;
        std::cout << "1. Adicionar música" << std::endl;
        std::cout << "2. Remover música" << std::endl;
        std::cout << "3. Verificar pilha vazia" << std::endl;
        std::cout << "4. Verificar próxima música a ser tocada" << std::endl;
        std::cout << "5. Exibir música atualmente sendo tocada" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Digite a opção desejada: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string musica;
                std::cout << "Digite o nome da música: ";
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
                    std::cout << "A pilha de músicas está vazia." << std::endl;
                } else {
                    std::cout << "A pilha de músicas não está vazia." << std::endl;
                }
                break;
            }
            case 4: {
                std::string proxima = proximaMusica(pilhaMusicas);
                std::cout << "Próxima música a ser tocada: " << proxima << std::endl;
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
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    } while (opcao != 6);

    return 0;
}

