#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "ListaEncad.c"

int main()
{
    lista_clientes *l = criar_lista_clientes();
    cadastro it;
    char pt[30], t[30];
    produtos p;
    float x;
    int y;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        printf("Usuario:\n");
        printf("Nome:");
        setbuf(stdin, NULL);
        fgets(it.nome, 30, stdin);
        printf("Senha:");
        setbuf(stdin, NULL);
        fgets(it.senha, 10, stdin);
        it.nome[strcspn(it.nome, "\n")] = '\0';
        it.senha[strcspn(it.senha, "\n")] = '\0';
        insere_novo_cliente(l, it);
        printf("Produtos:\n");
        for (int j = 0; j < 10; j++)
        {

            y = rand() % 12;
            p.CATEGORIA = y;
            printf("Nome do Produto:");
            setbuf(stdin, NULL);
            fgets(pt, 30, stdin);
            printf("Descricao:");
            setbuf(stdin, NULL);
            fgets(t, 30, stdin);
            setbuf(stdin,NULL);
            printf("Quantidade:");
            scanf("%d",&p.QUANTIDADE);
            setbuf(stdin,NULL);
            printf("Valor:");
            scanf("%f",&p.VALOR);
            pt[strcspn(pt, "\n")] = '\0';
            t[strcspn(t, "\n")] = '\0';
            strcpy(p.DESCRICAO, t);
            strcpy(p.NOME, pt);
            y = rand() % 5;
            p.NOTA_AVALIACAO = y;
            y = rand();
            p.QUANT_AVALIACAO = y;
            y = rand() % 11;
            if (y % 2 == 0)
                insere_novo_carrinho(l, it, p, 10);
            else
                insere_nova_compra(l, it, p);
        }
        mostrar_conta_cliente(l, it);
    }
    mostra_lista_clientes(l);
    salvar_clientes(l);
    return 0;
}
