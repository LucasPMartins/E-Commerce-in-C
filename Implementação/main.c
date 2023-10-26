#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // Utilizado para usar tecla esc para voltar
#include "ListaEncad.c"
#define ANSI_COLOR_RED "\x1b[31m"     // Cor: Vermelho
#define ANSI_COLOR_GREEN "\x1b[32m"   // Cor: Verde
#define ANSI_COLOR_YELLOW "\x1b[33m"  // Cor: Amarelo
#define ANSI_COLOR_BLUE "\x1b[34m"    // Cor: Azul
#define ANSI_COLOR_MAGENTA "\x1b[35m" // Cor: Magenta
#define ANSI_COLOR_CYAN "\x1b[36m"    // Cor: Ciano
#define ANSI_COLOR_RESET "\x1b[0m"    // Cor padrao

void print_logo();
void imprimelento(char *p, int N);

int main()
{
    int opcao, opcao2, opcao3, categoria, num, pos, i = 0;
    char tecla, *pesquisa = (char *)malloc(30 * sizeof(char));
    lista_clientes *l = criar_lista_clientes();
    lista_vendedores *l2;
    cliente* it = (cliente*) calloc(1,sizeof(cliente)); // Para zerar os campos, e NULL nos ponteiros
    vendedor* v = (vendedor*) calloc(1,sizeof(vendedor));
    

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
                switch (opcao2)
                {
                case 1: // CADASTRO CLIENTE
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n                    --- Digite seus DADOS ---\n\n");
                        printf("                     Digite seu nome:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it->cadastro.nome, 30, stdin);
                        printf(ANSI_COLOR_RESET);
                        it->cadastro.nome[strcspn(it->cadastro.nome, "\n")] = '\0'; // Remove o \n da string
                        printf("                     Digite sua senha:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it->cadastro.senha, 10, stdin);
                        printf(ANSI_COLOR_RESET);
                        it->cadastro.senha[strcspn(it->cadastro.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de clientes, não será criado um novo cliente
                    } while (verifica_cliente(l, it->cadastro) == 0);
                    // Se sair do loop significa que é um novo usuario com um nome diferente
                    insere_novo_cliente(l, it->cadastro);
                    printf(ANSI_COLOR_YELLOW);
                    printf("\n");
                    printf("                          ");
                    imprimelento("SALVANDO...", 200);
                    printf(ANSI_COLOR_RESET);
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n");
                        printf("                        Bem vindo, ");
                        printf(ANSI_COLOR_YELLOW);
                        printf("%s!\n\n", it->cadastro.nome);
                        printf(ANSI_COLOR_RESET);
                        // lista_produtos *retorno_lista;
                        /*Faz uma funcao que printa 5 produtos diferentes de vendedores diferentes
                        e salva em uma lista de produtos, tem que salvar em uma lista pois se o usuario
                        quiser adcionar no carrinho os produtos inicias temos que saber quais são!*/
                        printf("   Produto 1................................................\n");
                        printf("   Produto 2................................................\n");
                        printf("   Produto 3................................................\n");
                        printf("   Produto 2................................................\n");
                        printf("   Produto 5................................................\n");
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
                                printf("\n\nDigite o nome do Produto:");
                                printf(ANSI_COLOR_YELLOW);
                                setbuf(stdin, NULL);
                                fgets(pesquisa, 30, stdin);
                                printf(ANSI_COLOR_RESET);
                                produtos retorno;
                                /* Faz um função que procura um produto passando por todos os vendedores
                                ex: void search_produto(lista_vendedores *l,char *pesquisa, produtos *retorno){
                                        verifições padroes de lista;
                                        int teste = 0;
                                        no_vendedor *no = l->inicio; // vendedor inicial
                                        while(no != NULL) // procura em todos os vendedores
                                        {
                                            no_produtos *no2 = no->vendedor.inicio;
                                            while(no != NULL) // procura em todos os produtos do vendedor
                                            {
                                                if(strcmp(pesquisa,no2->produto.nome) == 0) // produto pesquisado com nome igual
                                                {
                                                    printf("Nome: %s", no2->produto.NOME);
                                                    printf("        Categoria: %d\t", no2->produto.CATEGORIA);
                                                    printf("        Quantidade de Avaliacoes: %d\t",no2->produto.QUANT_AVALIACAO);
                                                    printf("        Nota de Avalicao: %d\t", no2->produto.NOTA_AVALIACAO);
                                                    printf("        Quantidade: %d\t", no2->produto.QUANTIDADE);
                                                    printf("        Valor: %.2f\t", no2->produto.VALOR);
                                                    printf("        Descricao: %s}\n", no2->produto.DESCRICAO);
                                                    retorno = no2->produto; // retorna um produto
                                                    teste = 1;
                                                    break;
                                                }
                                                no2 = no2->prox;
                                            }
                                            no = no->prox;
                                        }
                                    if(teste == 0)
                                    {
                                        printf("Produto inexistente ou nome errado!\n");
                                    }
                                    return;
                                    }
                                */
                                printf("Adicionar o Produto (%s) ao carrinho?\n", retorno.NOME);
                                printf("Pressione Enter para Adicionar ou Esc para Voltar...\n");
                                while (1)
                                {
                                    if (_kbhit())
                                    {
                                        char tecla = _getch();
                                        if (tecla == 13)
                                        { // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                            insere_novo_carrinho(l, it->cadastro, retorno);
                                            printf(ANSI_COLOR_YELLOW);
                                            imprimelento("Adicionando ao Carrinho...\n", 100);
                                            printf(ANSI_COLOR_RESET);
                                            break;
                                        }
                                        if (tecla == 27)
                                        { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                                            break;
                                        }
                                    }
                                }
                                break;
                            case 2: // por categoria
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
                                // lista_produtos *retorno_lista;
                                /* Faz um função que procura um produto passando por todos os vendedores
                                ex: void search_categoria(lista_vendedores *l,int categoria,lista_produtos *retorno){
                                        verifições padroes de lista;
                                        int teste = 0,j = 0;
                                        no_vendedor *no = l->inicio; // vendedor inicial
                                        while(no != NULL) // procura em todos os vendedores
                                        {
                                            no_produtos *no2 = no->vendedor.inicio;
                                            while(no != NULL) // procura em todos os produtos do vendedor
                                            {
                                                if(categoria == no2->produto.CATEGORIA ) // produto pesquisado com categoria igual
                                                {
                                                    prinft("Produto %d: ",j);
                                                    printf("Nome: %s", no2->produto.NOME);
                                                    printf("        Categoria: %d\t", no2->produto.CATEGORIA);
                                                    printf("        Quantidade de Avaliacoes: %d\t",no2->produto.QUANT_AVALIACAO);
                                                    printf("        Nota de Avalicao: %d\t", no2->produto.NOTA_AVALIACAO);
                                                    printf("        Quantidade: %d\t", no2->produto.QUANTIDADE);
                                                    printf("        Valor: %.2f\t", no2->produto.VALOR);
                                                    printf("        Descricao: %s}\n", no2->produto.DESCRICAO);
                                                    insere_lista_produtos(retorno,no2->produto); //funcao que insere um produto na lista de produtos
                                                    teste = 1;
                                                    j++;
                                                }
                                                no2 = no2->prox;
                                            }
                                            no = no->prox;
                                        }
                                    if(teste == 0)
                                    {
                                        printf("Nenhum produto na categoria! :( \n");
                                    }
                                    return;
                                    }
                                */
                                do
                                {
                                    printf("\n\n");
                                    printf("Digite o numero do produto que deseja adicionar ao carrinho (-1 para voltar):");
                                    setbuf(stdin, NULL);
                                    scanf("%d", &num);
                                    produtos p;
                                    // Função que retorna o produto baseado na posicao digitada ex: produtos *retorna_prod(lista_produtos *l,int pos);
                                    insere_novo_carrinho(l, it->cadastro, p);
                                    printf(ANSI_COLOR_YELLOW);
                                    imprimelento("Adicionando ao Carrinho...\n", 100);
                                    printf(ANSI_COLOR_RESET);
                                } while (num != -1);
                                break;
                            default:
                                break;
                            }
                            break;
                        case 2: // Adicionar no carrinho
                            do
                            {
                                printf("\n\n");
                                printf("Digite o numero do produto que deseja adicionar ao carrinho (-1 para voltar):");
                                setbuf(stdin, NULL);
                                scanf("%d", &num);
                                produtos p;
                                // Função que retorna o produto baseado na posicao digitada ex: produtos *retorna_prod(lista_produtos *l,int pos);
                                insere_novo_carrinho(l, it->cadastro, p);
                                printf("\n\nProduto adicionado no Carrinho com Sucesso!");
                            } while (num != -1);
                            break;
                        case 3: // Ver carrinho
                            do
                            {
                                system("cls");
                                mostrar_carrinho(l, it->cadastro);
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
                                    printf("\n\n---- Pagamento via PIX ----\n\n");
                                    printf("    # ## ## # ### # #\n");
                                    printf("    ### ## # # ##  ##\n");
                                    printf("    ####  ## ## #####\n");
                                    printf("    ### ### # ##### #\n");
                                    printf("    ####  #### ##### \n");
                                    printf("    ### ##  ##### ###\n");
                                    printf("    # # # ##### ### #\n");
                                    printf("    ## ##  #### ## ##\n");
                                    printf("\n\nPressione Enter para finalizar pagamento...\n");
                                    while (1)
                                    {
                                        if (_kbhit())
                                        {
                                            tecla = _getch();
                                            if (tecla == 13)
                                            {          // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                                break; // Retorna ao menu anterior
                                            }
                                        }
                                    }
                                    insere_carrinho_comprados(l, it->cadastro);
                                    limpa_carrinho(l, it->cadastro);
                                }
                                else if (opcao2 == 2)
                                {
                                    printf("\nDigite o numero do produto de deseja remover:");
                                    setbuf(stdin, NULL);
                                    scanf("%d", &num);
                                    remove_do_carrinho(l, it->cadastro, num);
                                    imprimelento("\n\nRemovendo...", 200);
                                }
                                else if (opcao2 == 3)
                                {
                                    limpa_carrinho(l, it->cadastro);
                                    imprimelento("\n\nLimpando...", 200);
                                }
                                else if (opcao2 == 0)
                                {
                                    opcao3 = 10;
                                    break;
                                }
                            } while (opcao2 != 0);
                            break;
                        case 4: // Ver Historico  de  Compras
                            do
                            {
                                system("cls");
                                mostrar_comprados(l, it->cadastro);
                                printf("\n                   -- O QUE DESEJA FAZER? --\n\n");
                                printf("                     1- Avaliar Produto\n");
                                printf("                     0- Voltar\n\n");
                                printf("                      Digite sua opcao:");
                                setbuf(stdin, NULL);
                                scanf("%d", &opcao2);
                                if (opcao2 == 1)
                                {
                                    printf("\nDigite o numero do Produto que deseja Avaliar:");
                                    setbuf(stdin, NULL);
                                    scanf("%d", &pos);
                                    printf("\nDigite sua Avaliacao:");
                                    setbuf(stdin,NULL);
                                    scanf("%d",&num);
                                    avaliar_produto(l,l2, it->cadastro, pos,num);
                                    printf("Obrigado por Avaliar!\n\n");
                                }
                                if (opcao2 == 0)
                                {
                                    opcao3 = 10;
                                    break;
                                }
                            } while (opcao2 != 0);
                            break;
                        case 5: // opcoes de conta
                            system("cls");
                            print_logo();
                            printf("\n\n");
                            mostrar_conta_cliente(l, it->cadastro);
                            printf("Pressione Esc para Voltar...\n");
                            while (1)
                            {
                                if (_kbhit())
                                {
                                    tecla = _getch();
                                    if (tecla == 27)
                                    {          // Verifica se a tecla pressionada é o código ASCII do "Enter"
                                        break; // Retorna ao menu anterior
                                    }
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
                    // SEPARAÇÃO
                case 2:
                    /*            CADASTRO VENDEDOR */
                     do{
                        printf("Digite seu nome:");
                        setbuf(stdin,NULL);
                        fgets(v->cadastro.nome,30,stdin);
                        v->cadastro.nome[strcspn(v->cadastro.nome,"\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin,NULL);
                        fgets(v->cadastro.senha,10,stdin);
                        printf("Digite o nome da loja:");
                        setbuf(stdin,NULL);
                        fgets(v->nome_loja,30,stdin);
                        v->nome_loja[strcspn(v->nome_loja,"\n")] = '\0';
                    // Se o nome já existir na lista de vendedores, não será criado um novo vendedor
                    }while(verifica_vendedor(l2,*v) == 0);

                    // Se sair do loop significa que é um novo usuario com um nome diferente
                    insere_novo_vendedor(l2,*v);

                    printf("Cadastro realizado com sucesso!      Seja Bem vindo!\n");
                    opcao2 = 0; // Volta direto para o menu inicial
    
                    break;
                case 3:       /*       LOGIN COMO CLIENTE           */
                    do
                    {
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        fgets(it->cadastro.nome, 30, stdin);
                        it->cadastro.nome[strcspn(it->cadastro.nome, "\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        fgets(it->cadastro.senha, 10, stdin);
                        it->cadastro.senha[strcspn(it->cadastro.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de clientes sairá do loop, usuario existe
                    } while (verifica_cliente(l, it->cadastro) != 0);
                    printf("\nSeja Bem vindo de volta %s!\n\n", it->cadastro.nome);
                    opcao2 = 0; // Volta direto para o menu inicial
                    break;
                                /*       LOGIN COMO CLIENTE           */
                                

                case 4:
                                 /*       LOGIN COMO VENDEDOR           */
                    do
                    {
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        fgets(v->cadastro.nome,30,stdin);
                        v->cadastro.nome[strcspn(v->cadastro.nome,"\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        fgets(v->cadastro.senha,10,stdin);
                        // Se o nome já existir na lista de vendedores sairá do loop, usuario existe
                    } while (verifica_vendedor(l, *v) != 0);
                    printf("\nSeja Bem vindo de volta %s!\n\n", v->cadastro.nome);
                    opcao2 = 0; // Volta direto para o menu inicial
                    break;
                                    /*       LOGIN COMO VENDEDOR           */
                default:
                    break;
                }
            } while (opcao2 != 0);
            break;
        case 2:
            /* SOBRE */
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
            while (i++ < 3)
            {
                Sleep(500); // Sleep
                printf(".");
            }
            printf("  Volte sempre!\n");
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