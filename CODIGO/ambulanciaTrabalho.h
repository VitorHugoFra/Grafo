/*
				INFORMATION
WORK: AMBULANCIA
GROUP: MATHEUS HENRIQUE ALVES - VITOR HUGO FRANÇA DE PAULA - PEDRO HENRIQUE SOUZA
TEACHER: LILIANE GADE
CLASS: 203
SCHOOL: COLEGIO TECNICO DE MINAS GERAIS DA UFMG -- COLTEC-UFMG

*/

#ifndef AMBULANCIATRABALHO_H
#define AMBULANCIATRABALHO_H

#include <stdio.h>
#include <stdlib.h>
#define Max 100

typedef struct Filas{
	int dado[Max];
	int inicio;
	int fim;
	int qtd;
}fila;

//CRIANDO UMA LISTA DE ADJACENCIA
typedef struct lista_adjacencia{
	int vertices;                                       //vertice de destino
	struct lista_adjacencia *proximo;
}Lista_adjacencia;

typedef struct vertices{
	Lista_adjacencia *nos_adj;                          //lista de nós ligados
}Vertice;

typedef struct grafo{
	int num_Arestas;                                   //guarda o numero de arestas no grafo
	int num_Vertices;                                  //guarda o numero de vertices no grafo
	Vertice *no;                                       //vetor de vertices
}Grafo;



//Criando o Grafo
Grafo *cria_grafo(int vert);                           //o grafo possui um numero de nos(vertices) fixo = 7; Isso pois o numero de vilas é fixo =7;

//Criando lista de adjacencia para o no(vertice)
Lista_adjacencia *cria_lista_adjacencia(int vert);     //cada nó possui uma lista de adjacencia que armazena os vertices que estao ligados a ele

//Criando aresta para dois nos(vertices)
int cria_aresta(Grafo *grafo, int vertInic, int vertFin);         //a cada vertice presente na lista de adjacecnia de um vertice a funcao cria uma aresta ligando esses vertices

//Imprimindo o Grafo
void imprime(Grafo *grafo);                            //Imprime o grafo para facil vizualizacao do mesmo

//Menu de Opcoes Principal
int menu(void);                                        //Menu de Opcoes Principal do Programa


//Mostrando o Mapa do Municipio
void mapaMunicipio();                                  //Mostrando o Municipio de uma forma mais facil de vizualizar/entender, com os igarapes e seus sentidos e uma legenda
void libera(Grafo *g);
void largura(Grafo *g,int posto,int destino);
int visitaL(Grafo *g, int s,int destino, int *expl,int *pred);
fila* criar_f();
void inserir(fila** fi,int dado);
int retirar(fila** fi);
void liberar(fila*  fi);
int  fila_tam(fila* fi);
void lista_todos(fila** fi);



#endif //Arquivo "ambulanciaTrabalho.h"
