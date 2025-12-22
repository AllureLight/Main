#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Muda o pivo a partir desse valor
//1 - meio
//2 - final (nao ta funcionando)
//3 - inicio
#define PIVO 3

int v[10];
int comparacoes = 0, trocas = 0;

void imprimir(int Vet[10]){
    for(int i = 0; i < 10; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int definirPivo(int i, int j){
    if(PIVO == 1)
        return (i + j) / 2;
    else if(PIVO == 2)
        return j;
    else
        return i;
}

int Particao(int esq, int dir){
    int i = esq, j = dir;
    int aux, pivo = v[definirPivo(i, j)];

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
    for(int a = 0; a < 10 ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    QuickSort(0, 9);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}