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
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            // Cliente já exite na lista
            return 0;
        }
        search = search->prox;
    }
    // Cliente não existe
    return 3;
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
            no_produtos *no = (no_produtos *)malloc(sizeof(no_produtos));
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
        // Procura pelo cliente
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            no_produtos *no = (no_produtos *)malloc(sizeof(no_produtos));
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
    // Cliente nao existe
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
        // Procura pelo cliente
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            if (lista_carrinho_vazia(&search->valor) == 0)
                return 3; // Carrinho vazio
            if (pos > search->valor.total_carrinho || pos < 0)
                return 4; // Posicao maior que o total de produtos no carrinho ou posição menor que 0
            no_produtos *no = search->valor.carrinho_inicio;
            while (no->prox != NULL && pos > 0) // Procura pela posição
            {
                pos--;
                no = no->prox;
            }
            if (no->ant == NULL) // Primeiro produto da lista do carrinho
            {
                search->valor.carrinho_inicio = no->prox;
                search->valor.total_carrinho--;
                if (search->valor.carrinho_inicio != NULL)
                    search->valor.carrinho_inicio->ant = NULL;
                free(no);
                return 0;
            }
            if (no->prox == NULL) // Ultimo produto da lista do carrinho
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
    // Cliente não existe
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
        no_produtos *prod = search->valor.comprados_inicio;
        int j = 0;
        while (prod != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", prod->produto.NOME);
            printf("        Categoria: %d\t", prod->produto.CATEGORIA);
            printf("        Quantidade de Avaliacoes: %d\t",prod->produto.QUANT_AVALIACAO);
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
        prod = search->valor.carrinho_inicio;
        while (prod != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", prod->produto.NOME);
            printf("        Categoria: %d\t", prod->produto.CATEGORIA);
            printf("        Quantidade de Avaliacoes: %d\t",prod->produto.QUANT_AVALIACAO);
            printf("        Nota de Avalicao: %d\t", prod->produto.NOTA_AVALIACAO);
            printf("        Quantidade: %d\t", prod->produto.QUANTIDADE);
            printf("        Valor: %.2f\t", prod->produto.VALOR);
            printf("        Descricao: %s}\n", prod->produto.DESCRICAO);
            j++;
            prod = prod->prox;
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
        // Procura pelo cliente
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            printf("Nome: %s   ", search->valor.cadastro.nome);
            printf("Senha: %s\n", search->valor.cadastro.senha);
            int j = 0;
            no_produtos *prod = search->valor.comprados_inicio;
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
            prod = search->valor.carrinho_inicio;
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

void mostrar_carrinho(lista_clientes *l, cadastro it)
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
    no_clientes *no = l->inicio;
    while (no != NULL)
    {
        // Procura cliente
        if (strcmp(it.nome, no->valor.cadastro.nome) == 0)
        {
            int j = 1;
            printf("\nProdutos no Carrinho: (total:%d)\n\n", no->valor.total_carrinho);
            if (no->valor.carrinho_inicio == NULL)
            {
                printf("Nenhum produto no carrinho!\n");
                return;
            }
            no_produtos *prod = no->valor.carrinho_inicio;
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
            return;
        }
        no = no->prox;
    }
    // Cliente nao encontrado
    return;
}

void mostrar_comprados(lista_clientes *l, cadastro it)
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
    no_clientes *no = l->inicio;
    while (no != NULL)
    {
        // Procura cliente
        if (strcmp(it.nome, no->valor.cadastro.nome) == 0)
        {
            int j = 1;
            printf("\nHistorico de Produtos Comprados: (total:%d)\n\n", no->valor.total_comprados);
            if (no->valor.comprados_inicio == NULL)
            {
                printf("Nenhum produto foi comprado!\n");
                return;
            }
            no_produtos *prod = no->valor.comprados_inicio;
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
            return;
        }
        no = no->prox;
    }
    // Cliente nao encontrado
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
        // Procura pelo cliente
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            if (search->ant == NULL) // Primeiro cliente da lista
            {
                l->inicio = search->prox;
                if (l->inicio != NULL)
                    l->inicio->prox->ant = NULL;
                l->total_clientes--;
                limpa_compra_carrinho(l, it);
                free(search);
                return 0;
            }
            if (search->prox == NULL) // Ultimo cliente da lista
            {
                search->ant->prox = NULL;
                l->total_clientes--;
                limpa_compra_carrinho(l, it);
                free(search);
                return 0;
            } // Cliente no meio
            search->prox->ant = search->ant;
            search->ant->prox = search->prox;
            l->total_clientes--;
            limpa_compra_carrinho(l, it);
            free(search);
            return 0;
        }
        search = search->prox;
    }
    // cliente nao existe
    return 3;
}

