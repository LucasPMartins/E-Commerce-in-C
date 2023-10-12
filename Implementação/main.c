#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "ListaEncad.h"

int main()
{
    printf("\n\tBem vindo a powerful machine!\n");

    printf("____                         __       _ \n");
    printf("|  _ \\ _____      _____ _ __ / _|_   _| |\n");
    printf("| |_) / _ \\ \\ /\\ / / _ \\ '__| |_| | | | |\n");
    printf("|  __/ (_) \\ V  V /  __/ |  |  _| |_| | |\n");
    printf("|_|  _\\___/ \\_/\\_/ \\___|_|  |_|  \\__,_|_|\n");
    printf("|  \\/  | __ _  ___| |__ (_)_ __   ___    \n");
    printf("| |\\/| |/ _` |/ __| '_ \\| | '_ \\ / _ \\   \n");
    printf("| |  | | (_| | (__| | | | | | | |  __/   \n");
    printf("|_|  |_|\\__,_|\\___|_| |_|_|_| |_|\\___|   \n");

    int opcao, i = 0, opcao2;
    cadastro it;
    lista_clientes *l = ler_clientes(); // A função le um arquivo e retorna uma lista de clientes
    do
    {
        printf("\n-- O QUE DESEJA FAZER? --\n");
        printf("1- Cadastrar/Login \n");
        printf("2- Pesquisar produtos\n");
        printf("3- Sobre a loja\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            /* CADASTRAR/LOGAR */
            do
            {
                printf("\n\n");
                printf("1- Cadastrar como Cliente\n");
                printf("2- Cadastrar como Vendedor\n");
                printf("3- Login como Cliente\n");
                printf("4- Login como Vendedor\n");
                printf("0- Voltar\n");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                case 1:
                    do
                    {
                        printf("Digite seu nome:");
                        setbuf(stdin, NULL);
                        fgets(it.nome, 30, stdin);
                        it.nome[strcspn(it.nome, "\n")] = '\0'; // Remove o \n da string
                        printf("Digite sua senha:");
                        setbuf(stdin, NULL);
                        fgets(it.senha, 10, stdin);
                        it.senha[strcspn(it.senha, "\n")] = '\0';
                        // Se o nome já existir na lista de clientes, não será criado um novo cliente
                    } while (verifica_cliente(l, it) == 0);
                    // Se sair do loop significa que é um novo usuario com um nome diferente
                    insere_novo_cliente(l, it);
                    printf("\nCadastro realizado com sucesso!      Seja Bem vindo!\n\n");
                    opcao2 = 0; // Volta direto para o menu inicial
                    break;
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
            /* PESQUISAR */

            break;
        case 3:
            /* SOBRE A LOJA*/

            break;
        case 0:
            /* SAIR */
            printf("Saindo ");
            while (i++ < 3)
            {
                Sleep(200); // Sleep
                printf(".");
            }
            break;
        default:
            printf("-- Erro --\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}