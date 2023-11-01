#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "ListaEncad.h"

/*                                  CLIENTES   */
/*                                  CLIENTES   */
/*                                  CLIENTES   */

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

int verifica_cliente(lista_clientes *l, cadastro it)
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
    user->valor.total_carrinho = 0;
    user->valor.comprados_inicio = NULL;
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
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = (no_produtos *)malloc(sizeof(no_produtos));
        no->produto = p;
        no->prox = search->valor.comprados_inicio;
        no->ant = NULL;
        if (search->valor.comprados_inicio != NULL)
        {
            search->valor.comprados_inicio->ant = no;
        }
        search->valor.comprados_inicio = no;
        search->valor.total_comprados++;
        return 0;
    }
    return 2;
}

int insere_novo_carrinho(lista_clientes *l, cadastro it, produtos p)
{
    if (l == NULL)
        return 1;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = (no_produtos *)malloc(sizeof(no_produtos));
        no->produto = p;
        no->prox = search->valor.carrinho_inicio;
        no->ant = NULL;
        if (search->valor.carrinho_inicio != NULL)
        {
            search->valor.carrinho_inicio->ant = no;
        }
        search->valor.carrinho_inicio = no;
        search->valor.total_carrinho++;
        return 0;
    }
    return 2;
}

int remove_do_carrinho(lista_clientes *l, cadastro it, int pos)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = search->valor.carrinho_inicio;
        while (no != NULL && pos > 0)
        {
            pos--;
            no = no->prox;
        }
        if (no->prox == NULL)
        {
            if (no->ant == NULL)
            {
                search->valor.carrinho_inicio = NULL;
                free(no);
                search->valor.total_carrinho--;
                return 0;
            }
            no->ant->prox = NULL;
            free(no);
            search->valor.total_carrinho--;
            return 0;
        }
        if (no->ant == NULL)
        {
            search->valor.carrinho_inicio = no->prox;
            if (no->prox != NULL)
            {
                no->prox->ant = NULL;
            }
            free(no);
            search->valor.total_carrinho--;
            return 0;
        }
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
        free(no);
        search->valor.total_carrinho--;
        return 0;
    }
    return 3;
}

int remove_do_comprados(lista_clientes *l, cadastro it, int pos)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = search->valor.comprados_inicio;
        while (no != NULL && pos > 0)
        {
            pos--;
            no = no->prox;
        }
        if (no->prox == NULL)
        {
            if (no->ant == NULL)
            {
                search->valor.comprados_inicio = NULL;
                free(no);
                search->valor.total_comprados--;
                return 0;
            }
            no->ant->prox = NULL;
            free(no);
            search->valor.total_comprados--;
            return 0;
        }
        if (no->ant == NULL)
        {
            search->valor.comprados_inicio = no->prox;
            if (no->prox != NULL)
            {
                no->prox->ant = NULL;
            }
            free(no);
            search->valor.total_comprados--;
            return 0;
        }
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
        free(no);
        search->valor.total_comprados--;
        return 0;
    }
    return 3;
}

// Função de debug
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
            printf("        Quantidade de Avaliacoes: %d\t", prod->produto.QUANT_AVALIACAO);
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
            printf("        Quantidade de Avaliacoes: %d\t", prod->produto.QUANT_AVALIACAO);
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
        return;
    if (lista_clientes_vazia(l) == 0)
        return;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        printf("Nome: %s     Senha: %s\n", search->valor.cadastro.nome, search->valor.cadastro.senha);
        printf("Historico de compras: (total: %d)\n", search->valor.total_comprados);
        no_produtos *prod = search->valor.comprados_inicio;
        int j = 0;
        while (prod != NULL)
        {
            printf("{Produto %d:", j);
            printf("        Nome: %s\t", prod->produto.NOME);
            printf("        Categoria: %d\t", prod->produto.CATEGORIA);
            printf("        Quantidade de Avaliacoes: %d\t", prod->produto.QUANT_AVALIACAO);
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
            printf("        Quantidade de Avaliacoes: %d\t", prod->produto.QUANT_AVALIACAO);
            printf("        Nota de Avalicao: %d\t", prod->produto.NOTA_AVALIACAO);
            printf("        Quantidade: %d\t", prod->produto.QUANTIDADE);
            printf("        Valor: %.2f\t", prod->produto.VALOR);
            printf("        Descricao: %s}\n", prod->produto.DESCRICAO);
            j++;
            prod = prod->prox;
        }
        if (search->valor.carrinho_inicio == NULL)
            printf("Nenhum produto no carrinho!\n");
        printf("\n");
        return;
    }
    return;
}

