#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Bolha com Criterio de Parada

#define TAM 100000

void imprimir(int Vet[TAM]){
    for(int i = 0; i < TAM; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int main() {
    time_t start, end;
    start = clock();

    int V[TAM], aux, j;
    int x = 1, n = TAM;
    int indice = n-1;
    
    srand( (unsigned)time(NULL) );

    for(int i = 0; i < TAM ; i++){
        V[i] = rand()%100;
    }
    
    printf("Valores fora da ordem:\n");
    imprimir(V);

    while(x){
        j = 1;
        x = 0;
        while(j < n){
            if(V[j-1] > V[j]){
                aux = V[j-1];
                V[j-1] = V[j];
                V[j] = aux;
                x = 1;
            }
            indice = j;
            j = j+1;
        }
        n = indice;
    }
    
    printf("\nValores dentro da ordem:\n");
    imprimir(V);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}