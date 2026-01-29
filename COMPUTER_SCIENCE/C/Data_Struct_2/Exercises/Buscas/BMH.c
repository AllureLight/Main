#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 256

int BMH(char *T, char *P)
{
    int i, j, k;
    int n = strlen(T);
    int m = strlen(P);
    int d[MAX_CHAR];

    for (j=0; j < MAX_CHAR; j++) {
        d[j] = m;
    }

    for(j = 1; j < m; j++){
        d[(unsigned char)P[j - 1]] = m - j;
        printf("'%c' -> %d\n", P[j - 1], d[(unsigned char)P[j - 1]]);
    }

    i = m;

    while (i <= n) {
        k = i;
        j = m;
        while (T[k-1] == P[j-1] && j > 0) {
            k--;
            j--;
        }
        if (j == 0)
            return k;
        i += d[(unsigned char)T[i - 1]];
    }
    return -1;
}

int BMHCont(char *T, char *P)
{
    int i, j, k, ocorr = 0;
    int n = strlen(T);
    int m = strlen(P);
    int d[MAX_CHAR];

    for (j=0; j<MAX_CHAR; j++) {
        d[j] = m;
    }

    for (j=1; j<m; j++) {
        d[(unsigned char)P[j-1]] = m-j;
    }
    i = m;

    while (i <= n) {
        k = i;
        j = m;
        while (T[k-1] == P[j-1] && j > 0) {
            k--;
            j--;
        }
        if (j == 0)
            ocorr++;
        i += d[(unsigned char)T[i - 1]];
    }
    return ocorr;
}

int main()
{
    time_t start, end;
    start = clock();

    char texto[] = "aabcacbacbacac";
	char padrao[] = "cacbac";

    int ocorr;

    ocorr = BMH(texto, padrao);
    printf("Casamento na posição: %d \n", ocorr);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}