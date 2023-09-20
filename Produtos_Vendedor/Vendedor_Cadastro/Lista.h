#ifndef LISTA_H
#define LISTA_H

struct Vendedor {
    int codigo;
    char nome[50];
    float salario;
};

struct ListaVendedores;

struct ListaVendedores* criarLista();
void f(struct ListaVendedores* l);
int adicionarVendedor(struct ListaVendedores* l, struct Vendedor vendedor);
void listarVendedores(struct ListaVendedores* l);

#endif