int limpa_lista_clientes(lista_clientes *l)
{
    if (l == NULL)
        return 1;
    no_clientes *no = l->inicio;
    while (no != NULL) // Limpa cliente por cliente
    {
        excluir_conta_cliente(l, no->valor.cadastro);
        no = no->prox;
    }
    l->inicio = NULL;
    return 0;
}

int limpa_compra_carrinho(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = l->inicio;
    while (search != NULL)
    {
        // Procura pelo cliente
        if (strcmp(it.nome, search->valor.cadastro.nome) == 0)
        {
            if (lista_carrinho_vazia(&search->valor) == 0 && lista_comprados_vazia(&search->valor) == 0)
                return 3; // Carrinho e comprados vazio
            no_produtos *no = search->valor.carrinho_inicio;
            while (no != NULL) // Limpa carrinho
            {
                no_produtos *temp = no;
                free(temp);
                search->valor.total_carrinho--;
                no = no->prox;
            }
            no = search->valor.comprados_inicio;
            while (no != NULL) // Limpa comprados
            {
                no_produtos *temp = no;
                free(temp);
                search->valor.total_comprados--;
                no = no->prox;
            } // Carrinho e comprados limpos
            search->valor.carrinho_inicio = NULL;
            search->valor.comprados_inicio = NULL;
            return 0;
        }
        search = search->prox;
    }
    // Cliente nao existe
    return 5;
}

int salvar_clientes(lista_clientes *l)
{
    FILE *arquivo;
    arquivo = fopen("arquivo_clientes.txt", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    no_clientes *no = l->inicio;
    while (no != NULL)
    {
        // Escreve os dados do cliente
        fwrite(&no->valor, sizeof(cliente), 1, arquivo);
        // Escreve os dados dos produtos no carrinho
        no_produtos *no2 = no->valor.carrinho_inicio;
        while (no2 != NULL)
        {
            fwrite(&no2->produto, sizeof(produtos), 1, arquivo);
            no2 = no2->prox;
        }
        // Escreve os dados dos produtos comprados
        no2 = no->valor.comprados_inicio;
        while (no2 != NULL)
        {
            fwrite(&no2->produto, sizeof(produtos), 1, arquivo);
            no2 = no2->prox;
        }
        no = no->prox;
    }
    fclose(arquivo);
    return 0;
}

lista_clientes *ler_clientes()
{
    FILE *arquivo;
    arquivo = fopen("arquivo_clientes.txt", "rb");
    lista_clientes *lista = (lista_clientes *)malloc(sizeof(lista_clientes));
    lista->total_clientes = 0;
    lista->inicio = NULL;
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return lista;
    }
    cliente cliente_lido;
    while (fread(&cliente_lido, sizeof(cliente), 1, arquivo))
    {
        // Cria um novo cliente
        no_clientes *novo_cliente = (no_clientes *)malloc(sizeof(no_clientes));
        novo_cliente->valor = cliente_lido;
        novo_cliente->prox = NULL;
        novo_cliente->ant = NULL;
        // Adiciona novo cliente na lista
        if (lista->inicio == NULL)
        {
            lista->inicio = novo_cliente;
        }
        else
        {
            novo_cliente->prox = lista->inicio;
            lista->inicio->ant = novo_cliente;
            lista->inicio = novo_cliente;
        }
        lista->total_clientes++;
        // Le os dados dos produtos no carrinho
        no_produtos *no_carrinho = NULL;
        for (int i = 0; i < cliente_lido.total_carrinho; i++)
        {
            no_produtos *novo_produto = (no_produtos *)malloc(sizeof(no_produtos));
            fread(&novo_produto->produto, sizeof(produtos), 1, arquivo);
            novo_produto->prox = NULL;
            novo_produto->ant = NULL;
            if (no_carrinho == NULL)
            {
                no_carrinho = novo_produto;
                novo_cliente->valor.carrinho_inicio = no_carrinho;
            }
            else
            {
                no_carrinho->prox = novo_produto;
                novo_produto->ant = no_carrinho;
                no_carrinho = no_carrinho->prox;
            }
        }
        // Le os dados dos produtos comprados
        no_produtos *no_comprados = NULL;
        for (int i = 0; i < cliente_lido.total_comprados; i++)
        {
            no_produtos *novo_produto = (no_produtos *)malloc(sizeof(no_produtos));
            fread(&novo_produto->produto, sizeof(produtos), 1, arquivo);
            novo_produto->prox = NULL;
            novo_produto->ant = NULL;
            if (no_comprados == NULL)
            {
                no_comprados = novo_produto;
                novo_cliente->valor.comprados_inicio = no_comprados;
            }
            else
            {
                no_comprados->prox = novo_produto;
                novo_produto->ant = no_comprados;
                no_comprados = no_comprados->prox;
            }
        }
    }
    fclose(arquivo);
    return lista;
}

