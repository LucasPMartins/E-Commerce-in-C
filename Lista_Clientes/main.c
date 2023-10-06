#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncad.h"

int main(){
    cadastro it;
    printf("Digite o seu nome:");
    fgets(it.nome,30,stdin);
    it.nome[strcspn(it.nome,"\n")] = '\0';
    printf("Digite sua senha:");
    fgets(it.senha,10,stdin);
    it.senha[strcspn(it.senha,"\n")] = '\0';
    printf("Teste: %s %s\n\n",it.nome,it.senha);
    lista_clientes *l = criar_lista_clientes();
    verifica_cliente(l,it);
    produtos p;
    strcpy(p.NOME,"Celular Xiomai");
    strcpy(p.DESCRICAO,"Celular de alta qualidade, nunca explodiu");
    p.CATEGORIA = 1;
    p.NOTA_AVALIACAO = 5;
    p.QUANTIDADE = 100;
    p.VALOR = 999.99;
    insere_nova_compra(l,it,p);
    insere_novo_carrinho(l,it,p);
    printf("Obrigado por comprar :)\n\n");
    strcpy(p.NOME,"Celular Iphone 12");
    strcpy(p.DESCRICAO,"Celular muito caro");
    p.CATEGORIA = 1;
    p.NOTA_AVALIACAO = 5;
    p.QUANTIDADE = 1000;
    p.VALOR = 9999.99;
    insere_novo_carrinho(l,it,p);
    strcpy(p.NOME,"Microondas");
    strcpy(p.DESCRICAO,"Risco de comida raioativa");
    p.CATEGORIA = 3;
    p.NOTA_AVALIACAO = 3;
    p.QUANTIDADE = 100;
    p.VALOR = 599.99;
    
    insere_nova_compra(l,it,p);
    insere_novo_carrinho(l,it,p);

    mostrar_conta_cliente(l,it);

    remove_do_carrinho(l,it,1);
    mostrar_conta_cliente(l,it);
    excluir_conta_cliente(l,it);

    mostrar_conta_cliente(l,it);


    return 0;
}






