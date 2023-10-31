#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cadastro
{
    char nome[30];
    char senha[10];
} cadastro;

typedef struct produtos
{
    char NOME[30];
    char DESCRICAO[100];
    float VALOR;
    int CATEGORIA;
    int QUANTIDADE;
    int QUANT_AVALIACAO;
    int NOTA_AVALIACAO;
    char nome_loja[30];
} produtos;

typedef struct no_produtos
{
    produtos produto;
    struct no_produtos *prox;
    struct no_produtos *ant;
} no_produtos;


typedef struct vendedor
{
    int total_produtos;
    no_produtos *inicio; // o vendedor armazena o inicio do nó, ou seja é como se vendedor fosse a lista l q tem l->inicio
    cadastro cadastro;
    char nome_loja[30];
} vendedor;

typedef struct no_vendedores
{
    vendedor valor;
    struct no_vendedores *prox;
    struct no_vendedores *ant;
} no_vendedores;


typedef struct lista_vendedores
{
    int total_vendedores;
    no_vendedores *inicio;
} lista_vendedores;

typedef struct lista_produtos
{
    no_produtos *inicio;
} lista_produtos;


//                               TAD PRODUTOS

lista_produtos *criar();

void limpar_lista_produtos(lista_produtos *l);
int tamanho_lista_produtos(lista_produtos *l);
void mostrar_produtos(lista_produtos *l);

int inserirInicio_produtos(lista_produtos *l, produtos it);

int removerInicio_produtos(lista_produtos *l);

int listaVazia_produtos(lista_produtos *l);

//                              TAD VENDEDOR

lista_vendedores *criar_lista_vendedores();

int lista_vendedores_vazia(lista_vendedores *l);

int verifica_vendedor(lista_vendedores *l, vendedor v);

int insere_novo_vendedor(lista_vendedores *l, vendedor v);

void mostrar_lista_vendedores(lista_vendedores *l);

// int vendedor_adiciona_produtos(vendedor v,);

#endif