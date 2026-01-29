#include <stdlib.h>
#include <stdio.h>

typedef struct arvore{
    char info;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore* criarArvoreVazia(){
    return NULL;
}

Arvore *criarArvore(char c, Arvore* sae, Arvore* sad){
    Arvore* a = (Arvore*)malloc(sizeof(Arvore));
    if(a!=NULL){
        a->info = c;
        a->esq = sae;
        a->dir = sad;
    }
    return a;
}

int estaVazia(Arvore *arv){
    return(arv==NULL);
}

void imprimeArvore(Arvore* arv)/*com recursao*/{
    printf("<");
    if(!estaVazia(arv)){
        printf("%c", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* liberarArv(Arvore* arv){
    if(!estaVazia(arv)){
        liberarArv(arv->esq);
        liberarArv(arv->dir);
        free(arv);
    }
    return NULL;
}

int pertence(Arvore* arv, char c){
    if(estaVazia(arv)){
        return 0;
    }
    else{
        if(arv->info == c)
            return 1;
        else
            return(pertence(arv->esq, c) || pertence(arv->dir, c));
    }
}

int contNos(Arvore* arv){
    if(!estaVazia(arv))
        return 1 + contNos(arv->esq) + contNos(arv->dir);
    else
        return 0;
}//dar uma olhada  dps

int qtdeFolhas(Arvore* l){
    if(!estaVazia(l)){
        if((l->esq == NULL) && (l->dir == NULL)){
            return 1;
        }
        else
            return qtdeFolhas(l->dir) + qtdeFolhas(l->esq);
    }
    else
        return 0;
}

int qtdeChar(Arvore* l, char c){
    if(estaVazia(l))
        return 0;
    else
        return (l->info == c) + qtdeChar(l->esq, c) + qtdeChar(l->dir, c);
}

int iguais(Arvore* a, Arvore *b){
    if(estaVazia(a) && estaVazia(b))
        return 1;
    else if(estaVazia(a) || estaVazia(b))
        return 0;
    return (a->info == b->info) && iguais(a->dir, b->dir) && iguais(a->esq ,b->esq);
}

Arvore* copia(Arvore* a){
    if(!estaVazia(a)){
        Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
        if(novo!=NULL){
            novo->info = a->info;
            novo->esq = copia(a->esq);
            novo->dir = copia(a->dir);
        }
    return novo;
    }
    else
        return NULL;
}

int maior(Arvore *l){
    if(!estaVazia(l)){
        int maiorEsq = maior(l->esq);
        int maiorDir = maior(l->dir);
        int maior = l->info;

        if(maiorEsq > maior)
            maior = maiorEsq;
        if(maiorDir > maior)
            maior = maiorDir;
    return maior;
    }
    return -1;
}

int main() {
    Arvore* d = criarArvore('d', criarArvoreVazia(), criarArvoreVazia());
    Arvore* b = criarArvore('b', criarArvoreVazia(), d);
    
    Arvore* f = criarArvore('f', criarArvoreVazia(), criarArvoreVazia());
    Arvore* e = criarArvore('e', criarArvoreVazia(), criarArvoreVazia());
    
    Arvore *c = criarArvore('c', e, f);
    Arvore *a = criarArvore('a', b, c);
    
    printf("Original: ");
    imprimeArvore(a);

    Arvore* novo = copia(a);
    printf("\n\nNovo: ");
    imprimeArvore(novo);
    return 0;
}