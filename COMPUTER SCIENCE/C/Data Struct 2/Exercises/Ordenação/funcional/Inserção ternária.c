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

int main(){
    time_t start, end;
    start = clock();

    int v[TAM], aux;
    int esq, dir, m1, m2;

    srand( (unsigned)time(NULL) );
    for(int a = 0; a < TAM ; a++){
        v[a] = rand()%100;
    }

    printf("Valores fora da ordem:\n");
    imprimir(v);

    for(int i = 0; i < TAM ; i++){
        aux = v[i];
        esq = 0;
        dir = i;
        while(esq < dir){
            int terc = (dir - esq) / 3;
            m1 = esq + terc;
            m2 = dir - terc;

            if(v[m1] > aux)
                dir = m1;
            else if(v[m2] < aux)
                esq = m2 + 1;
            else{
                esq = m1 + 1;
                dir = m2;
            }
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