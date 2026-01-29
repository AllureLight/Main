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

void criaHeap(int v[], int inicio, int final, int *comparacoes, int *trocas){
    int aux = v[inicio];
    int j = inicio * 2 + 1;
    
    while(j <= final){

        (*comparacoes)++;
        if(j < final){
            if(v[j]<v[j+1]){
                j = j + 1;
            }
        }

        (*comparacoes)++;
        if(aux < v[j]){
            v[inicio] = v[j];
            (*trocas)++;
            inicio = j;
            j = 2 * inicio + 1;
        }
        else
            j = final + 1;
    }
    v[inicio] = aux;
}

void HeapSort(int v[], int n, int *comparacoes, int *trocas){
    int aux;

    for(int i = (n-1)/2; i >= 0; i--){
        criaHeap(v, i, n-1, comparacoes, trocas);
    }

    for(int i = n - 1; i > 0; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        (*trocas)++;

        criaHeap(v, 0, i - 1, comparacoes, trocas);
    }
}

int main(){
    time_t start, end;
    start = clock();

    int v[TAM], n = TAM;
    int comparacoes = 0, trocas = 0;

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    HeapSort(v, n, &comparacoes, &trocas);

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}