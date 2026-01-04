#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TESTE, TIRAR DPS
void imprimir(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

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
void geraNum(int *vetor, int n){
    int opc;
    
    do{
        printf("\n0 - aleatoria\t1 - crescente\t 2 - descrecente\nEscolha um metodo de geracao de valores: ");
        scanf("%d", &opc);
        if(opc != 0 && opc != 1 && opc != 2)
            printf("\nDigite uma opcao valida!\n");
    }while(opc != 0 && opc != 1 && opc != 2);

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

//ALGORITMOS DE ORDENACAO :
//Bolha
void bolha(int *vetor, int n) {
    int aux;
    
    for(int i = (n - 1); i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                
                vetor[j] = vetor[j+1];
                
                vetor[j+1] = aux;   
            }
        }
    }
}

//Bolha com Criterio de Parada
void bolhaCP(int *vetor, int n) {
    int aux, j;
    int x = 1;
    int indice = n-1;

    while(x){
        j = 1;
        x = 0;
        while(j < n){
            if(vetor[j-1] > vetor[j]){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                x = 1;
            }
            indice = j;
            j = j+1;
        }
        n = indice;
    }
}

//Insercao Direta
void insercaoDireta(int *vetor, int n) {
    int aux, j;
    
    for(int i = 1; i < n; i++){
        aux = vetor[i];
        j = i - 1;
        while((j >= 0) && (aux < vetor[j])){
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        if(j != (i-1))
            vetor[j+1] = aux;
    }
}

//Insercao Binaria
void insercaoBinaria(int *vetor, int n){
    int aux;
    int esq, dir, meio;

    for(int i = 0; i < n; i++){
        aux = vetor[i];
        esq = 0;
        dir = i;
        while(esq < dir){
            meio = (esq + dir) / 2;
            if(vetor[meio] <= aux)
                esq = meio + 1;
            else
                dir = meio;
        }
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j-1];
        }
        vetor[dir] = aux;
    }
}

//Insercao Ternaria
void insercaoTernaria(int *vetor, int n){
    int aux;
    int esq, dir, m1, m2;

    for(int i = 0; i < n ; i++){
        aux = vetor[i];
        esq = 0;
        dir = i;
        while(esq < dir){
            int terc = (dir - esq) / 3;
            m1 = esq + terc;
            m2 = dir - terc;

            if(vetor[m1] > aux)
                dir = m1;
            else if(vetor[m2] < aux)
                esq = m2 + 1;
            else{
                esq = m1 + 1;
                dir = m2;
            }
        }
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j-1];
        }
        vetor[dir] = aux;
    }
}

//Shellsort
void shellsort(int *vetor, int n){
    int h = 1, j;
    int aux;

    while(h < n / 3){
        h = 3 * h + 1;
    }

    while(h >= 1){
        for(int i = h; i < n; i++){
            aux = vetor[i];
            j = i - h;
            while(j >= 0 && aux < vetor[j]){
                vetor[j+h] = vetor[j];
                j = j - h;
            }
            vetor[j+h] = aux;
        }
        h /= 3;
    }
}

