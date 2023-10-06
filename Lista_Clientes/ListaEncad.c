#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncad.h"

lista_clientes *criar_lista_clientes()
{
    lista_clientes *l = (lista_clientes *)malloc(sizeof(lista_clientes));
    l->inicio = NULL;
    l->total_clientes = 0;
    return l;
}

int lista_clientes_vazia(lista_clientes *l)
{
    if (l == NULL)
        return 1;
    if (l->inicio == NULL && l->total_clientes == 0)
        return 0;
    else
        return 2;
}

int lista_carrinho_vazia(cliente *l)
{
    if (l == NULL)
        return 1;
    if (l->carrinho_inicio == 0 && l->total_carrinho == 0)
        return 0;
    else
        return 2;
}

int lista_comprados_vazia(cliente *l)
{
    if (l == NULL)
        return 1;
    if (l->comprados_inicio == NULL && l->total_comprados == 0)
        return 0;
    else
        return 2;
}

int verifica_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return insere_novo_cliente(l, it);
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            // cliente ja exite na lista
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return insere_novo_cliente(l, it);
}

int insere_novo_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    no_clientes *user = (no_clientes *)malloc(sizeof(no_clientes));
    user->valor.cadastro = it;
    user->valor.carrinho_inicio = NULL;
    user->valor.comprados_inicio = NULL;
    user->valor.total_carrinho = 0;
    user->valor.total_comprados = 0;
    user->prox = l->inicio;
    user->ant = NULL;
    if (l->inicio != NULL)
        l->inicio->ant = user;
    l->inicio = user;
    l->total_clientes++;
    return 0;
}

int insere_nova_compra(lista_clientes *l, cadastro it, produtos p)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            no_comprados *no = (no_comprados *)malloc(sizeof(no_comprados));
            no->produto = p;
            no->prox = search->valor.comprados_inicio;
            no->ant = NULL;
            if (search->valor.comprados_inicio != NULL)
                search->valor.comprados_inicio->ant = no;
            search->valor.comprados_inicio = no;
            search->valor.total_comprados++;
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 3;
}

int insere_novo_carrinho(lista_clientes *l, cadastro it, produtos p)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            no_carrinho *no = (no_carrinho *)malloc(sizeof(no_carrinho));
            no->produto = p;
            no->prox = search->valor.carrinho_inicio;
            no->ant = NULL;
            if (search->valor.carrinho_inicio != NULL)
                search->valor.carrinho_inicio->ant = no;
            search->valor.carrinho_inicio = no;
            search->valor.total_carrinho++;
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 3;
}

int remove_do_carrinho(lista_clientes *l, cadastro it, int pos)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            if (lista_carrinho_vazia(&search->valor) == 0)
                return 3; // carrinho vazio
            if (pos > search->valor.total_carrinho || pos < 0)
                return 4;
            no_carrinho *no = search->valor.carrinho_inicio;
            while (no->prox != NULL && pos > 0)
            {
                pos--;
                no = no->prox;
            }
            
            if (no->ant == NULL)
            {   
                search->valor.carrinho_inicio = no->prox;
                search->valor.total_carrinho--;
                if(search->valor.carrinho_inicio != NULL) search->valor.carrinho_inicio->ant = NULL;
                free(no);
                return 0;
            }
            if (no->prox == NULL)
            {
                no->ant->prox = NULL;
                search->valor.total_carrinho--;
                free(no);
                return 0;
            }
            no->ant->prox = no->prox;
            no->prox->ant = no->ant;
            search->valor.total_carrinho--;
            free(no);
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 5;
}

void mostra_lista_clientes(lista_clientes *l)
{
    if (l == NULL)
    {
        printf("Lista de clientes nao criada!\n");
        return;
    }
    if (lista_clientes_vazia(l) == 0)
    {
        printf("Lista de clientes vazia!\n");
        return;
    }
    no_clientes *search = l->inicio;
    int i = 0;
    while (search != NULL)
    {
        printf("Cliente %d: Nome: %s     Senha: %s\n", i, search->valor.cadastro.nome, search->valor.cadastro.senha);
        printf("Historico de compras: (total: %d)\n", search->valor.total_comprados);
        no_comprados *prod = search->valor.comprados_inicio;
        int j = 0;
        while (prod != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", prod->produto.NOME);
            printf("        Categoria: %d\t", prod->produto.CATEGORIA);
            printf("        Nota de Avalicao: %d\t", prod->produto.NOTA_AVALIACAO);
            printf("        Quantidade: %d\t", prod->produto.QUANTIDADE);
            printf("        Valor: %.2f\t", prod->produto.VALOR);
            printf("        Descricao: %s}\n", prod->produto.DESCRICAO);
            j++;
            prod = prod->prox;
        }
        if (search->valor.comprados_inicio == NULL)
            printf("Nenhum produto foi comprado!\n");
        j = 0;
        printf("\nProdutos no Carrinho: (total:%d)\n", search->valor.total_carrinho);
        no_carrinho *prodc = search->valor.carrinho_inicio;
        while (prodc != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", prodc->produto.NOME);
            printf("        Categoria: %d\t", prodc->produto.CATEGORIA);
            printf("        Nota de Avalicao: %d\t", prodc->produto.NOTA_AVALIACAO);
            printf("        Quantidade: %d\t", prodc->produto.QUANTIDADE);
            printf("        Valor: %.2f\t", prodc->produto.VALOR);
            printf("        Descricao: %s}\n", prodc->produto.DESCRICAO);
            j++;
            prodc = prodc->prox;
        }
        if (search->valor.carrinho_inicio == NULL)
            printf("Carrinho vazio!\n");
        printf("\n");
        i++;
        search = search->prox;
    }
    return;
}

