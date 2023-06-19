/*
    Nome: Programa de Compra de Bilhetes CPTM
    Autor: @brunno_u
    Data: 1X de maio de 20XX
    Descricao: Este programa permite ao usuário comprar bilhetes de trem da CPTM, 
	selecionando o destino, informando o identificador pessoal, quantidade de bilhetes
	 e forma de pagamento. Ele também calcula o valor total a pagar com base na idade 
	 dos passageiros e emite um bilhete com informações sobre a validade e horário de embarque.
*/


#include <iostream> // Biblioteca padrão de entrada e saída
#include <iomanip>  // Biblioteca para formatação de saída
#include <locale.h> // Biblioteca para configuração do locale em português

using namespace std;

int main() {
	
	int destino, id, idmenu; // variaveis
	setlocale(LC_ALL, "Portuguese"); // linguagem definida para português
	
    cout <<  ("1- Insira seu destino \n\n 1- São Paulo\n 2- Rio de Janeiro \n 3- Santa Catarina\n\n"); //MENU
  	scanf("%d", &destino);
  
		switch ( destino ) //Sistema de caso, para informar destino
 		{
    	 case 1 :
    	 cout << " Destino selecionado: São Paulo\n\n";
    	 break;
    
     	 case 2 :
    	 cout << (" Destino selecionado: Rio de janeiro\n\n");
    	 break;
    
    	 case 3 :
    	 cout << (" Destino selecionado: Santa Catarina\n\n");
    	 break;
    
    	 default :
   	 	 cout << (" Opção invalida!\n");
  		}
 
    cout <<  (" 1- Informar Identificador Pessoal\n 2- não possuo Identificador Pessoal\n\n"); 
  	scanf("%d", &idmenu);
  
 		switch ( idmenu )
  		{
    	 case 1 :
   		 cout << " Digite seu Identificador Pessoal\n\n";
    	 cin >> id;	
    	 cout << " ID confirmado com sucesso\n\n";
    	 break;
    
    	 case 2 :
    	 cout << (" Que pena, aproveite descontos especiais acesse o site CPTM.com e cadraste-se\n\n");
    	 break;
    
    	 default :
    	 cout << (" Opção invalida!\n");
  		}

		int anos, bilhetes, pessoas, preco, pagamento, cartao, senha, preco_total; //variaveis
    	pessoas = 1, preco_total = 0;
    			
    	cout << " Quantos bilhetes você quer comprar?\n ";
   		cin >> bilhetes;
   		cout << " Número de bilhetes: \n" << bilhetes << endl;
   				while (bilhetes >= pessoas) 
				{
        			cout << " Insira a idade da pessoa\n" << pessoas << ": ";
        			cin >> anos;
        		 {
            	 	if (anos > 15)
                	preco = 80;
            		else if (anos < 8)
               		preco = 0;
            	 	else
                	preco = 30;
        		 }
        		 preco_total += preco;
        		 pessoas++;
    			}
    			cout << " Total a Pagar: " << preco_total;
    			cout << "\n\nO bilhete adquerido tem validade de 5hs apartir da emissão.\n\n";
			
				cout << " Selecione a forma de pagamento \n\n 1- Cartão de credito VISA\n 2- Cartão de credito MASTER CARD\n 3- Cancelar operação \n\n"; //MENU
  				scanf("%d", &pagamento);
  
					switch ( pagamento ) //pagamento com cartão
 					{
    					case 1 :
    						 	cout << " Pagamento com cartão VISA selecionado.\n\n";
    							cout << " Insira seu cartão e após\n";
    	 						cout << " Insira os quatro primeiros digitos de sua senha\n ";
    	 						cin >> senha;
    	 						cout << " \n\n Pagamento realizado com sucesso,\n Obrigado por utilizar nossos serviços.\n\n";
    	 						system("pause");
    	 						cout << " Aperte em qualquer tecla para continuar\n\n";
    	 						system("cls");
    	 						cout << " \n\n Imprimindo bilhete!\n\n";
    	 						cout << " \n\n Retire seu bilhete do lado direito da maquina\n\n";
    	 						cout << " \n\n A CPTM te deseja uma boa viajem!\n\n";
    	 				break;
    					
						case 2 :
    						    cout << " Pagamento com cartão MASTER CARD selecionado.\n\n";
    							cout << " Insira seu cartão e após\n";
    	 						cout << " Insira os quatro primeiros digitos de sua senha\n ";
    	 						cin >> senha;
    	 						cout << " \n\n Pagamento realizado com sucesso,\n Obrigado por utilizar nossos serviços.\n\n";
    	 						system("pause");
    	 						cout << " Aperte em qualquer tecla para continuar\n\n";
    	 						system("cls");
    	 						cout << " \n\n Imprimindo bilhete!\n\n";
    	 						cout << " \n\n Retire seu bilhete do lado direito da maquina\n\n";
    	 						cout << " \n\n A CPTM te deseja uma boa viajem!\n\n";
    					break;
    					
     	 				case 3 :
    							cout << (" Operação cancelada.\n\n");
    					return 0;
    					break;
    
    					default :
   	 							cout << (" Opção invalida!\n");
  					}	

				return 0;
}//fim do programa

