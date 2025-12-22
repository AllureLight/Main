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

int main() {
    time_t start, end;
    start = clock();

    int V[TAM], aux, j;
    
    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        V[a] = rand()%100;
    }
    
    printf("Valores fora da ordem:\n");
    imprimir(V);
    
    for(int i = 1; i < TAM; i++){
        aux = V[i];
        j = i - 1;
        while((j >= 0) && (aux < V[j])){
            V[j+1] = V[j];
            j = j-1;
        }
        if(j != (i-1))
            V[j+1] = aux;
    }
    
    printf("\nValores dentro da ordem:\n");
    imprimir(V);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}