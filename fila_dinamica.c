#include <stdlib.h>
#include <stdio.h>
#include "fila_dinamica.h"


/** \brief funcao para criar fila
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */

void cria_fila(Fila *fi){
    Fila f = (Fila) malloc(sizeof(Fila));

    f->fim = f->ini = NULL;

    *fi = f;
}


/** \brief insere um elemento na fila
 *
 * \param ponteiro para o ponteiro fila
 * \param dados do elemento
 * \return void
 *
 */

void insere_fila(Fila fi, Elemento u){

    //cria novo elemento da fila
    Lista novo_el = (Lista)malloc(sizeof(struct lista));

    if(novo_el == NULL){
    	//caso nao tenha conseguido
    	//alocar espaco na memoria
    	//sai do programa
        exit(1);
    }

    //insere os dados do aluno
    novo_el->dados = u;
    novo_el->prox = NULL;


    //verifica se a fila nao esta vazia
    if(fi->fim != NULL){
        fi->fim->prox = novo_el;
    }else{
        fi->ini = novo_el;
    }

    fi->fim = novo_el;

}

/** \brief remove um elemento da fila
 *
 * \param ponteiro para o ponteiro fila
 * \return dados do elemento removido
 *
 */
Elemento remove_fila(Fila fi){
    Lista aux1;
    Elemento al;

    aux1 = fi->ini;
    al = aux1->dados;

    al = aux1->dados;

    //remove o primeiro aluno
    //da fila
    fi->ini = aux1->prox;

    //verifica se a fila ficou vazia
    if(fi->ini == NULL){
        fi->fim = NULL;
    }

    //libera a memoria
    free(aux1);

    return al;

}


/** \brief exibe todos os alunos na fila
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */
void imprime_fila(Fila fi){
    Lista aux = fi->ini;

    while(aux != NULL){
        printf("chave %d",aux->dados.chave);
        aux = aux->prox;
    }
}

/** \brief conta quantos elementos tem na fila
 *
 * \param ponteiro para o ponteiro fila
 * \return número de elementos na fila
 *
 */
int tamanho_fila(Fila fi){
    Lista aux = fi->ini;
    int num = 0;

    while(aux != NULL){
        num++;
        aux = aux->prox;
    }
    return num;
}

/** \brief libera memoria
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */
void fila_libera(Fila fi){
    Lista aux = fi->ini;

    while(aux != NULL){
        Lista t = aux->prox;
        free(aux);
        aux = t;
    }

    free(fi);
}
