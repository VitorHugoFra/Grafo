#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED

/** \brief tipo struct elemento
 *  \param chave
 */
typedef struct elemento{
    int chave;
}Elemento;

/** \brief estrutura lista
 *  \param dados -> Elemento
 *  \param ponteiro para proximo
 *         elemento da lista
 */
struct lista{
    Elemento dados;
    struct lista* prox;
};

//cria tipo lista
typedef struct lista *Lista;

struct fila{
    Lista ini;
    Lista fim;
};

//cria tipo fila
typedef struct fila *Fila;

/** \brief funcao para criar fila
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */

void cria_fila(Fila *fi);

/** \brief insere um elemento na fila
 *
 * \param ponteiro para o ponteiro fila
 * \param dados do elemento
 * \return void
 *
 */

void insere_fila(Fila fi, Elemento u);

/** \brief remove elemento na fila
 *
 * \param ponteiro para o ponteiro fila
 * \return dados do elemento removido
 *
 */
Elemento remove_fila(Fila fi);


/** \brief exibe todos os elementos na fila
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */
void imprime_fila(Fila fi);

/** \brief conta quantos elementos tem na fila
 *
 * \param ponteiro para o ponteiro fila
 * \return número de elementos na fila
 *
 */
int tamanho_fila(Fila fi);

/** \brief libera memoria
 *
 * \param ponteiro para o ponteiro fila
 * \return void
 *
 */
void fila_libera(Fila fi);
#endif // FILA_DINAMICA_H_INCLUDED
