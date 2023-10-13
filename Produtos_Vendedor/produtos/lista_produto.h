
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


/* O produto tem todas as operações basicas de lista*/