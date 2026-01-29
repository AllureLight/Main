#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#define TAM 100000
#define Linha 20

int main() {
    time_t start, end;
    start = clock();

    int V[TAM], aux;
    srand(time(NULL));
    
    for(int i = 0; i < TAM; i++){
        V[i] = rand() % 100;
        printf("%d ", V[i]);
        if(i % Linha == 0 && i != 0)
            printf("\n");
    }
    
    printf("\n\n");
    
    for(int i = (TAM - 1); i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(V[j] > V[j+1]){
                aux = V[j];
                
                V[j] = V[j+1];
                
                V[j+1] = aux;   
            }
        }
    }
    
    for(int i = 0; i < TAM; i++){
        printf("%d ", V[i]);
        if(i % Linha == 0 && i != 0)
            printf("\n");
    }
    
    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC); 
    return 0;
}