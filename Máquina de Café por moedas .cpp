/*
    Nome: Máquina de Café por moedas 
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descrição: Este programa simula uma máquina de café que permite ao usuário inserir moedas
    e selecionar diferentes produtos. Ele acompanha a quantidade de moedas inseridas e o estoque
    de cada produto.
*/

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <locale.h> // Biblioteca para configuração do locale

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para exibição em português

    int nccc, ndcc, nvcc, nqcc, nurc, ncc = 10, ndc = 10, nvc = 10, nqc = 10, nur = 0, cc = 5, dc = 10, vc = 25, qc = 50, ur = 100, cafepuro = 40, cafeleite = 60, chocolate = 70, contcp = 10, contcl = 10, contch = 10, quantdinins, x, quanttroco, inicio, ntur = 0, ntqc = 0, ntvc = 0, ntdc = 0, ntcc = 0;

    for (inicio = 0; inicio >= 0; inicio++)
    {
        printf("Nossa lista de produtos:\nCafé puro - R$0,40\nCafé com leite - R$0,60\nChocolate quente - R$0,70\n\n");
        printf("Para adquirir nossos produtos, primeiramente insira as moedas, digitando respectivamente o número de moedas de:\n");
        printf("\n5 centavos: ");
        scanf("%d", &nccc);
        ncc += nccc;
        printf("10 centavos: ");
        scanf("%d", &ndcc);
        ndc += ndcc;
        printf("25 centavos: ");
        scanf("%d", &nvcc);
        nvc += nvcc;
        printf("50 centavos: ");
        scanf("%d", &nqcc);
        nqc += nqcc;
        printf("1 real: ");
        scanf("%d", &nurc);
        nur += nurc;

        quantdinins = nccc * cc + ndcc * dc + nvcc * vc + nqcc * qc + nurc * ur;

        if (quantdinins == 0)
        {
            printf("\nNenhuma moeda foi inserida\n");
            getchar();
            printf("Aperte qualquer tecla para sair");
            getchar();
            return 0;
        }
        else if (contcp == 0 && contcl == 0 && contch == 0)
        {
            printf("\nTodos os produtos se esgotaram\n");
            getchar();
            printf("Aperte qualquer tecla para sair");
            getchar();
            return 0;
        }
        else
        {
            printf("\nPara café puro, digite um número negativo\nPara café com leite, digite 0\nPara chocolate quente, digite um número positivo\n\n");
            scanf("%d", &x);
            getchar();
        }

        if (x < 0 && quantdinins >= cafepuro)
        {
            if (contcp > 0)
            {
                quanttroco = quantdinins - cafepuro;
                printf("\n\nSeu troco é: %d centavos, sendo:\n", quanttroco);

                while (quanttroco >= ur && nur > 0)
                {
                    quanttroco -= ur;
                    nur--;
                    ntur++;
                }

                while (quanttroco >= qc && nqc > 0)
                {
                    quanttroco -= qc;
                    nqc--;
                    ntqc++;
                }

            }
        }
    }

    return 0;
}

