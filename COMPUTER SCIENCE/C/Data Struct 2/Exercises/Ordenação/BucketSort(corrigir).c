#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Esta dando overflow na quantidade de baldes e numeros de baldes, se colocar mts numeros acaba dando overflow

#define tam_bucket 1000
#define num_bucket 100
#define MAX 10000

int comparacoes = 0, trocas = 0;

typedef struct bucket{
    int balde[tam_bucket];
    int top;
}Bucket;

void imprimir(int v[]){
    for(int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble(int v[], int tam){
    int i, j, temp;
    for(j = 0; j < tam - 1; j++){
        for(i = 0; i < tam - 1; i++){
            comparacoes++;
            if(v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocas++;
            }
        }
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

    for(i = 0; i < num_bucket; i++){
        bucket[i].top = 0;
    }

    for (i = 0; i < tam; i++) {
        int indice = (v[i] - min) * num_bucket / (max - min + 1);
        bucket[indice].balde[bucket[indice].top++] = v[i];
        trocas++;
    }

    for(i = 0; i < num_bucket; i++){
        if(bucket[i].top > 1)
            bubble(bucket[i].balde, bucket[i].top);
    }

    k = 0;
    for(i = 0; i < num_bucket; i++){
        for(j = 0; j < bucket[i].top; j++){
            v[k++] = bucket[i].balde[j];
        }
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[MAX];

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < MAX ; a++){
        v[a] = rand()%100;
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