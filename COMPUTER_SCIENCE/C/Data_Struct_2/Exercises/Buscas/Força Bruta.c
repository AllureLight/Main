#include <stdio.h>
#include <string.h>
#include <time.h>

//1 - Busca Força Bruta que vise encontrar a chave recebida pelo usuário. 
//Também deve ser armazenado número de comparações realizadas durante a busca.

int function(){
    int n, m, j, cont = 0;
    
    char T[] = "Ola_Mundo_Estou_Esperando_E_Sendo_Pequen_Diante_De_Tudo_Pequeno_Pois_Foi_Dito";
    char P[] = "Pequeno";
    
    n = strlen(T);
    m = strlen(P);

    
    for(int i = 0; i <= (n-m); i++){
        cont++;
        j = 0;
        while(j < m && T[i + j] == P[j]){
            j ++;
            if(j == m){
                printf("Ele fez %d comparacoes\n", cont);
                return i;
            }
        }
    }
    printf("Ele fez %d comparacoes\n", cont);
    return -1;
}

int main(){
    int a;
    clock_t start, end;
    start = clock();

    a = function();

    if(a != -1){
        printf("\nPalavra/Letra Encontrado!");
    }
    
    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}