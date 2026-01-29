#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int v[MAX];
int comparacoes = 0, trocas = 0;

void imprimir(int v[]){
    for(int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int Particao(int esq, int dir){
    int i = esq, j = dir;
    int aux, pivo = v[(i+j) / 2];

    while(i <= j){
        while(v[i] < pivo && i < dir){
            i++;
            comparacoes++;
        }
        while(v[j] > pivo && j > esq){
            j--;
            comparacoes++;
        }
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            trocas++;

            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(int esq, int dir){
    if(esq < dir){
        int i = Particao(esq, dir);
        QuickSort(esq, i - 1);
        QuickSort(i, dir);
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