void mostrar_carrinho(lista_clientes *l, cadastro it)
{
    if (l != NULL)
        if (lista_clientes_vazia(l) != 0)
        {
            no_clientes *search = buscar_cliente(l, it);
            if (search != NULL)
            {
                int j = 1;
                printf("\nProdutos no Carrinho: (total:%d)\n\n", search->valor.total_carrinho);
                if (search->valor.carrinho_inicio == NULL)
                {
                    printf("Nenhum produto no carrinho!\n");
                }
                else
                {
                    no_produtos *prod = search->valor.carrinho_inicio;
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
                }
            }
        }
}

void mostrar_comprados(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return;
    if (lista_clientes_vazia(l) == 0)
        return;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        int j = 1;
        printf("\nHistorico de Produtos Comprados: (total:%d)\n\n", search->valor.total_comprados);
        if (search->valor.comprados_inicio == NULL)
        {
            printf("Nenhum produto no comprados!\n");
            return;
        }
        no_produtos *prod = search->valor.comprados_inicio;
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
    return;
}

int excluir_conta_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        if (search->ant == NULL) // Primeiro cliente da lista
        {
            limpa_compra_carrinho(l, search->valor.cadastro);
            l->inicio = search->prox;
            if (l->inicio != NULL)
                l->inicio->prox->ant = NULL;
            l->total_clientes--;
            free(search);
            return 0;
        }
        if (search->prox == NULL) // Ultimo cliente da lista
        {
            limpa_compra_carrinho(l, search->valor.cadastro);
            search->ant->prox = NULL;
            l->total_clientes--;
            free(search);
            return 0;
        } // Cliente no meio
        limpa_compra_carrinho(l, search->valor.cadastro);
        search->prox->ant = search->ant;
        search->ant->prox = search->prox;
        l->total_clientes--;
        free(search);
        return 0;
    }
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
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        if (search->valor.carrinho_inicio == NULL && search->valor.comprados_inicio == NULL)
            return 0; // Carrinho e comprados vazio
        int i = 0;
        while (i != search->valor.total_carrinho) // Limpa carrinho
        {
            remove_do_carrinho(l, it, 0);
            i++;
        }
        i = 0;
        while (i != search->valor.total_comprados) // Limpa comprados
        {
            remove_do_comprados(l, it, 0);
            i++;
        } // Carrinho e comprados limpos
        search->valor.carrinho_inicio = NULL;
        search->valor.comprados_inicio = NULL;
        return 0;
    }
    return 3;
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

int insere_do_carrinho_para_comprados(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = search->valor.carrinho_inicio;
        if (no != NULL)
        {
            while (no != NULL)
            {
                insere_nova_compra(l, it, no->produto);
                no = no->prox;
            }
            limpa_carrinho(l, it);
            return 0;
        }
        return 0;
    }
    return 3;
}

int limpa_carrinho(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return 1;
    if (lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no = search->valor.carrinho_inicio;
        while (no != NULL)
        {
            remove_do_carrinho(l, it, 0);
            no = no->prox;
        }
        search->valor.carrinho_inicio = NULL;
        return 0;
    }
    return 3;
}

int avaliar_produto(lista_vendedores *l2, lista_clientes *l, cadastro it, int pos, int num)
{
    if (l2 == NULL || l == NULL)
        return 1;
    if (lista_vendedores_vazia(l2) == 0 || lista_clientes_vazia(l) == 0)
        return 2;
    no_clientes *search = buscar_cliente(l, it);
    if (search != NULL)
    {
        no_produtos *no2 = search->valor.comprados_inicio;
        while (no2 != NULL && pos > 0)
        {
            pos--;
            no2 = no2->prox;
        }
        int nova_avaliacao = no2->produto.NOTA_AVALIACAO;
        nova_avaliacao = ((nova_avaliacao + num) / (no2->produto.QUANT_AVALIACAO + 1));
        no_vendedores *no3 = l2->inicio;
        while (no3 != NULL)
        {
            if (strcmp(no2->produto.nome_loja, no3->valor.nome_loja) == 0)
            {
                no_produtos *no4 = no3->valor.inicio;
                while(no4 != NULL){
                    if(strcmp(no4->produto.NOME,no2->produto.NOME) == 0){
                        no2->produto.NOTA_AVALIACAO = nova_avaliacao;
                        no2->produto.QUANT_AVALIACAO++;
                        no4->produto.NOTA_AVALIACAO = nova_avaliacao;
                        no4->produto.QUANT_AVALIACAO++;
                        return 0;
                    }
                    no4 = no4->prox;
                }
            }
            no3 = no3->prox;
        }
    }
    return 3;
}

