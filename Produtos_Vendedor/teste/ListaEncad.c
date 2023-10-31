#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "ListaEncad.h"

/*                                  PRODUTOS   */
/*                                  PRODUTOS   */
/*                                  PRODUTOS   */

lista_produtos *criar_lista_produtos()
{
    lista_produtos *l = (lista_produtos *)malloc(sizeof(lista_produtos));
    l->inicio = NULL;
    return l;
}

void limpar_lista_produtos(lista_produtos *l)
{
    while (listaVazia_produtos(l) != 0)
        removerInicio_produtos(l);
    free(l);
    l = NULL;
}

int tamanho_lista_produtos(lista_produtos *l)
{
    if (l == NULL)
        return -1;
    no_produtos *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

void mostrar_produtos(lista_produtos *l)
{
    if (l == NULL)
    {
        printf("Lista de Produtos nao Criada!\n");
        return;
    }
    if (listaVazia_produtos(l) == 0)
    {
        printf("Nenhum Produto foi Encontrado! :( \n");
        return;
    }
    if (l != NULL)
    {
        printf("[");
        no_produtos *no_Lista = l->inicio;
        int j = 0;
        while (no_Lista != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", no_Lista->produto.NOME);
            printf("        Categoria: %d\t", no_Lista->produto.CATEGORIA);
            printf("        Nota de Avalicao: %d\t", no_Lista->produto.NOTA_AVALIACAO);
            printf("        Quantidade: %d\t", no_Lista->produto.QUANTIDADE);
            printf("        Valor: %.2f\t", no_Lista->produto.VALOR);
            printf("        Descricao: %s}\n", no_Lista->produto.DESCRICAO);
            j++;
            no_Lista = no_Lista->prox;
        }
        printf("]\n");
    }
}

int listaVazia_produtos(lista_produtos *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

int inserirInicio_produtos(lista_produtos *l, produtos it)
{
    if (l == NULL)
        return 2;
    no_produtos *no = (no_produtos *)malloc(sizeof(no_produtos));
    no->produto = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)
        l->inicio->ant = no;
    l->inicio = no;
    return 0;
}

int removerInicio_produtos(lista_produtos *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia_produtos(l) == 0)
        return 1;
    no_produtos *no_Lista = l->inicio;
    l->inicio = no_Lista->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    free(no_Lista);

    return 0;
}

/*                                  VENDEDOR   */
/*                                  VENDEDOR   */
/*                                  VENDEDOR   */

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
        return 0;
    else
        return 1;
}

int verifica_vendedor(lista_vendedores *l, vendedor v)
{
    if (l == NULL)
        return 1;
    if (lista_vendedores_vazia(l) == 0)
        return 2;
    no_vendedores *atual = l->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->valor.cadastro.nome, v.cadastro.nome) == 0)
        {
            return 0;
        }
        atual = atual->prox;
    }
    return 3;
}

int verifica_vendedor_e_retorna(lista_vendedores *l, vendedor *v)
{
    if (l == NULL)
        return 1;
    if (lista_vendedores_vazia(l) == 0)
        return 2;
    no_vendedores *atual = l->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->valor.cadastro.nome, v->cadastro.nome) == 0)
        {
            *v = atual->valor;
            return 0;
        }
        atual = atual->prox;
    }
    return 3;
}

int insere_novo_vendedor(lista_vendedores *l, vendedor v)
{
    if (l == NULL)
        return 1;
    // a função insere no inicio
    no_vendedores *novo_no = (no_vendedores *)malloc(sizeof(no_vendedores));
    if (novo_no == NULL)
        return 2;
    novo_no->valor = v;
    novo_no->prox = l->inicio;
    novo_no->ant = NULL;

    if (l->inicio != NULL)
        l->inicio->ant = novo_no;

    l->inicio = novo_no;

    l->total_vendedores++;
    return 0;
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
            printf("Nome: %s\n", search->valor.cadastro.nome);
            printf("NomeLoja: %s\n", search->valor.nome_loja);
            printf("Senha: %s\n", search->valor.cadastro.senha);
            printf("Total produtos: [%d]\n", search->valor.total_produtos);
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

int vendedor_adiciona_produtos(vendedor *v, produtos p)
{
    if (v->total_produtos == 0)
    {
        // Nao tem produtos ainda
        v->inicio = (no_produtos *)malloc(sizeof(no_produtos));
        v->inicio->ant = NULL;
        v->inicio->produto = p;
        v->inicio->prox = NULL;
        v->total_produtos++;
        return 0;
    }
    no_produtos *temp = (no_produtos *)malloc(sizeof(no_produtos));
    temp->ant = NULL;
    temp->produto = p;
    temp->prox = v->inicio;
    v->inicio->ant = temp;
    v->inicio = temp;
    v->total_produtos++;

    return 0;
}

void mostra_produtos_vendedor(vendedor v)
{
    if (v.inicio == NULL)
    {
        printf("O vendedor nao possui produtos.\n");
    }
    else
    {
        printf("Produtos do vendedor:\n");
        no_produtos *temp = v.inicio;
        int j = 0;
        while (temp != NULL)
        {
            printf("  Produto [%d]:\n", j);
            printf("  Nome: %s\n", temp->produto.NOME);
            printf("  Categoria: %d\n", temp->produto.CATEGORIA);
            printf("  Nota de Avaliacao: %d\n", temp->produto.NOTA_AVALIACAO);
            printf("  Quantidade: %d\n", temp->produto.QUANTIDADE);
            printf("  Valor: %.2f\n", temp->produto.VALOR);
            printf("  Descricao: %s\n", temp->produto.DESCRICAO);
            j++;
            temp = temp->prox;
        }
    }
}

int removerPosicao_produto_do_vendedor(vendedor *v, int pos)
{
    if (v == NULL)
        return 1;
    no_produtos *no = v->inicio;
    while ((no->prox != NULL) && (pos > 0))
    {
        no = no->prox;
        pos--;
    }
    if (no->ant == NULL)
    {
        // Ele é o primeiro
        v->inicio = v->inicio->prox;
        if (v->inicio != NULL)
            v->inicio->ant = NULL;
        free(no);
        v->total_produtos--;
        return 0;
    }

    if (no->prox == NULL)
    {
        if (no->ant == NULL)
            v->inicio = NULL;
        else
            no->ant->prox = NULL;
        free(no);
        v->total_produtos--;
        return 0;
    }

    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    v->total_produtos--;
    return 0;
}

int atualiza_lista_vendedores(vendedor v,lista_vendedores *l){
    if (l == NULL)
        return 1;
    if (lista_vendedores_vazia(l) == 0)
        return 2;
    no_vendedores *atual = l->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->valor.cadastro.nome, v.cadastro.nome) == 0)
        {
            atual->valor = v;
            return 0;
        }
        atual = atual->prox;
    }
    return 3;
}