int insere_carrinho_comprados(lista_clientes *l,cadastro it){
    if(l == NULL) return 1;
    if(lista_clientes_vazia(l) == 0) return 2;
    no_clientes *no = l->inicio;
    while(no != NULL){
        if(strcmp(it.nome,no->valor.cadastro.nome) == 0){
            no_produtos *no2 = no->valor.carrinho_inicio;
            while(no2 != NULL){
                insere_nova_compra(l,it,no2->produto);
                no2 = no2->prox;
            }
            return 0;
        }
        no = no->prox;
    }
    return 3;
}

int limpa_carrinho(lista_clientes *l,cadastro it){
    if(l == NULL) return 1;
    if(lista_clientes_vazia(l) == 0) return 2;
    no_clientes *no = l->inicio;
    while(no != NULL){
        if(strcmp(it.nome,no->valor.cadastro.nome) == 0){
            no_produtos *no2 = no->valor.carrinho_inicio;
            while(no2 != NULL){
                no_produtos *temp = no2;
                no->valor.carrinho_inicio = no2->prox;
                no2 = no2->prox;
                free(temp);
            }
            return 0;
        }
        no = no->prox;
    }
    return 3;
}

int avaliar_produto(lista_clientes *l,lista_vendedores *l2,cadastro it, int pos,int num){
    if(l == NULL || l2 == NULL) return 1;
    if(lista_clientes_vazia(l) == 0) return 2; // falta lista vazia dos vendedores
    no_clientes *no = l->inicio;
    while(no != NULL){
        if(strcmp(it.nome,no->valor.cadastro.nome) == 0){
            no_produtos *no2 = no->valor.carrinho_inicio;
            while(no2 != NULL && pos > 0){
                pos--;
                no2 = no2->prox;
            }
            int nova_avaliacao = no2->produto.NOTA_AVALIACAO;
            nova_avaliacao = ((nova_avaliacao + num)/(no2->produto.QUANT_AVALIACAO + 1));
            no_vendedores *no3 = l2->inicio;
            while(no3 != NULL){
                no_produtos *no4 = no3->valor.inicio;
                while(no4 != NULL){
                    if(strcmp(no2->produto.NOME,no4->produto.NOME) == 0){
                        no4->produto.NOTA_AVALIACAO = nova_avaliacao;
                        no4->produto.QUANT_AVALIACAO++;
                        return 0;
                    }
                    no4 = no4->prox;
                }
                no3 = no3->prox;
            }
            return 0;
        }
        no = no->prox;
    }
    return 3;
}


// Produtos

Lista *criar_lista_produtos()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar_lista_produtos(Lista *l)
{
    while (listaVazia_produtos(l) != 0)
        removerInicio_produtos(l);
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
        int j;
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
    if (listaVazia_produtos(l) == 0)
        return 1;
    no_produtos *no_Lista = l->inicio;
    l->inicio = no_Lista->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    free(no_Lista);

    return 0;
}
