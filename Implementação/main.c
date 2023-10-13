#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "ListaEncad.c"
#define ANSI_COLOR_RED "\x1b[31m"     // Cor: Vermelho
#define ANSI_COLOR_GREEN "\x1b[32m"   // Cor: Verde
#define ANSI_COLOR_YELLOW "\x1b[33m"  // Cor: Amarelo
#define ANSI_COLOR_BLUE "\x1b[34m"    // Cor: Azul
#define ANSI_COLOR_MAGENTA "\x1b[35m" // Cor: Magenta
#define ANSI_COLOR_CYAN "\x1b[36m"    // Cor: Ciano
#define ANSI_COLOR_RESET "\x1b[0m"    // Cor padrao

void print_logo();
void imprimelento(char *p,int N);

int main()
{
    int opcao, opcao2, opcao3,i = 0;
    char tecla;
    cadastro it;
    lista_clientes *l = criar_lista_clientes(); // A função le um arquivo e retorna uma lista de clientes
    do
    {
        system("cls");
        print_logo();
        printf("\n\tBem-vindo a Powerful Machine - Sua Loja de Eletronicos de Excelencia\n");
        printf("\n-- O QUE DESEJA FAZER? --\n");
        printf("   1- Cadastrar/Login \n");
        printf("   2- Sobre a loja\n");
        printf("   0- Sair\n\n");
        printf("Digite sua opcao:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            /* CADASTRAR/LOGAR */
            do
            {
                system("cls");
                print_logo();
                printf("\n-- O QUE DESEJA FAZER? --\n");
                printf("  1- Cadastrar como Cliente\n");
                printf("  2- Cadastrar como Vendedor\n");
                printf("  3- Login como Cliente\n");
                printf("  4- Login como Vendedor\n");
                printf("  0- Voltar\n\n");
                printf("Digite sua opcao:");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                case 1:
                    do
                    {
                        system("cls");
                        print_logo();
                        printf("\n\n--- Digite seus DADOS ---\n\n");
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it.nome, 30, stdin);
                        printf(ANSI_COLOR_RESET);
                        it.nome[strcspn(it.nome, "\n")] = '\0'; // Remove o \n da string
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        printf(ANSI_COLOR_YELLOW);
                        fgets(it.senha, 10, stdin);
                        printf(ANSI_COLOR_RESET);
                        it.senha[strcspn(it.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de clientes, não será criado um novo cliente
                    } while (verifica_cliente(l, it) == 0);
                    // Se sair do loop significa que é um novo usuario com um nome diferente
                    insere_novo_cliente(l, it);
                    printf(ANSI_COLOR_YELLOW);
                    printf("\n");
                    imprimelento("SALVANDO...",300);
                    printf(ANSI_COLOR_RESET);
                    do{
                        
                    }while(opcao3 != 0);
                case 2:
                    /*            O mesmo sistema para os vendedores... implementes suas funções aqui Jamal
                     do{
                        printf("Digite seu nome:");
                        setbuf(stdin,NULL);
                        fgets(it.nome,30,stdin);
                        it.nome[strcspn(it.nome,"\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin,NULL);
                        fgets(it.senha,10,stdin);
                        it.senha[strcspn(it.senha,"\n")] = '\0';
                    // Se o nome já existir na lista de vendedores, não será criado um novo vendedor
                    }while(verifica_vendedor(l2,it) == 0);
                    // Se sair do loop significa que é um novo usuario com um nome diferente
                    insere_novo_vendedor(l2,it);
                    printf("Cadastro realizado com sucesso!      Seja Bem vindo!\n");
                    opcao2 = 0; // Volta direto para o menu inicial
                    */
                    break;
                case 3:
                    do
                    {
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        fgets(it.nome, 30, stdin);
                        it.nome[strcspn(it.nome, "\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        fgets(it.senha, 10, stdin);
                        it.senha[strcspn(it.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de clientes sairá do loop, usuario existe
                    } while (verifica_cliente(l, it) != 0);
                    printf("\nSeja Bem vindo de volta %s!\n\n", it.nome);
                    opcao2 = 0; // Volta direto para o menu inicial
                    break;
                case 4:
                    /*              O mesmo sistema para os vendedores... implementes suas funções aqui Jamal
                    do
                    {
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        fgets(it.nome, 30, stdin);
                        it.nome[strcspn(it.nome, "\n")] = '\0';
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        fgets(it.senha, 10, stdin);
                        it.senha[strcspn(it.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de vendedores sairá do loop, usuario existe
                    } while (verifica_vendedor(l, it) != 0);
                    printf("\nSeja Bem vindo de volta %s!\n\n", it.nome);
                    opcao2 = 0; // Volta direto para o menu inicial
                    */
                    break;
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
                    { // Verifica se a tecla pressionada é o código ASCII do "Esc"
                        system("cls");
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
            system("cls");
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

void imprimelento(char *p,int N){
    int i;
    for(i = 0;*(p+i)!='\0';i++){
        printf("%c",*(p+i));
        fflush(stdout);
        Sleep(N);
    }
}