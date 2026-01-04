#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000

int comparacoes = 0, trocas = 0;

void imprimir(int v[]){
    for(int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void countSort(int v[], int n, int exp){
    int *output = malloc(n * sizeof(int));
    int i, count[10] = { 0 };

    for(i = 0; i < n; i++){
        comparacoes++;
        count[(v[i] / exp) % 10]++;
    }

    for(i = 1; i < 10; i++){
        comparacoes++;
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--){
        comparacoes++;
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        trocas++;
        count[(v[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++){
        v[i] = output[i];
        trocas++;
    }
    free(output);
}

void radixsort(int v[], int n){
    int max = v[0];
    for(int i = 1; i < n; i++){
        comparacoes++;
        if(v[i] > max) max = v[i];
    }

    for(int i = 1; max / i > 0 ; i *= 10) {
        comparacoes++;
        countSort(v, n, i);
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

    radixsort(v, MAX);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}