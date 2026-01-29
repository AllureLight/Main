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

Arvore* Busca(Arvore* arv, int c){
    if(estaVazia(arv))
        return NULL;
    else{
        if(arv->info == c)
            return arv;    
        else if(arv->info > c)
            return Busca(arv->esq, c);
        else
            return Busca(arv->dir, c);
    }
}

Arvore* insere(Arvore* arv, int c){
    if(estaVazia(arv)){
        arv = (Arvore*)malloc(sizeof(Arvore));
        arv->info = c;
        arv->esq = arv->dir = NULL;
    }
    else{
        if(c < arv->info)
            arv->esq = insere(arv->esq, c);
        else
            arv->dir = insere(arv->dir, c);
    }
    return arv;
}

void imprimeArvore(Arvore* arv)/*com recursao*/{
    printf("<");
    if(!estaVazia(arv)){
        printf("%d", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* remover(Arvore* arv, int c){
    if(estaVazia(arv))
        return NULL;
    else{
        if(c < arv->info)
            arv->esq = remover(arv->esq, c);
        else if(c > arv->info)
            arv->dir = remover(arv->dir, c);
        else{
            if(arv->esq==NULL && arv->dir==NULL){
                free(arv);
                arv = NULL;
            }
            else if(arv->dir == NULL){
                Arvore* t = arv;
                arv = arv->esq;
                free(t);
            }
            else if(arv->esq == NULL){
                Arvore* t = arv;
                arv = arv->dir;
                free(t);
            }
            else{
                Arvore* t = arv->esq;
                while(t->dir!=NULL){
                    t=t->dir;
                }
                arv->info = t->info;
                t->info = c;
                arv->esq = remover(arv->esq, c);
            }
        }
        return arv;
    }
}

int main() {
    Arvore *arv = criarArvoreVazia();
    arv = insere(arv, 7);
    arv = insere(arv, 8);
    arv = insere(arv, 5);
    imprimeArvore(arv);
    return 0;
}