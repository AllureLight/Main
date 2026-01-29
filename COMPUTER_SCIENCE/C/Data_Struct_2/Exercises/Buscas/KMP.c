#include <stdio.h>
#include <string.h>
#include <time.h>

//2 - Busca KMP que vise encontrar a chave recebida pelo usuário.
//Também deve ser armazenado número de comparações realizadas durante a busca.

void pre_processamento(char *P, int *aux){
    int m = strlen(P);
    int j = -1;
    aux[0] = j;

    for(int i = 1; i <= (m-1); i++){
        while(j > -1 && P[j+1] != P[i]){
            j = aux[j];
        }
        if(P[i] == P[j+1]){
            j++;
        }
        aux[i] = j;
    }
}

int busca(char *P, char *T){

    int m = strlen(P), n = strlen(T), aux[m], k = -1;

    pre_processamento(P, aux);

    int cont = 0;

    for(int i = 0; i <= (n-1); i++){
        cont++;
        while(k > -1 && P[k+1] != T[i]){
            k = aux[k];
        }
        if(T[i] == P[k + 1]){
            k++;
        }
        if(k == m -1){
            printf("Ele fez %d combinacoes\n\n", cont);
            return (i-k);
        }
    }
    printf("Ele fez %d combinacoes\n\n", cont);
    return -1;
}

int main(){
    clock_t start, end;
    start = clock();

    char P[] = "Pequeno";
    char T[] = "Ola_Mundo_Estou_Esperando_E_Sendo_Pequen_Diante_De_Tudo_Pequeno_Pois_Foi_Dito";

    int a = busca(P, T);

    if(a != -1)
        printf("Encontrado!");

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}