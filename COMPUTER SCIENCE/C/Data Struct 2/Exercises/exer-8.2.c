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
    
    srand( (unsigned)time(NULL) );
    for(int a = 0; a < 30 ; a++){
        V[a] = rand()%100;
    }
    
    printf("Valores fora da ordem:\n");
    imprimir(V);
    
    for(int i = 1; i < 30; i++){
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

    return 0;
}