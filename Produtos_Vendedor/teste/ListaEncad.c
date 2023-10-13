#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncad.h"

lista_vendedores *criar_lista_vendedores()
{
    lista_vendedores *l = (lista_vendedores *)malloc(sizeof(lista_vendedores));
    l->inicio = NULL;
    l->total_vendedores = 0;
    return l;
}

int lista_vendedores_vazia(lista_vendedores *l)
{
    if (l == NULL)
        return 1;
    if (l->inicio == NULL && l->total_vendedores == 0)
        return 1;
    else
        return 0;
}

int verifica_vendedor(lista_vendedores *l, cadastro it, vendedor v)
{
    if (l == NULL)
        return 1;
    if (lista_vendedores_vazia(l) == 0)
        return insere_novo_vendedor(l, v);
    no_vendedores *atual = l->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->valor.lol.nome, it.nome) == 0)
        {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int insere_novo_vendedor(lista_vendedores *l, vendedor v)
{
    if (l == NULL)
    {
        return 1;
    }

    no_vendedores *novo_no = (no_vendedores *)malloc(sizeof(no_vendedores));
    if (novo_no == NULL)
    {
        return 2;
    }

    novo_no->valor = v;
    novo_no->prox = l->inicio;
    novo_no->ant = NULL;

    if (l->inicio != NULL)
    {

        l->inicio->ant = novo_no;
    }

    l->inicio = novo_no;

    l->total_vendedores++;
    return 0;
}

void libera_lista_vendedores(lista_vendedores *l)
{
    no_vendedores *atual = l->inicio;
    while (atual != NULL)
    {
        no_vendedores *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
    l->total_vendedores = 0;
}

void mostrar_lista_vendedores(lista_vendedores *l)
{
    if (l != NULL)
    {
        no_vendedores *search = l->inicio;
        int cont = 1;
        printf("{");
        while (search != NULL)
        {
            printf("Vendedor %d:\n", cont);
            printf("Nome: %s\n", search->valor.lol.nome);
            printf("NomeLoja: %s\n", search->valor.nomeloja);
            printf("Senha: %s\n", search->valor.lol.senha);
            printf("\n");

            search = search->prox;
            cont++;
        }
        printf("}");
    }
    /*if (l == NULL)
    {
        printf("Lista de vendedores nao criada!\n");
        return;
    }*/
}
