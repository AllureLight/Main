#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

void imprimir(int Vet[TAM]){
    for(int i = 0; i < TAM; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int main(){
    time_t start, end;
    start = clock();

    int h = 1, n = TAM, j;
    int v[TAM], aux;
    int comparacoes = 0, trocas = 0;

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    while(h < n / 3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        for(int i = h; i < n; i++){
            aux = v[i];
            j = i - h;
            comparacoes++;
            while(j >= 0 && aux < v[j]){
                v[j+h] = v[j];
                trocas++;
                j = j - h;
            }
            v[j+h] = aux;
            trocas++;
        }
        h /= 3;
    }

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    printf("\nNumero de comparacoes : %d \nNumero de trocas: %d", comparacoes, trocas);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}