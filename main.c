/*
				INFORMATION
WORK: AMBULANCIA
GROUP: MATHEUS HENRIQUE ALVES - VITOR HUGO FRANÇA DE PAULA - PEDRO HENRIQUE SOUZA
TEACHER: LILIANE GADE
CLASS: 203
SCHOOL: COLEGIO TECNICO DE MINAS GERAIS DA UFMG -- COLTEC-UFMG

*/

#include "ambulanciaTrabalho.h"

int main(){
	int posto;
	int destino;
	Grafo *g = cria_grafo(7);

	//insere as várias vilas do município de Águas Molhadas
	cria_aresta(g,1-1,2-1);
	cria_aresta(g,2-1,6-1);
	cria_aresta(g,6-1,2-1);
	cria_aresta(g,6-1,7-1);
	cria_aresta(g,6-1,4-1);
	cria_aresta(g,3-1,4-1);
	cria_aresta(g,4-1,5-1);
	cria_aresta(g,4-1,3-1);
	cria_aresta(g,5-1,7-1);
	cria_aresta(g,7-1,1-1);
	cria_aresta(g,7-1,4-1);

	int choice, sair;
	
	mapaMunicipio();
	
	printf("\n\n     Em qual ilha o Posto de Saude se encontra?\n");
	printf("                       : ");
	scanf("%d",&posto);
	
	choice = menu();

	while(choice!=5){
	
		switch(choice){

			case 1:
			
				system("clear");
				mapaMunicipio();
				printf("\n\n                     --------------------------------\n");
				printf("                    |   Digite um numero para sair   |\n");
				printf("                     --------------------------------\n");
				printf("                                   :");
				scanf("%d", &sair);
			
			break;

			case 2:
				
				system("clear");
				
				imprime(g);
    			
    			printf("\n\n                     --------------------------------\n");
				printf("                    |   Digite um numero para sair   |\n");
				printf("                     --------------------------------\n");
				printf("                                   :");
				
				scanf("%d", &sair);

			break;

			case 3:
	
				system("clear");
				
				printf("\n\n                          ----------------------\n");
				printf("                         |   Digite o DESTINO   |\n");
				printf("                          ----------------------\n");
				printf("                                    :");
				
				scanf("%d", &destino);

				system("clear");

				printf("        ---------------------------------------------------------\n");
				printf("       |  Posto de Saude -->  Vila %d         Destino --> Vila %d  |\n", posto, destino);
				printf("        ---------------------------------------------------------\n");

				printf("\n\n                                   IDA\n");
				largura(g,posto-1,destino-1);
				printf("\n                                  VOLTA\n");
				largura(g,destino-1,posto-1);

				printf("\n\n                     --------------------------------\n");
				printf("                    |   Digite um numero para sair   |\n");
				printf("                     --------------------------------\n");
				printf("                                   :");
				
				scanf("%d", &sair);
			
			break;

			case 4:

				system("clear");
				libera(g);
				exit(1);
			
			break;

			default:
            
                printf("Escolha invalida. \n\n");// choice != 4
            
            break;


		}

		choice = menu();
	
	}

}//Arquivo "main.c"
