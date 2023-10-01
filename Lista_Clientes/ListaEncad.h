#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cadastro {
    char nome[30];
    char senha[10];   
} cadastro;

typedef struct produtos {
    int CATEGORIA;
    char NOME[30];
    char DESCRICAO[100];
    float VALOR;
    int QUANTIDADE;
    int NOTA_AVALIACAO;
} produtos;

typedef struct no_carrinho {
    produtos produto;
    struct no_carrinho *prox;
    struct no_carrinho *ant;
} no_carrinho;

typedef struct no_comprados {
    produtos produto;
    struct no_comprados *prox;
    struct no_comprados *ant;
} no_comprados;

typedef struct cliente {
    int total_carrinho;
    int total_comprados;
    no_carrinho *carrinho_inicio;
    cadastro cadastro;
    no_comprados *comprados_inicio;
} cliente;

typedef struct no_clientes {
    cliente valor;
    struct no_clientes *prox;
    struct no_clientes *ant;
} no_clientes;

typedef struct lista_clientes {
    int total_clientes;
    no_clientes *inicio;
} lista_clientes;

lista_clientes *criar_lista_clientes();

int lista_clientes_vazia(lista_clientes *l);

int lista_carrinho_vazia(cliente *l);

int lista_comprados_vazia(cliente *l);

int verifica_cliente(lista_clientes *l,cadastro it);

int insere_novo_cliente(lista_clientes *l,cadastro it);

int insere_nova_compra(lista_clientes *l,cadastro it,produtos p);

int insere_novo_carrinho(lista_clientes *l,cadastro it,produtos p);

int remove_do_carrinho(lista_clientes *l,cadastro it,int pos);

void mostra_lista_clientes(lista_clientes *l);

#endif