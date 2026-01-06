#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam_bucket 1000
#define num_bucket 100
#define MAX 500000

int comparacoes = 0, trocas = 0;

typedef struct bucket{
    int *balde;
    int top;
}Bucket;

void imprimir(int v[]){
    for(int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insertion(int v[], int tam){
    int i, j, chave;

    for (i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (v[j] > chave) {
                v[j + 1] = v[j];
                trocas++;
                j--;
            } else {
                break;
            }
        }

        v[j + 1] = chave;
        trocas++;
    }
}

void bucketSort(int v[], int tam){
    Bucket bucket[num_bucket];
    int j, i, k;

    int min = v[0], max = v[0];

    for(i = 1; i < tam; i++){
        if(v[i] < min) min = v[i];
        if(v[i] > max) max = v[i]; 
    }

    if( max == min) return;

    for (i = 0; i < num_bucket; i++) {
        bucket[i].top = 0;
        bucket[i].balde = malloc(sizeof(int) * tam);
    }

    for (i = 0; i < tam; i++) {
        int indice = (v[i] - min) * num_bucket / (max - min + 1);
        bucket[indice].balde[bucket[indice].top++] = v[i];
        trocas++;
    }

    for(i = 0; i < num_bucket; i++){
        if(bucket[i].top > 1)
            insertion(bucket[i].balde, bucket[i].top);
    }

    k = 0;
    for(i = 0; i < num_bucket; i++){
        for(j = 0; j < bucket[i].top; j++){
            v[k++] = bucket[i].balde[j];
        }
        free(bucket[i].balde);
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[MAX];

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < MAX ; a++){
        v[a] = rand() & 100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    bucketSort(v, MAX);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}