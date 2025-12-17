#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int Vet[10]){
    for(int i = 0; i < 10; i++){
        printf("%d ", Vet[i]);
    }
    printf("\n");
}

int main(){
    time_t start, end;
    start = clock();

    int v[10], aux;
    int esq, dir, meio;

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < 10 ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    for(int i = 0; i < 10 ; i++){
        aux = v[i];
        esq = 0;
        dir = i;
        while(esq < dir){
            meio = (esq + dir) / 2;
            if(v[meio] <= aux)
                esq = meio + 1;
            else
                dir = meio;
        }
        for(int j = i; j > esq; j--){
            v[j] = v[j-1];
        }
        v[dir] = aux;
    }

    printf("\nValores dentro da ordem:\n");
    imprimir(v);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}