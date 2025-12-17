#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int Vet[30]){
    for(int i = 0; i < 30; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int main() {
    int V[30], aux, j;
    int x = 1, n = 30;
    int indice = n-1;
    
    srand( (unsigned)time(NULL) );

    for(int i = 0; i < 30 ; i++){
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

    return 0;
}