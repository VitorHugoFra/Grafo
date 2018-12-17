/*
                INFORMATION
WORK: AMBULANCIA
GROUP: MATHEUS HENRIQUE ALVES - VITOR HUGO FRANÇA DE PAULA - PEDRO HENRIQUE SOUZA
TEACHER: LILIANE GADE
CLASS: 203
SCHOOL: COLEGIO TECNICO DE MINAS GERAIS DA UFMG -- COLTEC-UFMG

*/

#include "ambulanciaTrabalho.h"

Grafo *cria_grafo(int vert){
	 
	Grafo *grafo = (Grafo*)malloc(sizeof(Grafo)); //alocando memoria para o grafo

	grafo->num_Vertices = vert;
	grafo->num_Arestas = 0;

	grafo->no = (Vertice*)malloc(vert * sizeof(Vertice)); //alocando memoria para os vertices

	int i;
    
	for(i = 0; i < vert; i++){
		grafo->no[i].nos_adj = NULL; //o grafo ainda nao possui arestas, entao é iniciado com NULL
	}

	return grafo;
}

Lista_adjacencia *cria_lista_adj(int vert){
	
	Lista_adjacencia *lista = (Lista_adjacencia*)malloc(sizeof(Lista_adjacencia));//alocando espaço para um no na lista de adjacencia
	lista->proximo = NULL;
    lista->vertices = vert;

	return lista;
}

int cria_aresta(Grafo *grafo, int vertInic, int vertFin){
	
	if(vertFin < 0 || (vertFin >= grafo->num_Vertices)){
		return -1; //se o valor do vertice for menor que 0 ou maior que a quantidade de vertices
	}

    if(!grafo){
        return -1;//se nao existir grafo
    }


	//caso o vertice seja menor que 0 ou maior que
	//o numero de vertices
	if(vertInic < 0 || (vertInic >= grafo->num_Vertices)){
		return -1;
	}

    Lista_adjacencia *adj = grafo->no[vertInic].nos_adj;

    while(adj){
        if(adj->vertices == vertFin){
            return -1;           //se ja existir uma aresta com esses vertices nao irá criar outra aresta
        }
        adj = adj->proximo;
    }

  
    Lista_adjacencia *nova = cria_lista_adj(vertFin);
 
    nova->proximo = grafo->no[vertInic].nos_adj;
 
    grafo->no[vertInic].nos_adj = nova;
	grafo->num_Arestas++;

	return 1;
}

void imprime(Grafo *grafo){

	int i;

    printf("\n                            CAMINHO DAS 7 VILAS\n\n");

	for(i = 0; i <  grafo->num_Vertices; i++){
		
        printf("                      VILA %i:", i+1);
		Lista_adjacencia *adj = grafo->no[i].nos_adj;

		while(adj){
            
    			printf(" --> VILA %d",adj->vertices+1);
    			adj = adj->proximo;

		}
		printf("\n");
	}
}

int menu(void){
    
    system("clear");

    int opcao;
    printf("\n                             MENU DE OPCOES\n\n");
    printf("                          1 - Mapa do Municipio\n");
    printf("                          2 - Caminhos das Vilas\n");
    printf("                          3 - Ir a uma Vila\n");
    printf("                          4 - Sair\n");
    printf("                                 : ");
    scanf("%d",&opcao);

    return opcao;

}

