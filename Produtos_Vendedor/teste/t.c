#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncad.c"
#include "ListaEncad.h"


int main() {
    lista_vendedores *l = criar_lista_vendedores();
    int escolha;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir novo vendedor\n");
        printf("2. Mostrar lista de vendedores\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                {
                    cadastro cad;
                    vendedor vend;

                    setbuf(stdin,NULL);
                    printf("Nome da loja: ");
                    fgets(vend.nomeloja, sizeof(vend.nomeloja), stdin);
                    vend.nomeloja[strlen(vend.nomeloja) - 1] = '\0';

                    printf("Nome do vendedor: ");
                    fgets(cad.nome, sizeof(cad.nome), stdin);
                    cad.nome[strlen(cad.nome) - 1] = '\0';
                    setbuf(stdin,NULL);

                    printf("Senha: ");
                   fgets(cad.senha, sizeof(cad.senha), stdin);
                   cad.senha[strlen(cad.senha) - 1] = '\0';

                    verifica_vendedor(l,cad, vend);
                    int inserido = insere_novo_vendedor(l, vend);

                    if (inserido) {
                        printf("Vendedor inserido\n");
                    } else {
                        printf("Erro ao inserir vendedor\n");
                    }
                }
                break;

            case 2:
                mostrar_lista_vendedores(l);
                break;

            case 3:
                printf("Encerrando\n");
                break;
        }
    } while (escolha != 3);


    libera_lista_vendedores(l);

    return 0;
}

