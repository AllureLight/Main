#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore* criarArvoreVazia(){
    return NULL;
}

int estaVazia(Arvore *arv){
    return(arv==NULL);
}

int ocorrências_x (Arvore * l, int x){
    if(!estaVazia(l)){
        if (x == l->info)
            return 1 + ocorrencias_x(l->dir, x);
        else if (x < l->info)
            return ocorrencias_x(l->esq, x);
        else 
            return ocorrencias_x(l->dir, x);
    }
    return 0;
}

void OrdemNnCres(Arvore* l){
    if(!estaVazia(l)){
        OrdemNnCres(l->dir);

        if (l->esq == NULL && l->dir == NULL) {
            printf("%d ", l->info);
        }

        OrdemNnCres(l->esq);
    }
    else
        return;
}

int main(){

}