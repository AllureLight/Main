#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gera o vetor com n valores
int *geraVet(int n){
    int *vetor = malloc(n * sizeof(int));

    if(vetor == NULL){
        printf("Error!\n");
        return NULL;
    }

    return vetor;
}

//gera n numeros em ordem aleatoria, crescente e decrescente
void geraNum(int opc, int *vetor, int n){
    printf("\n");
    switch(opc){
        //gera em ordem aleatoria
        case 0:
            srand(time(NULL));
            for(int i = 0; i < n; i++)
                vetor[i] = rand() % 100;
            break;
        //gera em ordem crescente
        case 1:
            for(int i = 0; i < n; i++)
                vetor[i] = i;
            break;
        //gera em ordem decrescente
        case 2:
            for(int i = n; i > 0; i--)
                vetor[n-i] = i-1;
            break;
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", vetor[i]);
}

//Abre o arquivo e escreve a saida do vetor nele
void escreveSaida(int *vetor, int n){
    FILE* arquivo;
    arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    for(int i = 0; i < n; i++)
        fprintf(arquivo, "%d", vetor[i]);
    fclose(arquivo);
}

int main(){
    time_t start, end;
    int opc, n;

    //Escolher o tamanho do vetor
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = geraVet(n);

    //Escolher a forma que o vetor vai ser preenchido
    do{
        printf("\n1 - aleatoria\t2 - crescente\t 3 - descrecente\nEscolha um metodo de geracao de valores: ");
        scanf("%d", &opc);
        if(opc != 1 && opc != 2 && opc != 3)
            printf("\nDigite uma opcao valida!\n");
    }while(opc != 1 && opc != 2 && opc != 3);
    opc--;
    geraNum(opc, vetor, n);

    //Inicio da contagem de tempo
    start = clock();

    printf("\nEscolha um algoritmo de ordenacao:\n1- Bolha\t");

    //Fim da contagem de tempo
    end = clock();

    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("a");
    return 0;
}
