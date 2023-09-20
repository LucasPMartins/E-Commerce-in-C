#include <stdio.h>
#include "Lista.h"
#include "vendedores.c"


int main() {
    struct ListaVendedores* lista = criarLista();

    printf("Cadastro do Vendedor:\n");
    struct Vendedor vendedor;

    printf("Codigo: ");
    scanf("%d", &vendedor.codigo);
    printf("Nome: ");
    scanf("%s", vendedor.nome);
    printf("Salario: ");
    scanf("%f", &vendedor.salario);

    printf("\n");

    if (adicionarVendedor(lista, vendedor)) {
        printf("Cadastrado");
    } else {
        printf("Erro");
    }

    listarVendedores(lista);

    f(lista);

    //Ainda não coloquei para armazenar os vendedores em um arquivo


    return 0;
}
