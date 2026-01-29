#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int chave;
    struct arvore *dir;
    struct arvore *esq;
    struct arvore *meio;
}Arvore;

Arvore* criarArvoreVazia(){
    return NULL;
}

int estaVazia(Arvore *l){
    return(l==NULL);
}

int quantidadeNos(Arvore *l){
    if(!estaVazia(l)){
        return 1 + quantidadeNos(l->dir) + quantidadeNos(l->esq) + quantidadeNos(l->meio);
    }
    else
        return 0;
}