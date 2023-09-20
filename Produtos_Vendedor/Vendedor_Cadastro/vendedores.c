#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

struct No {
    struct Vendedor vendedor;
    struct No* prox;
};

struct ListaVendedores {
    struct No* inicio;
};



struct ListaVendedores* criarLista() {
    struct ListaVendedores* l = (struct ListaVendedores*)malloc(sizeof(struct ListaVendedores));
    if (l == NULL) {
        exit(1);
    }
    l->inicio = NULL;
    return l;
}



void f(struct ListaVendedores* l) {
    struct No* atual = l->inicio;
    while (atual != NULL) {
        struct No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(l);
}




int adicionarVendedor(struct ListaVendedores* l, struct Vendedor vendedor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL) {
        return 0; 
    }
    novo->vendedor = vendedor;
    novo->prox = l->inicio;
    l->inicio = novo;
    return 1;
}



void listarVendedores(struct ListaVendedores* l) {
    struct No* atual = l->inicio;
    printf(" \nLista de Vendedores:\n");
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->vendedor.codigo);
        printf("Nome: %s\n", atual->vendedor.nome);
        printf("Salario: %.2f\n", atual->vendedor.salario);
        printf("\n");
        atual = atual->prox;
    }
}
