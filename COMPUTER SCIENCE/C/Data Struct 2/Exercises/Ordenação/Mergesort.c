#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

int comparacoes = 0, trocas = 0;

void imprimir(int Vet[TAM]){
    for(int i = 0; i < TAM; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

void intercalar(int v[], int ini, int fim, int meio){
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int aux[TAM];

    while(i <= meio || j <= fim){
        comparacoes++;
        if(i == meio + 1 || (v[j] < v[i] && j != fim+1)){
            aux[k] = v[j];
            j++;
            k++;
            trocas++;
        }
        else{
            aux[k] = v[i];
            i++;
            k++;
            trocas++;
        }
    }
    
    for(i = ini, k = 0; i <= fim; i++, k++){
        v[i] = aux[k];
    }
}

void mergeSort(int v[], int ini, int fim){
    if(ini < fim){
        int meio = (ini + fim) / 2;
        mergeSort(v, ini, meio);
        mergeSort(v, meio + 1, fim);
        intercalar(v, ini, fim, meio);
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[TAM];

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    mergeSort(v, 0, TAM-1);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}