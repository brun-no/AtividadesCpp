/*
Nome: Gerenciador de Lista Encadeada
Autor: @brunno_u
Data: 1X de maio de 20XX
Descricao: Implementa��o de uma lista encadeada em C++ para organizar informa��es
*/

#include <iostream> // Biblioteca de entrada e sa�da padr�o
#include <locale.h> // Biblioteca para configurar a localiza��o

using namespace std;

// Defini��o da estrutura do n�
struct No
{
    string nome;
    int idade;
    float altura;
    No* proximo;
};

// Defini��o da estrutura da lista encadeada
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

// Fun��o respons�vel por inserir um novo n� no in�cio da lista
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

// Fun��o respons�vel por inserir um novo n� no fim da lista
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

// Fun��o respons�vel por exibir os elementos da lista
void exibirLista(const Lista& lista)
{
    No* atual = lista.inicio;

    while (atual != NULL)
    {
        cout << "Nome: " << atual->nome << ", Idade: " << atual->idade << ", Altura: " << atual->altura << endl;
        atual = atual->proximo;
    }
}

// Fun��o respons�vel por excluir um n� espec�fico da lista
void excluirNo(Lista& lista)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista est� vazia." << endl;
        return;
    }

    string nomeExcluir;
    cout << "Digite o nome do n� a ser exclu�do: ";
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

            cout << "N� exclu�do com sucesso." << endl;
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    cout << "N� com o nome '" << nomeExcluir << "' n�o encontrado." << endl;
}

// Fun��o respons�vel por remover o primeiro n� da lista
void removerPrimeiroNo(Lista& lista)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista est� vazia." << endl;
        return;
    }

    No* primeiro = lista.inicio;
    lista.inicio = primeiro->proximo;

    if (lista.fim == primeiro)
        lista.fim = NULL;

    delete primeiro;
    lista.tamanho--;

    cout << "Primeiro n� removido com sucesso." << endl;
}

// Fun��o respons�vel por dividir a lista em duas partes
void dividirLista(const Lista& lista, Lista& lista1, Lista& lista2)
{
    if (lista.inicio == NULL)
    {
        cout << "A lista est� vazia." << endl;
        return;
    }

    int posicao;
    cout << "Digite a posi��o para dividir a lista: ";
    cin >> posicao;

    if (posicao <= 0 || posicao > lista.tamanho)
    {
        cout << "Posi��o inv�lida." << endl;
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
    setlocale(LC_ALL, "Portuguese"); // Configura a localiza��o para exibir textos em portugu�s
    Lista lista;
    int opcao;
    Lista lista1, lista2;

    do
    {
        cout << "MENU" << endl;
        cout << "1 - Inserir n� no in�cio da lista" << endl;
        cout << "2 - Inserir n� no fim da lista" << endl;
        cout << "3 - Exibir lista" << endl;
        cout << "4 - Excluir n�" << endl;
        cout << "5 - Remover primeiro n�" << endl;
        cout << "6 - Dividir lista" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma op��o: ";
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
                cout << "Op��o inv�lida." << endl;
                break;
        }

        cout << endl;

    } while (opcao != 0);

    return 0;
}