//Selecao Direta
void selecaoDireta(int *vetor, int n){
    int menor, aux;

    for(int i = 0; i < n - 1;i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

//Heapsort
void criaHeap(int *vetor, int inicio, int final){
    int aux = vetor[inicio];
    int j = inicio * 2 + 1;
    
    while(j <= final){

        if(j < final){
            if(vetor[j] < vetor[j+1]){
                j = j + 1;
            }
        }

        if(aux < vetor[j]){
            vetor[inicio] = vetor[j];
            inicio = j;
            j = 2 * inicio + 1;
        }
        else
            j = final + 1;
    }
    vetor[inicio] = aux;
}
void heapSort(int *vetor, int n){
    int aux;

    for(int i = (n-1)/2; i >= 0; i--){
        criaHeap(vetor, i, n-1);
    }

    for(int i = n - 1; i > 0; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        criaHeap(vetor, 0, i - 1);
    }
}

//Quicksort Centro void quicksortCentro(int *vetor, int n)

//Quicksort Fim void quicksortFim(int *vetor, int n)

////Quicksort Mediana void quicksortMediana(int *vetor, int n)

//Mergesort OLHAR DPS ******
void intercalar(int *vetor, int ini, int fim, int meio){
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int aux[fim];

    while(i <= meio || j <= fim){
        if(i == meio + 1 || (vetor[j] < vetor[i] && j != fim+1)){
            aux[k] = vetor[j];
            j++;
            k++;
        }
        else{
            aux[k] = vetor[i];
            i++;
            k++;
        }
    }
    
    for(i = ini, k = 0; i <= fim; i++, k++){
        vetor[i] = aux[k];
    }
}
void mergeSort(int *vetor, int ini, int fim){
    if(ini < fim){
        int meio = (ini + fim) / 2;
        mergeSort(vetor, ini, meio);
        mergeSort(vetor, meio + 1, fim);
        intercalar(vetor, ini, fim, meio);
    }
}

//Radixsort void radixsort(int *vetor, int n)
void countSort(int *vetor, int n, int exp){
    int *output = malloc(n * sizeof(int));
    int i, count[10] = { 0 };

    for(i = 0; i < n; i++){
        count[(vetor[i] / exp) % 10]++;
    }

    for(i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--){
        output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
        count[(vetor[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++){
        vetor[i] = output[i];
    }
    free(output);
}
void radixSort(int *vetor, int n){
    int max = vetor[0];
    for(int i = 1; i < n; i++){
        if(vetor[i] > max) max = vetor[i];
    }

    for(int i = 1; max / i > 0 ; i *= 10) {
        countSort(vetor, n, i);
    }
}

//Bucketsort void bucketsort(int *vetor, int n)

//roda todos os algoritmos
void todosAlgoritmos(int *vetor, int n){
    bolha(vetor, n);
    bolhaCP(vetor, n);
    insercaoDireta(vetor, n);
    insercaoBinaria(vetor, n);
    insercaoTernaria(vetor, n);
    shellsort(vetor, n);
    selecaoDireta(vetor, n);
    heapSort(vetor, n);
    //quick1
    //quick2
    //quick3
    //merge
    radixSort(vetor, n);
    //bucket
}

//roda um algoritmo escolhido
void umAlgoritmo(int *vetor, int n){
    int opc;
            printf("\n0 - Bolha\n1 - Bolha com Criterio de Parada\n2 - Insercao Direta\n3 - Insercao Binaria\n4 - Insercao Ternaria\n5 - Shellsort\n6 - Selecao Direta\n7 - Heapsort\n8 - Quicksort Centro\n9 - Quicksort Fim\n10 - Quicksort Mediana\n11 - Mergesort\n12 - Radixsort\n13 - Bucketsort");
            do{
                printf("\nEscolha qual algoritmo de ordenacao vai ser utilizado: ");
                scanf("%d", &opc);
                if(opc < 0 && opc > 14)
                    printf("\nDigite uma opcao valida!\n");
            }while(opc < 0 && opc > 14);

            switch(opc){
                case 0: 
                    bolha(vetor, n);
                    break;
                case 1:
                    bolhaCP(vetor, n);
                    break;
                case 2:
                    insercaoDireta(vetor, n);
                    break;
                case 12:
                    radixSort(vetor, n);
                    break;
            }
}

//roda um numero de algoritmos escolhidos
void numAlgoritmo(int *vetor, int n){
    int numAlg;
    do{
        printf("\nDigite quantos algoritmos deseja rodar (2 - 13): ");
        scanf("%d", &numAlg);
        if(numAlg < 2 || numAlg > 13)
            printf("\nDigite uma opcao valida!\n");
    }while(numAlg < 2 || numAlg > 13);

    printf("\n0 - Bolha\n1 - Bolha com Criterio de Parada\n2 - Insercao Direta\n3 - Insercao Binaria\n4 - Insercao Ternaria\n5 - Shellsort\n6 - Selecao Direta\n7 - Heapsort\n8 - Quicksort Centro\n9 - Quicksort Fim\n10 - Quicksort Mediana\n11 - Mergesort\n12 - Radixsort\n13 - Bucketsort");
    if(numAlg == 1){
            printf("\nEscolha qual algoritmo de ordenacao vai ser utilizado: ");
    }else{
        int *aux = malloc(numAlg * sizeof(int));
        if (aux == NULL) return;

        printf("\nEscolha quais algoritmos de ordenacao vao ser utilizados\n");
        for(int i = 0; i < numAlg; i++){
            printf("%d algoritmo escolhido: ", i + 1);
            scanf("%d", &aux[i]);
        }
        free(aux);
    }
}

//Abre o arquivo e escreve a saida do vetor nele
void escreveSaida(int *vetor, int n, int opc){
    FILE* arquivo;
    arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    for(int i = 0; i < n; i++)
        fprintf(arquivo, "%d\n", vetor[i]);
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
    geraNum(vetor, n);

    //Escolhe quantos algoritmos de ordenacao vao ser utilizados
    do{
        printf("\n0 - Todos os algoritmos\n1 - Um algoritmo\n2 - Um numero de algoritmos\nEscolha como deseja rodar os algoritmos de ordenacao: ");
        scanf("%d", &opc);
        if(opc != 0 && opc != 1 && opc != 2)
            printf("\nDigite uma opcao valida!\n");
    }while(opc != 0 && opc != 1 && opc != 2);

    switch(opc){
        case 0:
            todosAlgoritmos(vetor, n);
        break;
        case 1:
            umAlgoritmo(vetor, n);
        break;
        case 2:
            numAlgoritmo(vetor, n);
        break;
    }

    //Inicio da contagem de tempo
    start = clock();

    //Fim da contagem de tempo
    end = clock();

    printf("\n");
    imprimir(vetor, n);

    escreveSaida(vetor, n, opc);

    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("a");

    //Libera o vetor
    free(vetor);
    return 0;
}