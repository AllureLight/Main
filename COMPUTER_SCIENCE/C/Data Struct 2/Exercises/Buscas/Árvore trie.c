#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define Alfabeto 26

typedef struct trie{
    struct trie* filho[26];
    bool fim;
}Trie;

Trie* criarNo(){
    Trie* novo = (Trie*)malloc(sizeof(Trie));
    novo->fim = false;
    for(int i = 0; i < Alfabeto; i++)
        novo->filho[i] = NULL;
    return novo;
}

void Inserir(Trie* t, const char* palavra){
    Trie* atual = t;
    for(int i = 0; palavra[i] != '\0'; i++){
        char c = palavra[i];
        if(c < 'a' || c > 'z') continue;
        int indice = c - 'a';
        if(atual->filho[indice] == NULL)
            atual->filho[indice] = criarNo();
        atual = atual->filho[indice];
    }
    atual->fim = true;
}

bool buscar(Trie* t, const char *palavra){
    Trie* atual = t;
    for(int i = 0; palavra[i] != '\0'; i++){
        char c = palavra[i];
        if(c < 'a' || c > 'z') continue;
        int indice = c - 'a';
        if(atual->filho[indice] == NULL)
            return false;
        atual = atual->filho[indice];
    }
    return atual->fim;
}

void liberar(Trie* t){
    if(t !=NULL){
        for(int i = 0; i < Alfabeto; i++)
            liberar(t->filho[i]);
        free(t);
    }
}

int main(){
    time_t start, end;
    start = clock();

    Trie* raiz = criarNo();

    Inserir(raiz, "carro");
    Inserir(raiz, "abacate");
    Inserir(raiz, "bola");

    printf("Busca por 'carro': %s\n", buscar(raiz, "carro") ? "Encontrado" : "Nao encontrado");
    printf("Busca por 'casa': %s\n", buscar(raiz, "casa") ? "Encontrado" : "Nao encontrado");
    printf("Busca por 'bola': %s\n", buscar(raiz, "bola") ? "Encontrado" : "Nao encontrado"); 

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}