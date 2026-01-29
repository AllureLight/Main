#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 256

void CaracterRuim(char *P, int m, int CharRuim[MAX_CHAR]){
    int i;  

    for(i = 0; i < MAX_CHAR
    ; i++)
        CharRuim[i] = -1;

    for(i = 0; i < m; i++)
        CharRuim[(unsigned char)P[i]] = i;
}

void search(char *T, char* P){
    int m = strlen(P);
    int n = strlen(T);
    int comp = 0;
    int CharRuim[MAX_CHAR];
    CaracterRuim(P, m, CharRuim);

    int s = 0;
    while(s <= (n-m)){
        int j = m - 1;
        comp++;
        while(j >= 0 && P[j] == T[s + j])
            j--;

        if(j < 0){
            printf("Padrao encontrado na posicao %d\n", s);
            printf("Foram feitas %d comparacoes", comp);
            s += (s + m < n) ? m - CharRuim[(unsigned char)T[s + m]] : 1;
        }
        else{
            int deslocamento = j - CharRuim[(unsigned char)T[s + j]];
            s += (deslocamento > 1) ? deslocamento : 1;
        }
    }
}


int main(){
    clock_t start, end;
    start = clock();

    char T[] = "ABBDDCABDWWDACDADABCASDAAD";
    char P[] = "ABC";

    search(T, P);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}