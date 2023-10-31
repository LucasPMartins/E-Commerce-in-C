#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar teclas do teclado na seleção de opcões
#include "ListaEncad.c"

#define ANSI_COLOR_RED "\x1b[31m"     // Cor: Vermelho
#define ANSI_COLOR_GREEN "\x1b[32m"   // Cor: Verde
#define ANSI_COLOR_YELLOW "\x1b[33m"  // Cor: Amarelo
#define ANSI_COLOR_BLUE "\x1b[34m"    // Cor: Azul
#define ANSI_COLOR_MAGENTA "\x1b[35m" // Cor: Magenta
#define ANSI_COLOR_CYAN "\x1b[36m"    // Cor: Ciano
#define ANSI_COLOR_RESET "\x1b[0m"    // Cor: Padrão

void print_logo();
void imprimelento(char *p, int N);

int main()
{
    int opcao, opcao2, opcao3, categoria, num, pos, qtd, ret, sair, i = 0, indice;
    char tecla, *pesquisa = (char *)malloc(30 * sizeof(char));
    char *senha = (char *)malloc(30 * sizeof(char));           // Usado para verificar a senha do it.senha
    lista_clientes *l = criar_lista_clientes();                // Lista dos Clientes
    lista_vendedores *l_vendedores = criar_lista_vendedores(); // Lista dos Vendedores
    cadastro it;
    vendedor v;
    produtos p;                                             // Necessario uma função que retorna um produto de uma lista de produtos;
    lista_produtos *retorno_lista = criar_lista_produtos(); // Lista temporaria de produtos para printar
    lista_produtos *retorno_lista2 = criar_lista_produtos();
    // Necessario para salvar os 5 produtos iniciais, se usarmos as op. de pesquisa de produtos perderemos esses 5 pordutos (utilizar outra lista)

    /*    -----      DECLARAÇÕES    ----   */

    do
    {
        system("cls");
        print_logo();
        printf("\nBem-vindo a Powerful Machine - Sua Loja de Eletronicos de Excelencia\n");
        printf("\n                 -- O QUE DESEJA FAZER? --\n\n");
        printf("                     1- Cadastrar/Login \n");
        printf("                     2- Sobre a Loja\n");
        printf("                     0- Sair\n\n");
        printf("                    Digite sua opcao:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            /* CADASTRAR/LOGAR */
            do
            {
                system("cls");
                print_logo();
                printf("\n                    -- O QUE DESEJA FAZER? --\n\n");
                printf("                    1- Cadastrar como Cliente\n");
                printf("                    2- Cadastrar como Vendedor\n");
                printf("                    3- Login como Cliente\n");
                printf("                    4- Login como Vendedor\n");
                printf("                    0- Voltar\n\n");
                printf("                      Digite sua opcao:");
                setbuf(stdin, NULL);
                scanf("%d", &opcao2);
                if (opcao2 == 1 || opcao2 == 3) // Login e Cadastro de Cliente
                {
                    num = 3;
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n                                                                (Tentativas: %d)", num);
                        printf("\n\n                    --- Digite seus DADOS ---\n\n");
                        printf("                     Digite seu nome:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it.nome, 30, stdin);
                        printf(ANSI_COLOR_RESET);
                        it.nome[strcspn(it.nome, "\n")] = '\0'; // Remove o \n da string
                        printf("                     Digite sua senha:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it.senha, 10, stdin);
                        printf(ANSI_COLOR_RESET);
                        it.senha[strcspn(it.senha, "\n")] = '\0';
                        ret = verifica_cliente(l, it);
                        if (ret == 0 && opcao2 == 1)
                        {
                            printf(ANSI_COLOR_RED);
                            printf("\nNome ja Exite, Tente Outro!\n");
                            printf(ANSI_COLOR_RESET);
                            Sleep(1000);
                            num--;
                            if (num == 0)
                            {
                                break;
                            }
                        }
                        if (ret == 3 && opcao2 == 3)
                        {
                            printf(ANSI_COLOR_RED);
                            printf("\nNome de Usuario ou Senha Incorretos!\n");
                            printf(ANSI_COLOR_RESET);
                            Sleep(1000);
                            num--;
                            if (num == 0)
                            {
                                break;
                            }
                        }
                    } while ((opcao2 == 1 && ret == 0) || (opcao2 == 3 && ret == 3));
                    if (num == 0)
                    {
                        opcao = 10;
                        opcao2 = 0;
                        opcao3 = 0;
                        break;
                    }
                    if (opcao2 == 1)
                    {
                        insere_novo_cliente(l, it);
                        printf(ANSI_COLOR_YELLOW);
                        printf("\n");
                        printf("                          ");
                        imprimelento("SALVANDO...", 200);
                        printf(ANSI_COLOR_RESET);
                    }
                    if (opcao2 == 3)
                    {
                        printf(ANSI_COLOR_YELLOW);
                        printf("\n");
                        printf("                       ");
                        imprimelento("CARREGANDO...", 200);
                        printf(ANSI_COLOR_RESET);
                    }
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n");
                        printf("                        Bem vindo, ");
                        printf(ANSI_COLOR_YELLOW);
                        printf("%s!\n\n", it.nome);
                        printf(ANSI_COLOR_RESET);
                        // mostrar_5_produtos(l_vendedores,l, it, retorno_lista);
                        // mostrar_produtos(retorno_lista);
                        printf("\n                    -- O QUE DESEJA FAZER? --\n\n");
                        printf("                   1- Procurar  por  um  Produto\n");
                        printf("                   2- Adicionar Produto ao Carrinho\n");
                        printf("                   3- Ver Carrinho  de  Compras\n");
                        printf("                   4- Ver Historico  de  Compras\n");
                        printf("                   5- Acessar  Opcoes  da  Conta\n");
                        printf("                   0- Voltar  para  o  MENU Inicial\n\n");
                        printf("                       Digite sua opcao:");
                        setbuf(stdin, NULL);
                        scanf("%d", &opcao3);
                        switch (opcao3)
                        {
                        case 1: // procurar produto
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            printf("\n                   -- O QUE DESEJA FAZER? --\n\n");
                            printf("                     1- Procurar por NOME\n");
                            printf("                     2- Procurar por CATEGORIA\n");
                            printf("                     0- Voltar\n\n");
                            printf("                      Digite sua opcao:");
                            setbuf(stdin, NULL);
                            scanf("%d", &opcao2);
                            switch (opcao2)
                            {
                            case 1: // por nome
                                system("cls");
                                print_logo();
                                printf("\n\nDigite o nome do Produto:");
                                printf(ANSI_COLOR_YELLOW);
                                setbuf(stdin, NULL);
                                fgets(pesquisa, 30, stdin);
                                pesquisa[strlen(pesquisa) - 1] = '\0';
                                printf("\nPesquisando por %s ", pesquisa);
                                i = 3;
                                while (i > 0)
                                {
                                    imprimelento("...", 500);
                                    printf("\b\b\b   \b\b\b");
                                    i--;
                                }
                                printf(ANSI_COLOR_RESET);
                                produtos_de_nome(l_vendedores, pesquisa, retorno_lista2);
                                sair = 0;
                                if (listaVazia_produtos(retorno_lista2) != 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        print_logo();
                                        printf("\n\nProdutos encontrados para %s:\n\n", pesquisa);
                                        mostrar_produtos(retorno_lista);
                                        printf("\n\nPressione Enter para Adicionar Produtos ou Esc para Voltar...\n");
                                        while (1)
                                        {

                                            if (_kbhit())
                                            {
                                                tecla = _getch();
                                                if (tecla == 13)
                                                { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                                    do
                                                    {
                                                        printf("Digite o qual Produto deseja Adicionar:");
                                                        printf(ANSI_COLOR_YELLOW);
                                                        setbuf(stdin, NULL);
                                                        scanf("%d", &num);
                                                        printf(ANSI_COLOR_RESET);
                                                        printf("\n");
                                                    } while (num > tamanho_lista_produtos(retorno_lista2) || num < 0);
                                                    do
                                                    {
                                                        printf("Digite a Quantidade:");
                                                        printf(ANSI_COLOR_YELLOW);
                                                        setbuf(stdin, NULL);
                                                        scanf("%d", &qtd);
                                                        printf(ANSI_COLOR_RESET);
                                                        printf("\n");
                                                    } while (qtd < 0);
                                                    insere_novo_carrinho(l, it, p);
                                                    printf(ANSI_COLOR_YELLOW);
                                                    imprimelento("Adicionando ao Carrinho...\n", 100);
                                                    printf(ANSI_COLOR_RESET);
                                                    system("pause");
                                                    break;
                                                }
                                                if (tecla == 27)
                                                { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                                                    sair = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    } while (sair != 1);
                                }
                                else
                                {
                                    printf(ANSI_COLOR_RED);
                                    printf("\nNenhum Produto Encontrado :(\n");
                                    printf(ANSI_COLOR_RESET);
                                    break;
                                }
                                break;
                            case 2: // por categoria
                                system("cls");
                                print_logo();
                                printf("\n");
                                printf("\n                  ---- Escolha um CATEGORIA ----\n\n");
                                printf("1-  Celulares e Telefones      2-  Acessorios para PC       3-  Componentes para PC\n");
                                printf("4-  Perifericos para PC        5-  Software                 6-  Cabos e Hubs USB\n");
                                printf("7-  Monitores e Telas          8-  Pilhas e Carregadores    9-  Acessorios em Geral\n");
                                printf("10- Componentes Eletronicos   11-  Controles Remotos       12-  Outros\n\n");
                                printf("Digite sua opcao:");
                                printf(ANSI_COLOR_YELLOW);
                                setbuf(stdin, NULL);
                                scanf("%d", &categoria);
                                printf(ANSI_COLOR_RESET);
                                // FUNÇÃO QUE RETORNA TODOS OS PRODUTOS DE CATEGORIA X
                                produtos_de_categoria(l_vendedores, categoria, retorno_lista2);
                                mostrar_produtos(retorno_lista2);
                                printf(ANSI_COLOR_YELLOW);
                                printf("\nPesquisando pela Categoria %d ", categoria);
                                i = 3;
                                while (i > 0)
                                {
                                    imprimelento("...", 500);
                                    printf("\b\b\b   \b\b\b");
                                    i--;
                                }
                                printf(ANSI_COLOR_RESET);
                                sair = 0;
                                if (listaVazia_produtos(retorno_lista2) != 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        print_logo();
                                        printf("\n\nProdutos encontrados para Categoria %d:\n\n", categoria);
                                        mostrar_produtos(retorno_lista2);
                                        printf("\n\nPressione Enter para Adicionar Produtos ou Esc para Voltar...\n");
                                        while (1)
                                        {
                                            if (_kbhit())
                                            {
                                                tecla = _getch();
                                                if (tecla == 13)
                                                { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                                    do
                                                    {
                                                        printf("Digite o qual Produto deseja Adicionar:");
                                                        printf(ANSI_COLOR_YELLOW);
                                                        setbuf(stdin, NULL);
                                                        scanf("%d", &num);
                                                        printf(ANSI_COLOR_RESET);
                                                        printf("\n");
                                                    } while (num > tamanho_lista_produtos(retorno_lista2) || num < 0);
                                                    do
                                                    {
                                                        printf("Digite a Quantidade:");
                                                        printf(ANSI_COLOR_YELLOW);
                                                        setbuf(stdin, NULL);
                                                        scanf("%d", &qtd);
                                                        printf(ANSI_COLOR_RESET);
                                                        printf("\n");
                                                    } while (qtd < 0);
                                                    insere_novo_carrinho(l, it, p);
                                                    printf(ANSI_COLOR_YELLOW);
                                                    imprimelento("Adicionando ao Carrinho...\n", 100);
                                                    printf(ANSI_COLOR_RESET);
                                                    system("pause");
                                                    break;
                                                }
                                                if (tecla == 27)
                                                { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                                                    sair = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    } while (sair != 1);
                                }
                                else
                                {
                                    printf(ANSI_COLOR_RED);
                                    printf("\nNenhum Produto Encontrado :(\n");
                                    printf(ANSI_COLOR_RESET);
                                    break;
                                }
                                break;
                            default:
                                break;
                            }
                            break;
                        case 2: // Adicionar no carrinho
                            do
                            {
                                system("cls");
                                print_logo();
                                mostrar_produtos(retorno_lista); // Mostra a lista do 5 produtos iniciais
                                printf("\n\nPressione Enter para Adicionar Produtos ou Esc para Voltar...\n");
                                if (listaVazia_produtos(retorno_lista) != 0)
                                {
                                    while (1)
                                    {
                                        if (_kbhit())
                                        {
                                            tecla = _getch();
                                            if (tecla == 13)
                                            { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                                do
                                                {
                                                    printf("\nDigite o qual Produto deseja Adicionar:");
                                                    printf(ANSI_COLOR_YELLOW);
                                                    setbuf(stdin, NULL);
                                                    scanf("%d", &num);
                                                    printf(ANSI_COLOR_RESET);
                                                    printf("\n");
                                                } while (num > tamanho_lista_produtos(retorno_lista) || num < 0);
                                                do
                                                {
                                                    printf("Digite a Quantidade:");
                                                    printf(ANSI_COLOR_YELLOW);
                                                    setbuf(stdin, NULL);
                                                    scanf("%d", &qtd);
                                                    printf(ANSI_COLOR_RESET);
                                                    printf("\n");
                                                } while (qtd < 0);
                                                insere_novo_carrinho(l, it, p);
                                                printf(ANSI_COLOR_YELLOW);
                                                imprimelento("Adicionando ao Carrinho...\n", 100);
                                                printf(ANSI_COLOR_RESET);
                                                system("pause");
                                                break;
                                            }
                                            if (tecla == 27)
                                            { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                                                sair = 1;
                                                break;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    printf(ANSI_COLOR_RED);
                                    printf("\nNenhum Produto Encontrado :(\n");
                                    printf(ANSI_COLOR_RESET);
                                    break;
                                }
                            } while (sair != 1);
                            break;
                        case 3: // Ver carrinho
                            do
                            {
                                system("cls");
                                print_logo();
                                mostrar_carrinho(l, it);
                                printf("\n                   -- O QUE DESEJA FAZER? --\n\n");
                                printf("                     1- Confirmar Compra\n");
                                printf("                     2- Remover do carrinho\n");
                                printf("                     3- Limpar Carrinho\n");
                                printf("                     0- Voltar\n\n");
                                printf("                      Digite sua opcao:");
                                setbuf(stdin, NULL);
                                scanf("%d", &opcao2);
                                if (opcao2 == 1)
                                {
                                    system("cls");
                                    print_logo();
                                    printf("\n\n                      ---- Pagamento via PIX ----\n\n");
                                    printf("                           # ## ## # ### # #\n");
                                    printf("                           ### ## # # ##  ##\n");
                                    printf("                           ####  ## ## #####\n");
                                    printf("                           ### ### # ##### #\n");
                                    printf("                           ####  #### ##### \n");
                                    printf("                           ### ##  ##### ###\n");
                                    printf("                           # # # ##### ### #\n");
                                    printf("                           ## ##  #### ## ##\n");
                                    printf("\n\nPressione Enter para finalizar pagamento...\n");
                                    while (1)
                                    {
                                        if (_kbhit())
                                        {
                                            tecla = _getch();
                                            if (tecla == 13)
                                            { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                                printf(ANSI_COLOR_YELLOW);
                                                printf("\nConfirmando Pagamento");
                                                i = 3;
                                                while (i > 0)
                                                {
                                                    imprimelento("...", 500);
                                                    printf("\b\b\b   \b\b\b");
                                                    i--;
                                                }
                                                printf("\n\nPagamento Realizado com Sucesso! Obrigado por Comprar :)\n\n");
                                                printf(ANSI_COLOR_RESET);
                                                system("pause");
                                                break;
                                                // Retorna ao menu anterior
                                            }
                                        }
                                    }
                                    insere_do_carrinho_para_comprados(l, it);
                                }
                                else if (opcao2 == 2)
                                {
                                    printf("\nDigite o Numero do Produto de deseja Remover:");
                                    setbuf(stdin, NULL);
                                    printf(ANSI_COLOR_YELLOW);
                                    scanf("%d", &num);
                                    ret = remove_do_carrinho(l, it, num);
                                    imprimelento("\nRemovendo", 100);
                                    i = 3;
                                    while (i > 0)
                                    {
                                        imprimelento("...", 500);
                                        printf("\b\b\b   \b\b\b");
                                        i--;
                                    }
                                    if (ret == 0)
                                        printf("\n\nRemovido com Sucesso!\n\n");
                                    else
                                        printf("\n\nErro! :(\n\n");
                                    printf(ANSI_COLOR_RESET);
                                    system("pause");
                                }
                                else if (opcao2 == 3)
                                {
                                    ret = limpa_carrinho(l, it);
                                    printf(ANSI_COLOR_YELLOW);
                                    printf("\nLimpando carrinho");
                                    i = 3;
                                    while (i > 0)
                                    {
                                        imprimelento("...", 500);
                                        printf("\b\b\b   \b\b\b");
                                        i--;
                                    }
                                    if (ret == 0)
                                        printf("Todos os Produtos Removidos com Sucesso!\n\n");
                                    else
                                        printf("\n\nErro! :(\n\n");
                                    printf(ANSI_COLOR_RESET);
                                    system("pause");
                                }
                                else if (opcao2 == 0)
                                {
                                    opcao3 = 10;
                                    break;
                                }
                            } while (opcao2 != 0);
                            break;
                        case 4: // Ver Historico  de  Compras
                            sair = 0;
                            do
                            {
                                system("cls");
                                print_logo();
                                mostrar_comprados(l, it);
                                printf("\nPressione Enter para Avaliar Produtos ou Esc para Voltar...\n");
                                while (1)
                                {
                                    if (_kbhit())
                                    {
                                        tecla = _getch();
                                        if (tecla == 13)
                                        { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                            do
                                            {
                                                printf("\nDigite Numero do Produto que deseja Avaliar:");
                                                setbuf(stdin, NULL);
                                                printf(ANSI_COLOR_YELLOW);
                                                scanf("%d", &pos);
                                                printf(ANSI_COLOR_RESET);
                                                printf("\nDigite sua Avaliacao:");
                                                setbuf(stdin, NULL);
                                                printf(ANSI_COLOR_YELLOW);
                                                scanf("%d", &num);
                                                printf(ANSI_COLOR_RESET);
                                            } while (pos < 0);
                                            avaliar_produto(l_vendedores, l, it, pos, num);
                                            printf(ANSI_COLOR_YELLOW);
                                            printf("\nObrigado por Avaliar!\n\n");
                                            printf(ANSI_COLOR_RESET);
                                            system("pause");
                                            break;
                                        }
                                        if (tecla == 27)
                                        { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                                            sair = 1;
                                            break;
                                        }
                                    }
                                }
                            } while (sair != 1);
                            break;
                        case 5: // opcoes de conta
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            mostrar_conta_cliente(l, it);
                            printf("Pressione Backspace para Deletar a Conta ou Esc para Voltar...\n");
                            while (1)
                            {
                                if (_kbhit())
                                {
                                    tecla = _getch();
                                    if (tecla == 27)
                                    {
                                        break; // Retorna ao menu anterior
                                    }
                                    if (tecla == 8)
                                    { // Verifica se a tecla pressionada é o código ASCII do "Backspace"
                                        printf(ANSI_COLOR_RED);
                                        printf("\nTem certeza que deseja excluir a sua conta?\n\n");
                                        printf(ANSI_COLOR_RESET);
                                        printf("Pressione Enter para Continuar ou Esc para Voltar...\n");
                                        while (1)
                                        {
                                            if (_kbhit())
                                            {
                                                tecla = _getch();
                                                if (tecla == 13)
                                                {
                                                    do
                                                    {
                                                        printf("\nDigite sua senha:");
                                                        setbuf(stdin, NULL);
                                                        printf(ANSI_COLOR_YELLOW);
                                                        fgets(senha, 30, stdin);
                                                        printf(ANSI_COLOR_RESET);
                                                        senha[strcspn(senha, "\n")] = '\0';
                                                    } while (strcmp(it.senha, senha) != 0);
                                                    printf(ANSI_COLOR_YELLOW);
                                                    printf("\nExcluindo conta");
                                                    i = 3;
                                                    while (i > 0)
                                                    {
                                                        imprimelento("...", 500);
                                                        printf("\b\b\b   \b\b\b");
                                                        i--;
                                                    }
                                                    ret = excluir_conta_cliente(l, it);
                                                    if (ret == 0)
                                                        printf("\n\nConta excluida com sucesso! :( \n\n");
                                                    else
                                                        printf("\n\nErro! :(\n\n");
                                                    printf(ANSI_COLOR_RESET);
                                                    system("pause");
                                                    opcao3 = 0;
                                                    opcao2 = 0;
                                                    opcao = 10;
                                                    break; // Retorna ao menu anterior
                                                }
                                                if (tecla == 27)
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        case 0:
                            opcao3 = 0;
                            opcao2 = 0;
                            opcao = 10;
                            break;
                        default:
                            break;
                        }
                    } while (opcao3 != 0);
                    break;
                }
                if (opcao2 == 2 || opcao2 == 4) // Login e Cadastro de Vendedor
                {
                    /*            CADASTRO/LOGIN VENDEDOR */
                    num = 3;
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n                                                                (Tentativas: %d)", num);
                        printf("\n\n                    --- Digite seus DADOS ---\n\n");
                        printf("                     Digite seu nome:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        // fgets(it.nome, 30, stdin);
                        fgets(v.cadastro.nome, 30, stdin);
                        printf(ANSI_COLOR_RESET);
                        v.cadastro.nome[strcspn(v.cadastro.nome, "\n")] = '\0';
                        printf("                     Digite sua senha:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(v.cadastro.senha, 10, stdin);
                        if (opcao2 == 2)
                        {
                            printf(ANSI_COLOR_RESET);
                            printf("                     Digite o nome da loja:");
                            setbuf(stdin, NULL);
                            fgets(v.nome_loja, 30, stdin);
                            v.nome_loja[strcspn(v.nome_loja, "\n")] = '\0';
                        }
                        ret = verifica_vendedor(l_vendedores, v);
                        if (ret == 0 && opcao2 == 2)
                        {
                            printf(ANSI_COLOR_RED);
                            printf("\nNome ja Existe, Tente Outro!\n");
                            printf(ANSI_COLOR_RESET);
                            Sleep(1000);
                            num--;
                            if (num == 0)
                            {
                                break;
                            }
                        }
                        if (ret == 3 && opcao2 == 4)
                        {
                            
                            printf(ANSI_COLOR_RED);
                            printf("\nNome ou Senha Incorretos!\n");
                            printf(ANSI_COLOR_RESET);
                            Sleep(1000);
                            num--;
                            if (num == 0)
                            {
                                break;
                            }
                        }
                        
                    } while ((opcao2 == 2 && ret == 0) || (opcao2 == 4 && ret == 3));
                    if(ret == 0 && opcao2 == 4){
                        verifica_vendedor_e_retorna(l_vendedores,&v);
                    }
                            
                    if (num == 0)
                    {
                        opcao = 10;
                        opcao2 = 0;
                        opcao3 = 0;
                        break;
                    }
                    if (opcao2 == 2)
                    {
                        // cadastro
                        v.total_produtos = 0;
                        v.inicio = NULL;
                        insere_novo_vendedor(l_vendedores, v);
                        printf(ANSI_COLOR_YELLOW);
                        printf("\n");
                        printf("                          ");
                        imprimelento("SALVANDO...", 200);
                        printf(ANSI_COLOR_RESET);
                    }
                    if (opcao2 == 4)
                    {
                        // Login
                        printf(ANSI_COLOR_YELLOW);
                        printf("\n");
                        printf("                       ");
                        imprimelento("CARREGANDO...", 200);
                        printf(ANSI_COLOR_RESET);
                    }
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n");
                        printf("                        Bem vindo, ");
                        printf(ANSI_COLOR_YELLOW);
                        printf("%s!\n\n", v.cadastro.nome);
                        printf(ANSI_COLOR_RESET);
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
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            printf("Insira o Nome do Produto:");
                            setbuf(stdin, NULL);
                            fgets(p.NOME, 30, stdin);
                            p.NOME[strcspn(p.NOME, "\n")] = '\0';
                            printf("Insira a Categoria do Produto:");
                            setbuf(stdin, NULL);
                            scanf("%d", &p.CATEGORIA);
                            printf("Insira a Descricao do Produto:");
                            setbuf(stdin, NULL);
                            fgets(p.DESCRICAO, 100, stdin);
                            p.DESCRICAO[strcspn(p.DESCRICAO, "\n")] = '\0';
                            printf("Insira a Quantidade do Produto:");
                            setbuf(stdin, NULL);
                            scanf("%d", &p.QUANTIDADE);
                            printf("Insira o Valor do Produto:\n");
                            setbuf(stdin, NULL);
                            scanf("%f", &p.VALOR);
                            p.NOTA_AVALIACAO = 0;
                            p.QUANT_AVALIACAO = 0;
                            strcpy(p.nome_loja, v.nome_loja);
                            if (vendedor_adiciona_produtos(&v, p) == 0)
                                printf("Cadastro de Produto Realizado com Sucesso!\n");
                            else
                                printf("Cadastro de Produto Falhou!\n");
                            atualiza_lista_vendedores(v, l_vendedores);
                            break;
                        case 2:
                            /*       remover produtos           */
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            mostra_produtos_vendedor(v);
                            printf("Qual Produto deseja Remover? por Indice [i]\n");
                            printf(ANSI_COLOR_RED);
                            printf("Remover Produto:");
                            printf(ANSI_COLOR_RESET);
                            scanf("%d", &indice);
                            if (removerPosicao_produto_do_vendedor(&v, indice) == 0)
                            {
                                printf(ANSI_COLOR_YELLOW);
                                printf("\n");
                                printf("                       ");
                                imprimelento("Removendo", 200);
                                i = 3;
                                while (i > 0)
                                {
                                    imprimelento("...", 500);
                                    printf("\b\b\b   \b\b\b");
                                    i--;
                                }
                                printf(ANSI_COLOR_RESET);
                            }
                            else
                            {
                                printf(ANSI_COLOR_RED);
                                printf("\nNao foi Possivel Remover Produto!\n");
                                printf(ANSI_COLOR_RESET);
                            }
                            atualiza_lista_vendedores(v, l_vendedores);
                            break;
                        case 3:
                            /*       Mostrar produtos           */
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            mostra_produtos_vendedor(v);
                            system("pause");
                            break;

                        default:
                            break;
                        }

                    } while (opcao3 != 0);
                }
            } while (opcao2 != 0);
            break;
        case 2:
            system("cls");
            printf("\n");
            printf("=========================================================================\n");
            printf(ANSI_COLOR_YELLOW);
            printf("\nO que voce pode esperar da Powerful Machine:\n\n");
            printf("Variedade Inigualavel: ");
            printf(ANSI_COLOR_RESET);
            printf("Oferecemos uma ampla gama de produtos eletronicos,\n");
            printf("desde smartphones  e laptops ate  dispositivos  inteligentes para  casa e\n");
            printf("acessorios  de  ultima  geracao. Seja  qual  for a sua  necessidade, voce\n");
            printf("encontrara  a  solucao  perfeita  em  nossa  loja.\n\n");
            printf(ANSI_COLOR_YELLOW);
            printf("Qualidade  Garantida:");
            printf(ANSI_COLOR_RESET);
            printf(" Na  Powerful Machine, qualidade eh  a nossa priori-\n");
            printf("dade. Trabalhamos  com  as  principais   marcas  do  mercado  e  produtos\n");
            printf("de  alta  qualidade  para  garantir  a  satisfacao  de  nossos  clientes.\n\n");
            printf(ANSI_COLOR_YELLOW);
            printf("Atendimento  Personalizado:");
            printf(ANSI_COLOR_RESET);
            printf(" Nossa  equipe esta  sempre  pronta  para aju-\n");
            printf("da-lo  a encontrar  o  produto  certo  que  atenda as  suas  necessidades\n");
            printf("e orcamento, orientacao e suporte para  tornar sua experiencia  de compra\n");
            printf("mais facil e agradavel.\n\n");
            printf(ANSI_COLOR_YELLOW);
            printf("Precos Competitivos:");
            printf(ANSI_COLOR_RESET);
            printf(" Com  precos competitivos e ofertas especiais, garan-\n");
            printf("timos que  voce obtenha o melhor custo-beneficio em sua compra de eletro-\n");
            printf("nicos na Powerful Machine.\n\n");
            printf(ANSI_COLOR_YELLOW);
            printf("Conveniencia Online:");
            printf(ANSI_COLOR_RESET);
            printf(" Alem de nossa loja fisica, oferecemos uma plataforma\n");
            printf("de compras  online conveniente, permitindo que voce compre  seus  eletro-\n");
            printf("nicos favoritos no conforto de sua casa.\n\n");
            printf(ANSI_COLOR_YELLOW);
            printf("Assistencia Tecnica Especializada:");
            printf(ANSI_COLOR_RESET);
            printf(" Alem  das vendas, oferecemos  servicos\n");
            printf("de assistencia tecnica de primeira linha para garantir que seus disposi-\n");
            printf("tivos funcionem perfeitamente.\n\n");
            printf("=========================================================================\n");
            // Pressione Esc para voltar
            printf("Pressione Esc para voltar ao menu anterior...\n");
            while (1)
            {
                if (_kbhit())
                {
                    tecla = _getch();
                    if (tecla == 27)
                    {          // Verifica se a tecla pressionada é o código ASCII do "Esc"
                        break; // Retorna ao menu anterior
                    }
                }
            }
            break;
        case 0:
            /* SAIR */
            system("cls");
            printf(ANSI_COLOR_YELLOW);
            printf("Saindo");
            i = 3;
            while (i > 0)
            {
                i--;
                imprimelento("...", 500);
                printf("\b\b\b   \b\b\b");
            }
            system("cls");
            printf(ANSI_COLOR_RED);
            printf("                        ___\n");
            printf("                    __,' __`.                _..----....____\n");
            printf("        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'\n");
            printf("  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'\n");
            printf(",'________________                          \\`-._`-','\n");
            printf(" `._              ```````````------...___   '-.._'-:\n");
            printf("    ```--.._      ,.                     ````--...__\\-.\n");
            printf("            `.--. `-`                       ____    |  |`\n");
            printf("              `. `.                       ,'`````.  ;  ;`\n");
            printf("                `._`.        __________   `.      \'__/`\n");
            printf("                   `-:._____/______/___/____`.     \\  `\n");
            printf("                               |       `._    `.    \\\n");
            printf("                               `._________`-.   `.   `.___\n");
            printf("                                                  `------'`\n");
            printf("\n\nVolte sempre!");
            system("pause");
            printf(ANSI_COLOR_RESET);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void print_logo()
{
    printf(ANSI_COLOR_RED);
    printf("             ____                         __       _ \n");
    printf("            |  _ \\ _____      _____ _ __ / _|_   _| |\n");
    printf("            | |_) / _ \\ \\ /\\ / / _ \\ '__| |_| | | | |\n");
    printf("            |  __/ (_) \\ V  V /  __/ |  |  _| |_| | |\n");
    printf("            |_|  _\\___/ \\_/\\_/ \\___|_|  |_|  \\__,_|_|\n");
    printf("              |  \\/  | __ _  ___| |__ (_)_ __   ___    \n");
    printf("              | |\\/| |/ _` |/ __| '_ \\| | '_ \\ / _ \\   \n");
    printf("              | |  | | (_| | (__| | | | | | | |  __/   \n");
    printf("              |_|  |_|\\__,_|\\___|_| |_|_|_| |_|\\___|   \n");
    printf(ANSI_COLOR_RESET);
}

void imprimelento(char *p, int N)
{
    int i;
    for (i = 0; *(p + i) != '\0'; i++)
    {
        printf("%c", *(p + i));
        fflush(stdout);
        Sleep(N);
    }
}
