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

typedef struct cliente
{
    int total_carrinho;
    int total_comprados;
    no_produtos *carrinho_inicio;
    no_produtos *comprados_inicio;
    cadastro cadastro;
} cliente;

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

typedef struct no_clientes
{
    cliente valor;
    struct no_clientes *prox;
    struct no_clientes *ant;
} no_clientes;

typedef struct lista_clientes
{
    int total_clientes;
    no_clientes *inicio;
} lista_clientes;

typedef struct lista_vendedores
{
    int total_vendedores;
    no_vendedores *inicio;
} lista_vendedores;

typedef struct lista_produtos
{
    no_produtos *inicio;
} lista_produtos;

lista_clientes *criar_lista_clientes();
int lista_clientes_vazia(lista_clientes *l);
int verifica_cliente(lista_clientes *l, cadastro it);
int insere_novo_cliente(lista_clientes *l, cadastro it);
int insere_nova_compra(lista_clientes *l, cadastro it, produtos p);
int insere_novo_carrinho(lista_clientes *l, cadastro it, produtos p);
int remove_do_carrinho(lista_clientes *l, cadastro it, int pos);
void mostra_lista_clientes(lista_clientes *l);
int remove_do_comprados(lista_clientes *l, cadastro it, int pos);
void mostrar_carrinho(lista_clientes *l, cadastro it);
void mostrar_conta_cliente(lista_clientes *l, cadastro it);
void mostrar_comprados(lista_clientes *l, cadastro it);
int excluir_conta_cliente(lista_clientes *l, cadastro it);
int limpa_lista_clientes(lista_clientes *l);
int limpa_compra_carrinho(lista_clientes *l, cadastro it);
int salvar_clientes(lista_clientes *l);
lista_clientes *ler_clientes();
int insere_do_carrinho_para_comprados(lista_clientes *l, cadastro it);
int limpa_carrinho(lista_clientes *l, cadastro it);
int avaliar_produto(lista_vendedores *l2, lista_clientes *l, cadastro it, int pos, int num);
no_clientes *buscar_cliente(lista_clientes *l, cadastro it);

//                               TAD PRODUTOS

lista_produtos *criar();

void limpar_lista_produtos(lista_produtos *l);
int tamanho_lista_produtos(lista_produtos *l);
void mostrar_produtos(lista_produtos *l);

int inserirInicio_produtos(lista_produtos *l, produtos it);

int removerInicio_produtos(lista_produtos *l);

int buscarItemChave(lista_produtos *l, int chave, struct produtos *retorno);
int buscarPosicao(lista_produtos *l, int posicao, int *retorno);
int listaVazia_produtos(lista_produtos *l);

int produtos_de_categoria(lista_vendedores *v, int categoria, lista_produtos *p);

int produtos_de_nome(lista_vendedores *v, char *pesquisa, lista_produtos *p);

int retorna_5_produtos(lista_vendedores *v, lista_clientes *l, cadastro it, lista_produtos *p);
//NOVAS
int conta_produtos_total(lista_vendedores* l);
int verifica_produto(lista_produtos*p, produtos it);
int buscar_produto_posicao(lista_produtos*p, produtos* it, int pos);
int produtos_registrados(lista_vendedores *v, lista_produtos *p);

int remover_posicao_produto(lista_produtos *p, int pos);


//                              TAD VENDEDOR

lista_vendedores *criar_lista_vendedores();

int lista_vendedores_vazia(lista_vendedores *l);

int verifica_vendedor(lista_vendedores *l, vendedor v);

int insere_novo_vendedor(lista_vendedores *l, vendedor v);

void mostrar_lista_vendedores(lista_vendedores *l);

int verifica_vendedor_e_retorna(lista_vendedores *l, vendedor *v);

int vendedor_adiciona_produtos(vendedor *v, produtos p);

void mostra_produtos_vendedor(vendedor v);

int removerPosicao_produto_do_vendedor(vendedor *v, int pos);

// NOVAS:
int buscar_por_posicao_vendedor(lista_vendedores* l, int pos, vendedor *v);

int atualiza_lista_vendedores(vendedor v, lista_vendedores *l);

#endif