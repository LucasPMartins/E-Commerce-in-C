#include "lista_vendedores.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    Vendedor vendedor;
    struct no* prox;
}No;

typedef struct lista { 
    No* inicio;
}ListaVendedores;

ListaVendedores* criarLista() {
     ListaVendedores* l = (ListaVendedores*) malloc(sizeof(ListaVendedores));
    if (l == NULL) {
        exit(1);
    }
    l->inicio = NULL;
    return l;
}

int adicionarVendedor(ListaVendedores* l, Vendedor it) {
    if(l == NULL)
        return 3;
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL)
        return 2; 
    novo->vendedor = it;
    novo->prox = l->inicio;
    l->inicio = novo;
    return 0;
}
//Implementacao 12/10 brenin
void listarVendedores(ListaVendedores* l) {
    No* atual = l->inicio;
    printf(" \nLista de Vendedores:\n");
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->vendedor.codigo);
        printf("Nome: %s\n", atual->vendedor.nome);
        printf("Salario: %.2f\n", atual->vendedor.salario);
        printf("\n");
        atual = atual->prox;
    }
}

int listaVazia(ListaVendedores* l){
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

void limpar(ListaVendedores *l)
{
    while (listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}

int removerInicio(ListaVendedores *l)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    
    return 0;
}
