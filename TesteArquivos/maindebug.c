#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar teclas do teclado na seleção de opcões
#include "ListaEncad.c"

int main(){
    lista_vendedores *l = lerListaVendedores();
    lista_clientes *l2 = ler_clientes();
    mostra_lista_clientes(l2);
    mostrar_lista_vendedores(l);
    system("pause");
    return 0;
}