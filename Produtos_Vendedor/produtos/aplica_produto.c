#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_produto.h"

/* --  A lista de produtos será implementada usando Lista duplamente encadeada
       pela facilidade de se adicionar e remover produtos, e pela maior facilidade
       de manutenção do código e implementação de novas funçoes.
   --
*/

Lista *criar_lista_produtos()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar_lista_produtos(Lista *l)
{
    while (listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho_lista_produtos(Lista *l)
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

void mostrar_produto_aleatorio(Lista *l)
{
    if (l != NULL)
    {
        printf("[");
        no_produtos *no_Lista = l->inicio;
        int j=0;
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

int listaVazia_produtos(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

int inserirInicio_produtos(Lista *l, produtos it)
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

int removerInicio_produtos(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    no_produtos *no_Lista = l->inicio;
    l->inicio = no_Lista->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    free(no_Lista);

    return 0;
}
