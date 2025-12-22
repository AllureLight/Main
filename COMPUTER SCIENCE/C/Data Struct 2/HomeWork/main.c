#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gera o vetor com n valores
int *geraVet(int n){
    int *vetor = malloc(n * sizeof(int));

    if(vetor == NULL){
        printf("Error!\n");
        return 1;
    }
    return vetor;
}

//gera n numeros em ordem aleatoria, descrescente e crescente
void geraNum(int opc, int *vetor, int n){
    switch(opc){
        //gera em ordem aleatoria
        case 0:
            srand(time(NULL));
            for(int i = 0; i < n; i++){
                vetor[i] = rand() % 100;
                printf("%d\n", vetor[i]);
            }
            break;
        //gera em ordem decrescente
        case 1:
            
            break;
        //gera em ordem crescente
        case 2:
            break;
    }   
}

int main(){
    time_t start, end;
    start = clock();

    

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}
