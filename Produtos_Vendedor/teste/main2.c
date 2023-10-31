#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar teclas do teclado na seleção de opcões
#include "ListaEncad.c"

int main()
{
    int opcao2, opcao3, indice,categoria;
    char pesquisa[30];
    lista_vendedores *l_vendedores = criar_lista_vendedores();
    vendedor v;
    produtos p;
    lista_produtos *retorno_lista = criar_lista_produtos();

    /* CADASTRAR/LOGAR */
    do
    {
        printf("\n                    -- O QUE DESEJA FAZER? --\n\n");
        printf("                    X- Cadastrar como Cliente\n");
        printf("                    2- Cadastrar como Vendedor\n");
        printf("                    X- Login como Cliente\n");
        printf("                    4- Login como Vendedor\n");
        printf("                    0- Voltar\n\n");
        printf("                   99- Produtos categoria\n\n");
        printf("                   100- Produtos nome\n\n");

        printf("                      Digite sua opcao:");
        scanf("%d", &opcao2);
        switch (opcao2)
        {   
            case 99:
            printf("Categoria");
            scanf("%d",&categoria);
            produtos_de_categoria(l_vendedores,categoria,retorno_lista);
            mostrar_produtos(retorno_lista);
            zerar_produtos(retorno_lista);
            //entra no menu de compra olhando pra essa lista
            // buscar produtos na lista de produtos, vai em lista vendedores, pelo nome_loja do produto, achar o produto pelo nome,altera a qtd,se qtd = 0 remove
            // p = produtos *busca_produto(lista_vendedores *l,lista_produtos*p,int indice,int qtd)
            /*
                - Por indice, o cliente escolhe o produto na retorno_lista, pega o produto, nome_loja, vai em l_vendedores
                e procura o nome_loja, quando achar, ver a qtd do cara e chama REDUZIR_QUANTIDADE_PRODUTO_VENDEDOR, se qtd = 0 elimina
                se qtd_do_cliente >= qtd_produtos , else: qtd_produtos - qtd_cliente;  o cliente compra o qtd_produtos; e remove o produto do vendedor, e retorna
                um produto que vai ser utilizado pra colocar no carrinho. com uma nova qtd p.quantidade(qtd);
                
        
            */
            break;

            case 100:
            setbuf(stdin,NULL);
            fgets(pesquisa,30,stdin);
            pesquisa[strlen(pesquisa)-1] = '\0';
            produtos_de_nome(l_vendedores,pesquisa, retorno_lista);
            mostrar_produtos(retorno_lista);
            zerar_produtos(retorno_lista);
            break;

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
                // Verificar o nome_loja tambem!!
                if (verifica_vendedor(l_vendedores, v) == 0)
                {
                    // printf(ANSI_COLOR_RED);
                    printf("\nNome ja Existe, Tente Outro!\n");
                    /*printf(ANSI_COLOR_RESET);
                    Sleep(1000);
                    num--;
                    if (num == 0)
                    {
                        opcao = 10;
                        opcao2 = 0;
                        opcao3 = 0;
                        break;
                    }*/
                }

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
                if (verifica_vendedor_e_retorna(l_vendedores, &v) != 0)
                {
                    printf("Login incorreto\n");
                }
            } while (verifica_vendedor_e_retorna(l_vendedores, &v) != 0);
            printf("===============\n");
            mostrar_lista_vendedores(l_vendedores);
            printf("===============\n");

            printf("-----------\n");
            printf("Nome: %s\n", v.cadastro.nome);
            printf("NomeLoja: %s\n", v.nome_loja);
            printf("Senha: %s\n", v.cadastro.senha);
            printf("TOTAL PRODUTO [%d]\n", v.total_produtos);
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
                    printf("==========\n");
                    mostrar_lista_vendedores(l_vendedores);
                    printf("==========\n");
                    printf("Insira categoria:\n");
                    scanf("%d", &p.CATEGORIA);
                    printf("Insira descricao:\n");
                    setbuf(stdin, NULL);
                    fgets(p.DESCRICAO, 100, stdin);
                    printf("Insira nome do produto:\n");
                    setbuf(stdin, NULL);
                    fgets(p.NOME, 30, stdin);
                    p.NOME[strlen(p.NOME)-1] = '\0';
                    printf("INsira quantidade:\n");
                    scanf("%d", &p.QUANTIDADE);
                    printf("INsira Valor:\n");
                    scanf("%f", &p.VALOR);
                    p.NOTA_AVALIACAO = 0;
                    p.QUANT_AVALIACAO = 0;
                    strcpy(p.nome_loja, v.nome_loja);
                    if (vendedor_adiciona_produtos(&v, p) == 0)
                        printf("Cadastro de produto realizado com sucesso!\n");
                    else
                        printf("Cadastro de produto falhou!\n");
                    atualiza_lista_vendedores(v, l_vendedores);
                    break;

                case 2:
                    /*       remover produtos           */
                    printf("Qual produto quer remover? por indice [i]");
                    mostra_produtos_vendedor(v);
                    scanf("%d", &indice);
                    if (removerPosicao_produto_do_vendedor(&v, indice) == 0)
                        printf("Remocao concluida!\n");
                    else
                        printf("Remocao falha\n");
                    atualiza_lista_vendedores(v, l_vendedores);
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
