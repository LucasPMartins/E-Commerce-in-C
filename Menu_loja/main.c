#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

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



    int opcao,i=0;
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