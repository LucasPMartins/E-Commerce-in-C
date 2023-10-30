#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar teclas do teclado na seleção de opcões
#include "ListaEncad.c"

int main()
{
    int opcao2, opcao3,indice;
    lista_vendedores *l_vendedores = criar_lista_vendedores();
    vendedor v;
    produtos p;

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
            v.total_produtos = 0;
            v.inicio = NULL;
            insere_novo_vendedor(l_vendedores, v);

            printf("Cadastro realizado com sucesso!      Seja Bem vindo!\n");

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
            } while (verifica_vendedor_e_retorna(l_vendedores, &v) != 0);
            
            printf("Nome: %s\n", v.cadastro.nome);
            printf("NomeLoja: %s\n", v.nome_loja);
            printf("Senha: %s\n", v.cadastro.senha);
            printf("%d\n",v.total_produtos);
            printf("\n");

            printf("\nSeja Bem vindo de volta %s!\n\n", v.cadastro.nome);
            
            do
            {
                printf("\n                    -- O QUE DESEJA FAZER? --\n\n");
                printf("                    1- Cadastrar Produto\n");
                printf("                    2- Remover produto\n");
                printf("                    3- Ver produtos\n");
                printf("                    0- SAIR\n");
                printf("                      Digite sua opcao:");
                scanf("%d", &opcao3);
                switch (opcao3)
                {

                case 1:
                    /*  cadastrar produto */
                    p.CATEGORIA = 1;
                    strcpy(p.DESCRICAO, "kaka");
                    strcpy(p.NOME, "kekel");
                    p.NOTA_AVALIACAO = 1;
                    p.QUANT_AVALIACAO = 2;
                    p.QUANTIDADE = 10;
                    p.VALOR = 200.50;
    
                    vendedor_adiciona_produtos(&v, p);
                    
                    printf("Cadastro de produto realizado com sucesso!\n");
                    break;

                case 2:
                    /*       remover produtos           */
                    printf("Qual produto quer remover? por indice [i]");
                    mostra_produtos_vendedor(v);
                    scanf("%d",&indice);
                    removerPosicao_produto_do_vendedor(&v,indice);

                    break;
                case 3:
                    /*       Mostrar produtos           */
                    mostra_produtos_vendedor(v);
                    break;

                default:
                    break;
                }
            } while (opcao3 != 0);

            break;

        default:
            break;
        }
    } while (opcao2 != 0);

    return 0;
}
