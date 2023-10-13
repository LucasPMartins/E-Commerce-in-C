#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cadastro {
    char nome[30];
    char senha[10];   
} cadastro;

typedef struct produtos {
    char NOME[30];
    char DESCRICAO[100];
    float VALOR;
    int CATEGORIA;
    int QUANTIDADE;
    int QUANT_AVALIACAO;
    int NOTA_AVALIACAO;
} produtos;

typedef struct no_produtos {
    produtos produto;
    struct no_produtos *prox;
    struct no_produtos *ant;
} no_produtos;

typedef struct cliente {
    int total_carrinho;
    int total_comprados;
    no_produtos *carrinho_inicio;
    no_produtos *comprados_inicio;
    cadastro cadastro;
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

void mostrar_conta_cliente(lista_clientes *l, cadastro it);

void mostra_comprados(lista_clientes *l,cadastro it);

void mostrar_carrinho(lista_clientes *l, cadastro it);

int excluir_conta_cliente(lista_clientes *l, cadastro it);

int limpa_lista_clientes(lista_clientes *l);

int limpa_compra_carrinho(lista_clientes *l,cadastro it);

lista_clientes *ler_clientes();

int salvar_clientes(lista_clientes *l);


// produtos
typedef struct lista
{
    no_produtos *inicio;
} Lista;

Lista *criar();

void limpar_lista_produtos(Lista *l);
int tamanho_lista_produtos(Lista *l);
void mostrar_produto_aleatorio(Lista *l);

int inserirInicio_produtos(Lista *l, produtos it);

int removerInicio_produtos(Lista *l);

int buscarItemChave(Lista *l,int chave,struct produtos *retorno);
int buscarPosicao(Lista *l,int posicao,int *retorno);
int listaVazia_produtos(Lista *l);

#endif