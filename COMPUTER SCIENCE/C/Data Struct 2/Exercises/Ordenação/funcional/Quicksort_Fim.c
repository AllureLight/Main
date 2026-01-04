#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000

int v[MAX];
int comparacoes = 0, trocas = 0;

void imprimir(int v[]){
    for(int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int Particao(int esq, int dir){
    int i = esq - 1;
    int aux, pivo = v[dir];

    for(int j = esq; j < dir; j++){
        comparacoes++;
        if(v[j] <= pivo){
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            trocas++;
        }
    }

    aux = v[i + 1];
    v[i+1] = v[dir];
    v[dir] = aux;
    trocas++;

    return i + 1;
}

void QuickSort(int esq, int dir){
    if(esq < dir){
        int i = Particao(esq, dir);
        QuickSort(esq, i - 1);
        QuickSort(i + 1, dir);
    }
}

int main(){
    time_t start, end;
    start = clock();

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < MAX ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    QuickSort(0, MAX - 1);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}