void mostrar_conta_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
    {
        printf("Lista de clientes nao criada!\n");
        return;
    }
    if (lista_clientes_vazia(l) == 0)
    {
        printf("Lista de clientes vazia!\n");
        return;
    }
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            printf("Nome: %s   ", search->valor.cadastro.nome);
            printf("Senha: %s\n", search->valor.cadastro.senha);
            int j = 0;
            no_comprados *prod = search->valor.comprados_inicio;
            printf("Historico de compras: (total: %d)\n", search->valor.total_comprados);
            while (prod != NULL)
            {
                printf("{Produto %d:", j);
                printf("        Nome: %s\t", prod->produto.NOME);
                printf("        Categoria: %d\t", prod->produto.CATEGORIA);
                printf("        Nota de Avalicao: %d\t", prod->produto.NOTA_AVALIACAO);
                printf("        Quantidade: %d\t", prod->produto.QUANTIDADE);
                printf("        Valor: %.2f\t", prod->produto.VALOR);
                printf("        Descricao: %s}\n", prod->produto.DESCRICAO);
                j++;
                prod = prod->prox;
            }
            if (search->valor.comprados_inicio == NULL)
                printf("Nenhum produto foi comprado!\n");
            j = 0;
            printf("\nProdutos no Carrinho: (total:%d)\n", search->valor.total_carrinho);
            no_carrinho *prodc = search->valor.carrinho_inicio;
            while (prodc != NULL)
            {
                printf("{Produto %d:", j);
                printf("        Nome: %s\t", prodc->produto.NOME);
                printf("        Categoria: %d\t", prodc->produto.CATEGORIA);
                printf("        Nota de Avalicao: %d\t", prodc->produto.NOTA_AVALIACAO);
                printf("        Quantidade: %d\t", prodc->produto.QUANTIDADE);
                printf("        Valor: %.2f\t", prodc->produto.VALOR);
                printf("        Descricao: %s}\n", prodc->produto.DESCRICAO);
                j++;
                prodc = prodc->prox;
            }
            if (search->valor.carrinho_inicio == NULL)
                printf("Carrinho vazio!\n");
            printf("\n");
            return;
        }
        search = search->prox;
    }
    // cliente nao existe
    return;
}

int excluir_conta_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            if(search->ant == NULL){
                l->inicio = search->prox;
                if(l->inicio != NULL) l->inicio->prox->ant = NULL;
                l->total_clientes--;
                limpa_compra_carrinho(l,it);
                free(search);
                return 0;
            }
            if(search->prox == NULL){
                search->ant->prox = NULL;
                l->total_clientes--;
                limpa_compra_carrinho(l,it);
                free(search);
                return 0;
            }
            search->prox->ant = search->ant;
            search->ant->prox = search->prox;
            l->total_clientes--;
            limpa_compra_carrinho(l,it);
            free(search);
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 3;
}

int limpa_lista_clientes(lista_clientes *l){
    if(l == NULL) return 1;
    no_clientes *no = l->inicio;
    while(lista_clientes_vazia(l) == 0){
        excluir_conta_cliente(l,no->valor.cadastro);
        no = no->prox;
    }
    return 0;
}

int limpa_compra_carrinho(lista_clientes *l,cadastro it){
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0 && strcmp(it.senha, search->valor.cadastro.senha) == 0)
        {
            if (lista_carrinho_vazia(&search->valor) == 0 && lista_comprados_vazia(&search->valor) == 0)
                return 3; // carrinho e comprados vazio
            no_carrinho *no = search->valor.carrinho_inicio;
            while (no != NULL )
            {
                no_carrinho *temp = no;
                free(temp);
                search->valor.total_carrinho--;
                no = no->prox;
            }
            no_comprados *no2 = search->valor.comprados_inicio;
            while(no2 != NULL){
                no_comprados *temp2 = no2;
                free(temp2);
                search->valor.total_comprados--;
                no2 = no2->prox;
            }//carrinhoe comprados limpos
            search->valor.carrinho_inicio = NULL;
            search->valor.comprados_inicio = NULL;
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 5;
}