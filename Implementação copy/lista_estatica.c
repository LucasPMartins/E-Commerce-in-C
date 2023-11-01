#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncad.h"


Lista_estatica *criar_estatica(){
    Lista_estatica *l = (Lista_estatica *)malloc(sizeof(Lista_estatica));
    if (l != NULL)
        l->total = 0;
    return l;
}

void limpar_estatica(Lista_estatica *l) {
    if (l != NULL)
        l->total = 0;
}

int inserirInicio_estatica(Lista_estatica *l, produtos it){
    int i;
    if (l == NULL) return 2;
    if (listaCheia_estatica(l) == 0) return 1;
    
    for (i=l->total;i>0;i--) {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = it;
    l->total++;

    return 0;
}

int inserirFim_estatica(Lista_estatica *l, produtos it){
    if (l == NULL) return 2;
    if (listaCheia_estatica(l) == 0) return 1;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}

int buscarItemChave_estatica(Lista_estatica *l, char* chave,produtos *retorno){
    int i;
    if (l == NULL) return 2;
    if (listaVazia_estatica(l) == 0) return 1;
    for (i=0;i<l->total;i++)
        if (strcmp(l->valores[i].nome_loja,chave) == 0){
            *retorno = l->valores[i];
            return 0;
        }
    return -1;
}

int listaVazia_estatica(Lista_estatica *l) {
    if (l == NULL) return 2;
    if (l->total == 0) return 0;
    else return 1;
}
int listaCheia_estatica(Lista_estatica *l) {
    if (l == NULL) return 2;
    if (l->total == 5) return 0;
    else return 1;
}
void mostrar_estatica(Lista_estatica *l) {
    int i;
    if (l != NULL) {
    printf("[");
    for (i=0;i<l->total;i++) {
        printf(" {%s, ",l->valores[i].NOME);
        printf("%s, ",l->valores[i].DESCRICAO);
        printf("%s, ",l->valores[i].nome_loja);
        printf("%d} ",l->valores[i].CATEGORIA);
    }
    printf("]\n");
    }

}

int removerInicio_estatica(Lista_estatica *l) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia_estatica(l) == 0) return 1;
    for (i=0;i<l->total-1;i++)
        l->valores[i] = l->valores[i+1];

    l->total--;
    return 0;
}

int removerFim_estatica(Lista_estatica *l) {
    if (l == NULL) return 2;
    if (listaVazia_estatica(l) == 0) return 1;
    l->total--;
    return 0;
}

int inserirPosicao_estatica(Lista_estatica *l, produtos it, int pos){
    int i;
    if( l == NULL)
        return 2; // Se a lista existe ele prossegue
    if(listaCheia_estatica(l) == 0) 
        return 1; //se a lista estiver cheia, ela retorna 0.
    for (i=l->total;i>pos;i--)
        l->valores[i] = l->valores[i-1];
    l->valores[pos] = it;
    l->total++;
    return 0;
}
int removerPosicao_estatica(Lista_estatica *l, int pos){
    int i;
    if (l == NULL) return 2; // se a lista existe
    if (listaVazia(l) == 0) return 1; //se  a lista nao e cheia

    for (i=pos;i<l->total-1;i++)
        l->valores[i] = l->valores[i+1];

    l->total--;
    return 0;
}
int removerItem_estatica(Lista_estatica *l, produtos it){

    if (l == NULL) return 2; // se a lista existe
    if (listaVazia_estatica(l) == 0) return 1; //se  a lista nao e cheia
    int i;
    for(i=0;i<l->total;i++){
            if (strcmp(it.NOME,l->valores[i].NOME) == 0){
                removerPosicao_estatica(l,i);
                i--;
            }
    }
    l->total--;
    return 0;
}

/*
int buscarPosicao(Lista_estatica *l, int pos, produtos *it){
    if (l == NULL) return 2; // se a lista existe
    if (listaVazia(l) == 0) return 1; //se  a lista nao e cheia
    it->mat = l->valores[pos].mat;
    it->n1 = l->valores[pos].n1;
    strcpy(it->nome,l->valores[pos].nome);
    return 0;
}

int ContemItem(Lista_estatica *l, produtos it){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 3;
    int i,ver=0;
    for(i=0;i<l->total;i++){
        if(l->valores[i].mat == it.mat){
            ver = 1;
        }
    }
    if(ver)
        return 0;
    else
        return 1;

}

int ContaItem(Lista_estatica *l, produtos it){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 3;
    int i,ver=0;
    for(i=0;i<l->total;i++){
        if(l->valores[i].mat == it.mat){
            ver++;
        }
    }
    return ver;
}
*/