no_clientes *buscar_cliente(lista_clientes *l, cadastro it)
{
    if (l == NULL)
        return NULL;
    if (lista_clientes_vazia(l) == 0)
        return NULL;
    no_clientes *no = l->inicio;
    while (no != NULL)
    {
        if (strcmp(it.nome, no->valor.cadastro.nome) == 0 && strcmp(it.senha, no->valor.cadastro.senha) == 0)
        {
            return no;
        }
        no = no->prox;
    }
    return NULL;
}

produtos compra_produto(lista_clientes *c, lista_vendedores *l, lista_produtos *p, cadastro it, int qtd, int pos)
{
    if (c != NULL && l != NULL && p != NULL)
    {
        no_clientes *no = buscar_cliente(c, it);
        if (no != NULL)
        {
            no_produtos *no1 = p->inicio; // Procura pelo produto na lista de pordutos
            while (no1 != NULL && pos > 0)
            {
                pos--;
                no1 = no1->prox;
            }
            produtos p1 = no1->produto;
            no_vendedores *no2 = l->inicio;
            while (no2 != NULL)
            {
                if (strcmp(no2->valor.nome_loja, p1.nome_loja) == 0)
                {
                    no_produtos *no3 = no2->valor.inicio;
                    while (no3 != NULL)
                    {
                        if (strcmp(no3->produto.NOME, p1.NOME) == 0)
                        {
                            if (no3->produto.QUANTIDADE <= qtd)
                            {
                                no3->produto.QUANTIDADE = 0;
                                p1.QUANTIDADE = qtd;
                                no1->produto.QUANTIDADE = 0;
                                return p1;
                            }
                            no3->produto.QUANTIDADE = no3->produto.QUANTIDADE - qtd;
                            p1.QUANTIDADE = qtd;
                            no1->produto.QUANTIDADE = no1->produto.QUANTIDADE - qtd;
                            return p1;
                        }
                        no3 = no3->prox;
                    }
                }
                no2 = no2->prox;
            }
        }
    }
}

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

int retorna_5_produtos(lista_vendedores *v, lista_clientes *l, cadastro it, lista_produtos *p)
{
    if (v == NULL || p == NULL)
        return 2;
    no_clientes *no = buscar_cliente(l, it);
    if (no == NULL)
        return 3;
    srand(time(NULL));
    produtos aux;
    lista_produtos *todos = criar_lista_produtos();
    int t = 0, x, total;
    total = conta_produtos_total(v);
    if (v->total_vendedores == 0 || total == 0)
        return 0;
    if (no->valor.total_comprados == 0)
    {
        if (produtos_registrados(v, todos) != 0)
            return -1;
        if (total > 5)
            total = 5;
        while (t < total)
        {
            x = rand() % tamanho_lista_produtos(todos);
            if (buscar_produto_posicao(todos, &aux, x) == 0)
            {
                remover_posicao_produto(todos, x);
                inserirInicio_produtos(p, aux);
                t++;
            }
        }
        limpar_lista_produtos(todos);
        return 0;
    }

    // Mostrar relacionado as compras do cliente
    int cat = no->valor.comprados_inicio->produto.CATEGORIA;
    produtos_de_categoria(v, cat, todos);
    total = tamanho_lista_produtos(todos);
    if (total > 5)
        total = 5;
    while (t < total)
    {
        x = rand() % tamanho_lista_produtos(todos);
        if (buscar_produto_posicao(todos, &aux, x) == 0)
        {
            remover_posicao_produto(todos, x);
            inserirInicio_produtos(p, aux);
            t++;
        }
    }
    limpar_lista_produtos(todos);
    return 0;
}

int produtos_de_categoria(lista_vendedores *v, int categoria, lista_produtos *p)
{
    if (v == NULL || (categoria < 0 || categoria > 12))
        return 2;
    if (lista_vendedores_vazia(v) == 0)
        return 1;
    no_vendedores *no = v->inicio;
    no_produtos *nl = NULL;

    while (no != NULL)
    {
        nl = no->valor.inicio;
        while (nl != NULL)
        {
            if (nl->produto.CATEGORIA == categoria)
            {
                inserirInicio_produtos(p, nl->produto);
            }
            nl = nl->prox;
        }
        no = no->prox;
    }
    return 0;
}

