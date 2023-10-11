#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncad.h"

int main(){
    cadastro it;
    lista_clientes *l = ler_clientes();

    mostra_lista_clientes(l);

    return 0;
}
