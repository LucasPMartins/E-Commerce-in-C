#ifndef LISTA_H
#define LISTA_H

typedef struct vendedor {
    int codigo;
    char nome[50];
    float salario;
}Vendedor;

typedef struct lista ListaVendedores;

ListaVendedores* criarLista();
// void f(ListaVendedores* l);

int adicionarVendedor(ListaVendedores* l, struct vendedor it);
void listarVendedores(ListaVendedores* l);
//Implementacao 12/10:

int listaVazia(ListaVendedores* l);
void limpar(ListaVendedores *l);
int removerInicio(ListaVendedores *l);

#endif
