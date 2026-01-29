#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct patricia {
    char *chave;
    int bit;
    struct patricia *esq, *dir;
} Patricia;

// retorna o bit na posição index (1-based)
int addBit(const char *chave, int Index) {
    int byte = (Index - 1) / 8;
    int bit = 7 - ((Index - 1) % 8);
    if (byte >= (int)strlen(chave)) return 0;
    return ((chave[byte] >> bit) & 1);
}

// cria um novo nó
Patricia* criar(const char *chave, int bit) {
    Patricia* novo = (Patricia*)malloc(sizeof(Patricia));
    novo->chave = strdup(chave);
    novo->bit = bit;
    novo->esq = novo->dir = novo;
    return novo;
}

// busca
Patricia* busca(Patricia* p, const char* chave) {
    if (!p) return NULL;
    Patricia *aux = p, *aux2 = p->esq;
    while (aux->bit < aux2->bit) {
        aux = aux2;
        int bit = addBit(chave, aux2->bit);
        aux2 = bit ? aux2->dir : aux2->esq;
    }
    return (strcmp(aux2->chave, chave) == 0) ? aux2 : NULL;
}

// inserção corrigida
Patricia* inserir(Patricia *p, const char *chave) {
    if (p == NULL) {
        p = criar(chave, 0);
        p->esq = p;
        return p;
    }

    Patricia* pai = p;
    Patricia* filho = p->esq;

    while (pai->bit < filho->bit) {
        pai = filho;
        int bit = addBit(chave, filho->bit);
        filho = bit ? filho->dir : filho->esq;
    }

    if (strcmp(filho->chave, chave) == 0) {
        printf("Chave ja existe: %s\n", chave);
        return p;
    }

    int i = 1;
    while (addBit(chave, i) == addBit(filho->chave, i)) i++;

    Patricia* pai2 = p;
    Patricia* filho2 = p->esq;

    while ((pai2->bit < filho2->bit) && (filho2->bit < i)) {
        pai2 = filho2;
        int bit = addBit(chave, filho2->bit);
        filho2 = bit ? filho2->dir : filho2->esq;
    }

    Patricia* novo = criar(chave, i);
    int bitNovo = addBit(chave, i);

    if (bitNovo) {
        novo->dir = novo;
        novo->esq = filho2;
    } else {
        novo->esq = novo;
        novo->dir = filho2;
    }

    if (addBit(chave, pai2->bit))
        pai2->dir = novo;
    else
        pai2->esq = novo;

    return p;
}

void imprimir(Patricia *atual) {
    if (atual == NULL) return;

    if (atual->esq != NULL && atual->esq->bit > atual->bit)
        imprimir(atual->esq);

    printf("%s\n", atual->chave);

    if (atual->dir != NULL && atual->dir->bit > atual->bit)
        imprimir(atual->dir);
}

int main() {
    time_t start, end;
    start = clock();

    Patricia *raiz = NULL;

    raiz = inserir(raiz, "1");
    raiz = inserir(raiz, "10");
    raiz = inserir(raiz, "11");
    raiz = inserir(raiz, "111");

    printf("Chaves na arvore:\n");
    imprimir(raiz);

    end = clock();
    printf("\nTempo: %.4f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}