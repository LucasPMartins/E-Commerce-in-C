typedef struct produto{
    int categoria;
    char nome[30];
    float preco;
    int qtd_estoque;
    int avaliacao;
    char descricao[100];
}Produto;
// redundante esse typedef?? lista
typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

int inserirInicio(Lista *l,struct produto it);
int inserirFim(Lista *l,struct produto it);
int inserirPosicao(Lista *l,struct produto it,int pos);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,int it);

int buscarItemChave(Lista *l,int chave,struct produto *retorno);
int buscarPosicao(Lista *l,int posicao,int *retorno);
int listaVazia(Lista *l);
int listaCheia(Lista *l);



/* O produto tem todas as operações basicas de lista*/