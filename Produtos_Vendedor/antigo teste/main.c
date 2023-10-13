#include <stdio.h>
//#include "lista_vendedores.h"
#include "aplicacao_vendedores.c"


int main() {
    ListaVendedores* lista = criarLista();
    Vendedor vendedor;
    printf(" --- CADASTRO DO VENDEDOR ---\n");

    printf("Codigo: ");
    scanf("%d", &vendedor.codigo);
    printf("Nome: ");
    scanf("%s", vendedor.nome);
    printf("Salario: ");
    scanf("%f", &vendedor.salario);

    printf("\n"); // oi

    if (adicionarVendedor(lista, vendedor) == 0) {
        printf("Cadastrado");
    } else {
        printf("Erro");
    }
    listarVendedores(lista);

    limpar(lista);

    //Ainda não coloquei para armazenar os vendedores em um arquivo


    return 0;
}
