#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar teclas do teclado na seleção de opcões
#include "ListaEncad.c"

int main()
{
    int opcao2;
    lista_vendedores *l_vendedores = criar_lista_vendedores();
    vendedor v;

    /* CADASTRAR/LOGAR */
    do
    {
        printf("\n                    -- O QUE DESEJA FAZER? --\n\n");
        printf("                    X- Cadastrar como Cliente\n");
        printf("                    2- Cadastrar como Vendedor\n");
        printf("                    X- Login como Cliente\n");
        printf("                    4- Login como Vendedor\n");
        printf("                    0- Voltar\n\n");
        printf("                      Digite sua opcao:");
        scanf("%d", &opcao2);
        switch (opcao2)
        {

        case 2:
            /*            CADASTRO VENDEDOR */
            /*
            do
            {
                printf("Digite seu nome:");
                setbuf(stdin, NULL);
                fgets(v.cadastro.nome, 30, stdin);
                v.cadastro.nome[strcspn(v.cadastro.nome, "\n")] = '\0';
                printf("Digite sua senha:");
                setbuf(stdin, NULL);
                fgets(v.cadastro.senha, 10, stdin);
                printf("Digite o nome da loja:");
                setbuf(stdin, NULL);
                fgets(v.nome_loja, 30, stdin);
                v.nome_loja[strcspn(v.nome_loja, "\n")] = '\0';
                // Se o nome já existir na lista de vendedores, não será criado um novo vendedor
            } while (verifica_vendedor(l_vendedores, v) == 0);
*/
            printf("Digite seu nome:");
            setbuf(stdin, NULL);
            fgets(v.cadastro.nome, 30, stdin);
            printf("Digite sua senha:");
            setbuf(stdin, NULL);
            fgets(v.cadastro.senha, 10, stdin);
            printf("Digite o nome da loja:");
            setbuf(stdin, NULL);
            fgets(v.nome_loja, 30, stdin);
            // Quando vendedor é criado a lista dele aponta pra NULL
            // v->inicio = NULL;
            // Se sair do loop significa que é um novo usuario com um nome diferente
            insere_novo_vendedor(l_vendedores, v);

            printf("Cadastro realizado com sucesso!      Seja Bem vindo!\n");
            opcao2 = 0; // Volta direto para o menu inicial

            break;

        case 4:
            /*       LOGIN COMO VENDEDOR           */
            do
            {
                printf("Digite seu nome:");
                setbuf(stdin, NULL);
                fgets(v.cadastro.nome, 30, stdin);
                v.cadastro.nome[strcspn(v.cadastro.nome, "\n")] = '\0';
                printf("Digite sua senha:");
                setbuf(stdin, NULL);
                fgets(v.cadastro.senha, 10, stdin);
                // Se o nome já existir na lista de vendedores sairá do loop, usuario existe
            } while (verifica_vendedor(l_vendedores, v) != 0);
            printf("\nSeja Bem vindo de volta %s!\n\n", v.cadastro.nome);

            /* FUNÇÕES DO VENDEDOR:
                - CADASTRAR UM PRODUTO
            */
            opcao2 = 0; // Volta direto para o menu inicial
            break;

        default:
            break;
        }
    } while (opcao2 != 0);

    return 0;
}