int produtos_de_nome(lista_vendedores *v, char *pesquisa, lista_produtos *p)
{
    if (v == NULL)
        return 2;
    if (lista_vendedores_vazia(v) == 0)
        return 1;
    no_vendedores *no = v->inicio;
    no_produtos *nl = NULL;
    while (no != NULL)
    {
        nl = no->valor.inicio;
        while (nl != NULL)
        {
            if (strcmp(nl->produto.NOME, pesquisa) == 0)
                inserirInicio_produtos(p, nl->produto);
            nl = nl->prox;
        }
        no = no->prox;
    }
    return 0;
}

void zerar_produtos(lista_produtos *l)
{
    while (listaVazia_produtos(l) != 0)
        removerInicio_produtos(l);
}
/*FUNÇAO QUE PODEMOS USAR POSTERIORMENTE
int buscar_produto_no_vendedor_posicao(vendedor v, int pos, produtos *p){
    if (v.total_produtos == 0)
        return 1;
    if (p == NULL)
        return 2;
    if (pos < 0)
        return 3;
    no_produtos *no = v.inicio;
    while (no->prox != NULL && pos > 0)
    {
        no = no->prox;
    }
    *p = no->produto;
    return 0;
}
*/
int remover_posicao_produto(lista_produtos *p, int pos)
{
    if (p == NULL)
        return 2;
    if (pos < 0)
        return 1;
    if (listaVazia_produtos(p) == 0)
        return 3;
    no_produtos *atual = p->inicio;
    while (atual->prox != NULL && pos > 0)
    {
        atual = atual->prox;
        pos--;
    }
    if (atual->ant == NULL)
        return removerInicio_produtos(p);
    if (atual->prox == NULL)
    {
        // Caso remover FIM
        atual->ant->prox = NULL;
        free(atual);
        return 0;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    free(atual);
    return 0;
}

int conta_produtos_total(lista_vendedores *l)
{
    if (l == NULL)
        return -2;
    if (lista_vendedores_vazia(l) == 0)
        return -1;
    no_vendedores *no = l->inicio;
    no_produtos *nl = NULL;
    int cont = 0;
    while (no != NULL)
    {
        nl = no->valor.inicio;
        while (nl != NULL)
        {
            cont++;
            nl = nl->prox;
        }
        no = no->prox;
    }
    return cont;
}

int verifica_produto(lista_produtos *p, produtos it)
{
    if (p == NULL)
        return 1;
    no_produtos *atual = p->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->produto.NOME, it.NOME) == 0)
        {
            return 0;
        }
        atual = atual->prox;
    }
    return 3;
}

int buscar_produto_posicao(lista_produtos *p, produtos *it, int pos)
{
    if (p == NULL)
        return 1;
    if (listaVazia_produtos(p) == 0)
        return 2;
    no_produtos *atual = p->inicio;
    while (atual->prox != NULL && pos > 0)
    {
        atual = atual->prox;
        pos--;
    }
    *it = atual->produto;
    return 0;
}

int produtos_registrados(lista_vendedores *v, lista_produtos *p)
{
    if (v == NULL || p == NULL)
        return 2;
    if (conta_produtos_total(v) < 0)
        return 1;
    no_vendedores *no = v->inicio;
    no_produtos *nl = NULL;
    while (no != NULL)
    {
        nl = no->valor.inicio;
        while (nl != NULL)
        {
            inserirInicio_produtos(p, nl->produto);
            nl = nl->prox;
        }
        no = no->prox;
    }
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
        if (strcmp(atual->valor.cadastro.nome, v.cadastro.nome) == 0 && strcmp(atual->valor.nome_loja, v.nome_loja) == 0 && strcmp(atual->valor.cadastro.senha, v.cadastro.senha) == 0)
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
        if (strcmp(atual->valor.cadastro.nome, v->cadastro.nome) == 0 && strcmp(atual->valor.cadastro.senha, v->cadastro.senha) == 0)
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

int atualiza_lista_vendedores(vendedor v, lista_vendedores *l)
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
            atual->valor = v;
            return 0;
        }
        atual = atual->prox;
    }
    return 3;
}

int buscar_por_posicao_vendedor(lista_vendedores *l, int pos, vendedor *v)
{
    if (l == NULL)
        return 2;
    if (lista_vendedores_vazia(l) == 0)
        return 1;
    if (pos < 0)
        return 3;
    no_vendedores *no = l->inicio;
    while (no->prox != NULL && pos > 0)
    {
        no = no->prox;
        pos--;
    }
    *v = no->valor;
    return 0;
}