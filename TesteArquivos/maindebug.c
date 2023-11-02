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

void print_logo()
{
    printf(ANSI_COLOR_RED);
    printf("+-------===========================+++++++++++===========================-------+\n");
    printf("|   * .  ^           ____    .       *      .     __       _         *      .   |\n");
    printf("|       / \\     *   |  _ \\ _____  .   _____ _ __ / _|_   _| |              *    |\n");
    printf("|      /___\\        | |_) / _ \\ \\ /\\ / / _ \\ '__| |_| | | | |    .       .      |\n");
    printf("|  *  |=   =|  *    |  __/ (_) \\ V  V /  __/ |  |  _| |_| | |                   |\n");
    printf("|     |     |     . |_|  _\\___/ \\_/\\_/ \\___|_|  |_|  \\__,_|_|        *          |\n");
    printf("|     |     |       |  \\/  | __ _  ___| |__ (_)_ __   ___               *       |\n");
    printf("|     |##!##|   *   | |\\/| |/ _` |/ __| '_ \\| | '_ \\ / _ \\     *          *     |\n");
    printf("|    /|##!##|\\      | |  | | (_| | (__| | | | | | | |  __/               .      |\n");
    printf("|   / |##!##| \\     |_|  |_|\\__,_|\\___|_| |_|_|_| |_|\\___|      *               |\n|");
    printf("   |/^  |  ^\\|         *                      .                            *   |\n");
    printf("+-------===========================+++++++++++===========================-------+\n");
    printf(ANSI_COLOR_RESET);
}

int main()
{
    int opcao;
    system("cls");
    print_logo();
    printf("\n");
    printf("                                BEM VINDO, ");
    printf(ANSI_COLOR_YELLOW);
    printf("%d!\n\n",opcao);
    printf("                            -- O QUE DESEJA FAZER? --\n\n");
    printf(ANSI_COLOR_RESET);
    printf("                               1- Cadastrar Produto\n");
    printf("                               2- Remover produto\n");
    printf("                               3- Ver produtos\n");
    printf("                               4- Excluir conta\n");
    printf("                               0- SAIR\n\n");
    printf(ANSI_COLOR_YELLOW);
    printf("                               DIGITE SUA OPCAO:");
    printf(ANSI_COLOR_RESET);
    scanf("%d", opcao);
    system("pause");
    return 0;
}