void mapaMunicipio(){
    system("clear");

    printf("\n\n                   MAPA DO MUNICIPIO DE AGUAS MOLHADAS \n");


    system("sleep 0.06");
    printf("                                        ---           ---                                             \n");
    system("sleep 0.06");
    printf("                                       |   | ------> |   |                                            \n");
    system("sleep 0.06");
    printf("     ---                               | 6 | <------ | 2 |                                            \n");
    system("sleep 0.06");
    printf("    |   | -----                     -- |   | --      |   | <--                                        \n");
    system("sleep 0.06");
    printf("    | 3 |      -                   -    ---    -      ---     -                                       \n");
    system("sleep 0.06");
    printf("    |   | <--   -                -              -              -                                      \n");
    system("sleep 0.06");
    printf("     ---     -   -     ---      -                -     ---      -        ---                             \n");
    system("sleep 0.06");
    printf("              -   --> |   |  <--                  --> |   |      ------ |   |                            \n");
    system("sleep 0.06");
    printf("               ------ | 4 |  <----------------------- | 7 |             | 1 |                            \n");
    system("sleep 0.06");
    printf("                   -- |   |                       --> |   | ----------> |   |                            \n");
    system("sleep 0.06");
    printf("                  -    ---                       -     ---               ---                             \n");
    system("sleep 0.06");
    printf("                 -                              -                                                        \n");
    system("sleep 0.06");
    printf("        ---     -                              -                                                         \n");
    system("sleep 0.06");
    printf("       |   | <--                              -                                                          \n");
    system("sleep 0.06");
    printf("       | 5 |                                 -                                                           \n");
    system("sleep 0.06");
    printf("       |   | --------------------------------                                                            \n");
    system("sleep 0.06");
    printf("        ---                                                                                      \n\n");
    system("sleep 0.06");

    printf("  ---------                                             \n");
    printf(" | LEGENDA |  \n");
    printf("  ---------   \n");
    printf(" 1 - Setas '--->' mostram os sentidos dos igarapes!\n");

}//Arquivo "ambulanciaTrabalho.c"
fila* criar_f(){
    fila *fi = (fila*) malloc(sizeof(fila));
    
    if(fi != NULL){
        fi -> fim = 0;
        fi -> inicio = 0;
        fi -> qtd = 0;
    }

    return fi;
}
void inserirF(fila* fi,int dado){
    if((*fi).qtd != Max){
        (fi)->dado[(fi)->fim] = dado;
        (*fi).fim = ((*fi).fim +1) % Max;
        (*fi).qtd++;
    }
}
int retirarF(fila* fi){
    int ret;

    if ((*fi).qtd != 0){
        ret = (fi)->dado[(fi)->inicio];
        (*fi).inicio = ((*fi).inicio +1) % Max;
        (fi)->qtd--;
    }
    return ret;
}
void liberar(fila*  fi){
    if (fi != NULL){
        free(fi);
    }
}
int  fila_tam(fila* fi){
    return fi->qtd;
}
void lista_todosF(fila* fi){

    for(int i = (*fi).inicio;i != (*fi).fim;(i++) %Max){
        printf("(%d)",(*fi).dado[i]+1);
    }
    printf("\n");
}

void libera(Grafo *g){

    for(int i = 0; i < g->num_Vertices; i++){
        Lista_adjacencia *adj = g->no[i].nos_adj;
        Lista_adjacencia *aux = adj;
        while(adj){
            aux = adj->proximo;
            free(adj);
            adj = aux;
        }

    }

    free(g->no);
    free(g);

}

void largura(Grafo *g,int posto,int destino){
    int *expt = (int*)calloc(g->num_Vertices,sizeof(int));
    int *pred = (int*)calloc(g->num_Vertices,sizeof(int));
    int *Resposta = (int*)calloc(g->num_Vertices,sizeof(int));
    int res,tam = 0;

    for(int i = 0; i < g->num_Vertices; i++){
        pred[i] = -1;
    }

    res = visitaL(g,posto,destino,expt,pred);
    
    //printf("(%d)",destino+1);
    for (int i = destino; ;){
        Resposta[tam] = pred[i]+1;
    //printf("(%d)",pred[i]+1);  
        tam++;
        i =  pred[i]; 
        if(i == posto){
            break;
        }
    }
    Resposta[tam] = destino+1;
    printf("        ");
    for (int j = tam -1; j >= 0; j--){
        printf("Vila [%d] --> ",Resposta[j] );
    }
    printf("Vila [%d]\n",Resposta[tam] );    
    free(expt);
    free(pred);
    free(Resposta);
}

int visitaL(Grafo *g, int s,int destino, int *expl,int *pred){
    fila *f;
    f = criar_f();

    expl[s] = 1;
    int i =0;
    int u = s;
    //insere o no de partida na fila
    inserirF(f,u);

    //enquanto tiver elemento na fila
    while(fila_tam(f)){

        //remove o primeiro elemento da fila
        //realiza a vista em seus nós adjacentes
        //apenas se nao tiverem sido visitados
        u = retirarF(f);
        Lista_adjacencia *v = g->no[u].nos_adj;
        while(v){

            if(expl[v->vertices] == 0){
                expl[v->vertices] = 1;
                pred[v->vertices] = u;
                if (v->vertices == destino){
                    liberar(f);
                    return 1;
                }

                inserirF(f,v->vertices);
            }

            v = v->proximo;
        }
    }
    liberar(f);
    return -1;
}


