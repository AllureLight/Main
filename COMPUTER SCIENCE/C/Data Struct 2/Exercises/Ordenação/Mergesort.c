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

void intercalar(int *vetor, int ini, int fim, int meio){
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int aux[fim - ini + 1];

    while(i <= meio && j <= fim){
        comparacoes++;
        if (vetor[i] <= vetor[j]) {
            aux[k++] = vetor[i++];
        } else {
            aux[k++] = vetor[j++];
        }
        trocas++; 
    }

    while (i <= meio) {
        aux[k++] = vetor[i++];
        trocas++;
    }

    while(j <= fim){
        aux[k++] = vetor[j++];
        trocas++;
    }
    
    for(i = ini, k = 0; i <= fim; i++, k++){
        vetor[i] = aux[k];
        trocas++;
    }
}
void mergeSort(int *vetor, int ini, int fim){
    if(ini < fim){
        int meio = (ini + fim) / 2;
        mergeSort(vetor, ini, meio);
        mergeSort(vetor, meio + 1, fim);
        intercalar(vetor, ini, fim, meio);
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[TAM] = {4, 2, 9, 3, 5 ,7};

    /*srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }*/

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