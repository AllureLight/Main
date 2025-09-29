#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHAS 20 

int tradicional(int *val, int chave, int dir){
    int esq = 0, meio;
    
    while(esq <= dir){
        meio = (esq + dir)/ 2;
        if(chave < val[meio])
            dir = meio - 1;
        else if(chave > val[meio])
            esq = meio + 1;
        else
            return 1;
    }
    return 0;
}

int recursiva(int *val, int chave, int dir, int esq){
    int meio = (esq + dir)/2;
    if (esq > dir)
        return 0;
    else if(val[meio] == chave)
        return 1;
    else if(val[meio] > chave)
        return recursiva(val, chave, meio - 1, esq);
    else
        return recursiva(val, chave, dir, meio + 1);
}

int main() {
    int opc, valores[MAX_LINHAS], chave, tamanho = 0;

    clock_t start, end;
    start = clock();
    
    FILE *arquivo = fopen("Entrada_busca.csv", "r");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while(fscanf(arquivo, "%d", &valores[tamanho]) == 1 && tamanho < MAX_LINHAS){
        tamanho++;
    }
    fclose(arquivo);
    
    do{
        int x = 2;
        printf("0 - Pesquisa Tradicional\n");
        printf("1 - Pesquisa Recursiva\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
        if(opc == 0 || opc == 1){
            printf("\nInsira um valor a ser procurado:");
            scanf("%d", &chave);
        }
        switch(opc){
            case 0:
                x = tradicional(&valores[0], chave, tamanho);
                break;
            
            case 1:
                x = recursiva(&valores[0], chave, tamanho, 0);
                break;
            
            case 2:
                break;
            
            default:
                printf("\nDigite um valor Valido!\n");
                break;
        }
        if(x == 1)
            printf("\nValor Encontrado!\n\n");
        else if(x == 0)
            printf("\nValor nn Encontrado!\n\n");
    }while(opc !=2);

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}