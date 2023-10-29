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
        return 1;
    else
        return 0;
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


// int vendedor_adiciona_produtos(vendedor v)
