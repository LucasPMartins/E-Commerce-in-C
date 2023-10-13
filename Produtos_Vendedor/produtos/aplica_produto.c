#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_produto.h"

/* --  A lista de produtos será implementada usando Lista duplamente encadeada
       pela facilidade de se adicionar e remover produtos, e pela maior facilidade
       de manutenção do código e implementação de novas funçoes.
   --
*/
// TESTEEE BRENO
typedef struct no{
    struct no* ant;
    Produto valor;
    struct no* prox;
}No;

typedef struct lista{
    No* inicio;
}Lista;

Lista* criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar(Lista *l){
    while(listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho(Lista *l)
{
    if (l == NULL)
        return -1;
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

void mostrar(Lista *l)
{
    if (l != NULL)
    {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL)
        {
            printf(" {%d, ", noLista->valor.);
            printf("%s, ", noLista->valor.);
            printf("%.2f} ", noLista->valor.);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int listaVazia(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

int listaCheia(Lista *l)
{
    return 1;
}

int inserirInicio(Lista *l, Produto it)
{
    if (l == NULL)
        return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)
        l->inicio->ant = no;
    l->inicio = no;
    return 0;
}

int removerInicio(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    free(noLista);

    return 0;
}

