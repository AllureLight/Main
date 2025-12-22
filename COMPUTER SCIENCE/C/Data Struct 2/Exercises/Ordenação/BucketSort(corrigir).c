#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparacoes = 0, trocas = 0;

typedef struct {
    int valor[10];
    int top;
} Bucket;

void imprimir(int Vet[10]){
    for(int i = 0; i < 10; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

void bucketSort(int v[10], int tam){
    int num = 10;
    Bucket bucket[10];

    for(int i = 0; i < num; i++){
        bucket[i].top = 0;
    }

    for(int i = 0; i < tam; i++){
        int j = num - 1;

        while(j >= 0){
            comparacoes++;
            if(v[i] >= j*10){
                bucket[j].valor[bucket[j].top] = v[i];
                bucket[j].top++;
                trocas++;
                break;
            }
            j--;
        }
    }

    for(int i = 0; i < num; i++){
        if(bucket[i].top > 1)
            bucketSort(bucket[i].valor, bucket[i].top);
    }

    int inx = 0;
    
    for(int j = 0; j < num; j++){
        for(int k = 0; k < bucket[j].top; k++){
            v[inx] = bucket[j].valor[k];
            inx++;
        }
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[10];

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < 10 ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    bucketSort(v, 10);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}