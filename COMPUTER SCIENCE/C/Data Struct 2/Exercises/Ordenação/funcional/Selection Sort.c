#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50000

void imprimir(int Vet[TAM]){
    for(int i = 0; i < TAM; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int main(){
    time_t start, end;
    start = clock();

    int v[TAM], n = TAM, menor, aux;
    int comparacoes = 0, trocas = 0;

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    for(int i = 0; i < n -1 ;i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            comparacoes++;
            if(v[j] < v[menor])
                menor = j;
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            trocas++;
        }
    }
    
    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}