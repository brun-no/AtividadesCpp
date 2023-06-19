/*
Nome: Gerenciador de Lista Encadeada
Autor: @brunno_u
Data: 1X de maio de 20XX
Descricao: Implementação de uma lista encadeada em C++ para organizar informações
*/

#include <iostream> // Biblioteca de entrada e saída padrão
#include <locale.h> // Biblioteca para configurar a localização

using namespace std;

// Definição da estrutura do nó
struct No
{
    string nome;
    int idade;
    float altura;
    No* proximo;
};

// Definição da estrutura da lista encadeada
struct Lista
{
    No* inicio;
    No* fim;
    int tamanho;

    Lista()
    {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
};

// Função responsável por inserir um novo nó no início da lista
void inserirNoInicio(Lista& lista)
{
    No* novoNo = new No;

    cout << "Digite o nome: ";
    cin >> novoNo->nome;
    cout << "Digite a idade: ";
    cin >> novoNo->idade;
    cout << "Digite a altura: ";
    cin >> novoNo->altura;

    novoNo->proximo = lista.inicio;
    lista.inicio = novoNo;

    if (lista.fim == NULL)
        lista.fim = novoNo;

    lista.tamanho++;
}

// Função responsável por inserir um novo nó no fim da lista
void inserirNoFim(Lista& lista)
{
    No* novoNo = new No;

    cout << "Digite o nome: ";
    cin >> novoNo->nome;
    cout << "Digite a idade: ";
    cin >> novoNo->idade;
    cout << "Digite a altura: ";
    cin >> novoNo->altura;

    novoNo->proximo = NULL;

    if (lista.fim == NULL)
    {
        lista.inicio = novoNo;
        lista.fim = novoNo;
    }
    else
    {
        lista.fim->proximo = novoNo;
        lista.fim = novoNo;
    }

    lista.tamanho++;
}

// Função responsável por exibir os elementos da lista
void exibirLista(const Lista& lista)
{
    No* atual = lista.inicio;

    while (atual != NULL)
    {
        cout << "Nome: " << atual->nome << ", Idade: " << atual->idade << ", Altura: " << atual->altura << endl;
        atual = atual->proximo;
    }
}

// Função responsável por excluir um nó específico da lista
void excluirNo(Lista& lista)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista está vazia." << endl;
        return;
    }

    string nomeExcluir;
    cout << "Digite o nome do nó a ser excluído: ";
    cin >> nomeExcluir;

    No* atual = lista.inicio;
    No* anterior = NULL;

    while (atual != NULL)
    {
        if (atual->nome == nomeExcluir)
        {
            if (atual == lista.inicio)
            {
                lista.inicio = atual->proximo;

                if (lista.fim == atual)
                    lista.fim = NULL;
            }
            else if (atual == lista.fim)
            {
                lista.fim = anterior;
                lista.fim->proximo = NULL;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }

            delete atual;
            lista.tamanho--;

            cout << "Nó excluído com sucesso." << endl;
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    cout << "Nó com o nome '" << nomeExcluir << "' não encontrado." << endl;
}

// Função responsável por remover o primeiro nó da lista
void removerPrimeiroNo(Lista& lista)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista está vazia." << endl;
        return;
    }

    No* primeiro = lista.inicio;
    lista.inicio = primeiro->proximo;

    if (lista.fim == primeiro)
        lista.fim = NULL;

    delete primeiro;
    lista.tamanho--;

    cout << "Primeiro nó removido com sucesso." << endl;
}

// Função responsável por dividir a lista em duas partes
void dividirLista(const Lista& lista, Lista& lista1, Lista& lista2)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista está vazia." << endl;
        return;
    }

    int posicao;
    cout << "Digite a posição para dividir a lista: ";
    cin >> posicao;

    if (posicao <= 0 || posicao > lista.tamanho)
    {
        cout << "Posição inválida." << endl;
        return;
    }

    lista1.inicio = lista.inicio;
    lista1.tamanho = posicao;

    No* atual = lista.inicio;
    No* anterior = NULL;
    int contador = 0;

    while (contador < posicao)
    {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    lista1.fim = anterior;
    lista1.fim->proximo = NULL;

    lista2.inicio = atual;
    lista2.tamanho = lista.tamanho - posicao;
    lista2.fim = lista.fim;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para exibir textos em português
    Lista lista;
    int opcao;
    Lista lista1, lista2;

    do
    {
        cout << "MENU" << endl;
        cout << "1 - Inserir nó no início da lista" << endl;
        cout << "2 - Inserir nó no fim da lista" << endl;
        cout << "3 - Exibir lista" << endl;
        cout << "4 - Excluir nó" << endl;
        cout << "5 - Remover primeiro nó" << endl;
        cout << "6 - Dividir lista" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                inserirNoInicio(lista);
                break;
            case 2:
                inserirNoFim(lista);
                break;
            case 3:
                exibirLista(lista);
                break;
            case 4:
                excluirNo(lista);
                break;
            case 5:
                removerPrimeiroNo(lista);
                break;
            case 6:
                dividirLista(lista, lista1, lista2);

                cout << "Lista 1: ";
                exibirLista(lista1);

                cout << "Lista 2: ";
                exibirLista(lista2);

                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }

        cout << endl;

    } while (opcao != 0);

    return 0;
}

