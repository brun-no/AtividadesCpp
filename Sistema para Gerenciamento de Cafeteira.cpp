/*
Nome do arquivo: Sistema para Gerenciamento de Cafeteira
Autor: itsourcecode.com
Data de criação: 1X de maio de 20XX
Descrição: Um programa para gerenciar pedidos em uma cafeteria.
Originalmente oferecido por Code-projects.org.
Última modificação por: @brunno_u
Data da última modificação: 1X de maio de 20XX
Descrição da modificação: Adicionada a tradução para o idioma português do Brasil.
*/

#include <string.h> // Biblioteca para manipulação de strings
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <conio.h> // Biblioteca para manipulação de entrada no console
#include <stdlib.h> // Biblioteca padrão do sistema
#include <locale.h> // Biblioteca para configuração do locale em português
#include <windows.h> // Biblioteca para manipulação de funções do sistema Windows
#include <time.h> // Biblioteca para manipulação de data e hora.


///Funções lógicas

   /// Função de atualização e inserção
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

/// Função de visualização
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

    ///Função de apagar e contar
void deletefood(int serial);
int countitem();




///função extra de design 

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);


        ///Start da Estrutura

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

   ///Tipo global

typedef struct Node node ;

node *head, *list;

int main() {
    setlocale(LC_ALL, "portuguese");

	system("título Sistema de gestão de cafetarias");
	system("mode con: cols=88 lines=30");


	loadingbar();  //barra de carregamento
	cls();
	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1,"Pingado ",23,120.23);
	insertend(2,"Mochachino",13,100.67);
	insertend(3,"Cappuccino",8,720.83);
	insertend(4,"Espresso  ",46,70.23);
	insertend(5,"Cremoso   ",46,70.23);
	insertend(6,"Nescafe   ",34,60.23);
	insertend(7,"Leite     ",7,520.29);
	insertend(8,"Chá       ",121,35.13);
	insertend(9,"Agua      ",73,20.13);



	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Menu principal ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  printf("1. Menu principal\n\n\t"); Sleep(300);
			printf("Por favor, introduza a senha ou ( 1 para voltar ao menu principal ) : ");


			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==123){



				node *temp;

				temp = list;

				adminchoise:

				cls();  br(3); pre(4); echo(">>>> Painel de administração <<<<   \n\n");
				pre(4);
				printf(" 1. Total de dinheiro hoje \n\n");Sleep(250);pre(4);
				printf(" 2. Ver Pagamento com Cartão \n\n");Sleep(250);pre(4);
				printf(" 3. Adicionar novo Item \n\n");Sleep(250);pre(4);
				printf(" 4. Apagar Item \n\n");Sleep(250);pre(4);
				printf(" 5. Lista de Itens \n\n");Sleep(250);pre(4);
				printf(" 6. Contador de Itens \n\n");Sleep(250);pre(4);
				printf(" 7. Sistema de Backup\n\n");Sleep(250);pre(4);
				printf(" 8. Pré-visualização da encomenda\n\n");Sleep(250);pre(4);
				printf(" 0. Menu principal \n\n");
				printf("Introduza o seu nome de utilizador 1-0: ");
				Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d",&adminchoise);

				if(adminchoise==1){

					cls();  middle1(); pre(4);   printf("Total de dinheiro de hoje: %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){

						cls();  br(3); pre(4);

						printf(" ____________________________\n");pre(4);
						printf("|   Cartão n.º | Dinheiro   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);pre(4);
							printf("------------------------------\n");pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					printf("No Card History\n");}
					Sleep(1500);
					goto adminchoise;
				}

				else if(adminchoise==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      printf("  Introduzir nome do item :  ");

					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					printf(" Introduzir a quantidade do item :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
					br(2);pre(4);  printf(" Introduzir a série do item :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf("  Item Serial Já Existe, Por Favor Re-Introduzir  "); Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  printf(" Introduzir o preço do Item :  ");fflush(stdin);

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Enviar os seus dados");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Adicionando item com sucesso......\n");

					Sleep(2000);

					goto adminchoise;

				}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					printf("Introduza o número de série do item para apagar: ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Por favor introduza o número correto: "); Sleep(500);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- Voltar  \n\n");pre(5);



					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						printf("Contagem de itens ");
						printf(" %d ",cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					printf("Total de Itens é --> %d  \n",citem); Sleep(2000);
					goto adminchoise;

				}

                        ///Backup do sistema
				else if(adminchoise==7){


					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr,"Total de dinheiro hoje: %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Cartão n.º -------- Dinheiro \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Feito com Successo..."); Sleep(1500);



					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){

					cls();br(2);pre(2);
					ccolor(26);
					printf("\n\t\t"); ccolor(240);
					printf("______________________________________________________ "); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("|  Nº de encomenda  |   Nome do item    |  Quantidade |  No Estoque|"); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("------------------------------------------------------"); ccolor(26);
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  printf("1. <-- Voltar  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;



				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Por favor, seleccione da lista :  "); Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Por favor, introduza a escolha correcta");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Obrigado por utilizar o nosso sistema. \n\t\t\tSe curtiu já segue @brunno_u \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);

		}

	}
	else{
		br(2); pre(4); printf("Introduza a opção correcta"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	printf("Faça o seu pedido: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Por favor escolha da lista: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		printf("Introduza a quantidade do item : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("A quantidade não pode ser zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Sem Estoque ! "); Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4);  printf("Item escolhido %s  o seu preço é %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirme a compra deste item \n\n");pre(4);
		printf("2. Lista de itens \n\n");
		printf("Pressione 1 para confirmar e 2 para voltar à lista :");

		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);
			printf(" 1. Dinheiro ");
			br(2);pre(4);
            printf(" 2. Crédito\n");
            printf("Seleccione o método de pagamento 1-2: ");
			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  printf("===>OBRIGADO<===");
				br(2);pre(4);  printf("Item encomendado com sucesso ...");
				br(2);pre(4);  printf("1. Continuar comprando? ");
				br(2);pre(4);  printf("2. Menu principal\n");
				br(2);pre(4);   printf("Selecionar: ");
				psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Por favor escolha da lista : "); goto psmenu;}

			}

			//Opção de cartão de crédito

			else if(payment==2){

				int card_number[100];

				c++;

				cls();middle1();pre(4); printf("Introduza o número do seu cartão : ");

				fflush(stdin);   scanf("%d",&card_number[c]);



				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  printf("Introduza o PIN do seu cartão [nunca guardamos o seu PIN]  : ");

				fflush(stdin);     scanf("%d",&pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  printf("Pagamento efetuado com sucesso...");
				br(2);pre(4);    printf("1. Continuar comprando? ");
				br(2);pre(4);    printf("2. Menu principal \n");
				br(2);pre(4);   printf("Selecionar: ");
				psmenu2:
				int ps_menu2;

				scanf("%d",&ps_menu2);

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);printf("Por favor escolha da lista : "); goto psmenu2;}

			}

			else{

				br(2);pre(4);   printf("Introduza a escolha da lista : ");

				goto payment;


			}


		}    ///Fim Confirmar Y/y



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			br(2);pre(4);    printf("Introduza a escolha da lista: ");

			goto confirm;


		}  ///Fim Confirmar 


	}  ///Fim obter escolha 


	else{

		br(2);pre(4);  echo("Escolha uma opção da lista  "); br(2); Sleep(300);

		goto foodlist;

	}  ///fim obter escolha da comida
}

