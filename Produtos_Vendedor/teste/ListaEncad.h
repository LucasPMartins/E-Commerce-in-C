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

typedef struct vendedor{
    char nomeloja[30];
    cadastro lol;
}vendedor;

typedef struct no_vendedores {
    vendedor valor;
    struct no_vendedores *prox;
    struct no_vendedores *ant;
} no_vendedores;

typedef struct lista_vendedores {
    int total_vendedores;
    no_vendedores *inicio;
} lista_vendedores;




lista_vendedores *criar_lista_vendedores();

int lista_vendedores_vazia(lista_vendedores *l);

int verifica_vendedor(lista_vendedores *l,cadastro it, vendedor v);

int insere_novo_vendedor(lista_vendedores *l,vendedor v);

void mostrar_lista_vendedores(lista_vendedores *l);

#endif