void cls(){

	system("cls");

}

void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}

void main_menu(){

	cls();
	br(5); pre(3); echo(">> 1. Lista de cafés"); Sleep(400);
	br(2); pre(3); echo(">> 2. Painel de administração"); Sleep(400);
	br(2); pre(3); echo(">> 3. Sair");  Sleep(400);
	//   br(2); pre(3); echo("=> 4. Painel de administração");  Sleep(400);

	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	// livre (temporário)
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tApagando Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tApagado com Successo \n"); Sleep(500);

		}
		else{
			printf("\n\n\n\n\t\t\tItem não encontrado\n"); Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tApagando Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tApagado com Successo \n"); Sleep(500);

		head = temp ;

		list=head;
	}
}

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

}
void foodlist(){

	ccolor(0);

	printf("\n\t\t"); ccolor(240);
	printf("______________________________________________________ ");ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("|  Nº de encomenda  |   Nome do item    |  Quantidade |  No Estoque|"); ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("-------------------------------------------------------");ccolor(26);

	node *temp;

	temp = list;

	while(temp != NULL){

		ccolor(26);


		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("-------------------------------------------------------");


		temp = temp->next ;

		Sleep(100);

	}

	ccolor(26);

	// livre (temporário)

}


void order_view(int order, int quantity, int or_no){



	ccolor(26);

	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){

		ccolor(26);

		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("-------------------------------------------------------");

		Sleep(100);

	}

	ccolor(26);

}

void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

// o código acima apresenta um fundo colorido.
// Se quiser um fundo colorido, pode remover o comentário acima, mas não o código, apenas o comentário ( // )
}


/// AQUI FUNÇÃO ESTILO PRINTF

void pwellcome(){
	ccolor(26);

	char welcome[50]="BEM-VINDO";
	char welcome2[50]=" AO SISTEMA DE";
	char welcome3[50]=" GERENCIAMENTO DE";
	char welcome4[50]=" CAFETERIA";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
	ccolor(26);

}
void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Carregando sistema...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}
void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Fazer cópia de segurança dos dados...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(120+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}


void middle1(void){

	printf("\n\n\n\n\n\n\n");
}

void middtab1(void){
	printf("\t\t\t\t\t");
}
