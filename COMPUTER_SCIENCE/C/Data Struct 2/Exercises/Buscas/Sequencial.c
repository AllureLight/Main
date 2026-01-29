#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarArquivo(int *arquivo){
    int opc;
    
    printf("\n0 - Usando valores aleatorios\n");
    printf("1 - Preencher com valores escolhidos\n");
    printf("Como deseja criar o arquivo: ");
    scanf("%d", &opc);
    
    if(opc == 0){
        srand(time(NULL));
        for(int i = 0; i<10; i++)
            arquivo[i] = rand() % 100;
        printf("\n");
    }else if(opc == 1){
        printf("\nDigite um valor a ser inserido no Arquivo: ");
        scanf("%d", &arquivo[0]);
        
        for(int i = 1; i<10; i++){
            printf("Digite um valor a ser inserido no Arquivo: ");
            scanf("%d", &arquivo[i]);
        }
        printf("\n");
    }else{
        printf("Valor invalido!\n");
        criarArquivo(&arquivo[0]);
    }
}

void imprimirArquivo(int *arquivo){
    printf("\nOs valores no arquivo sao:\n");
    for(int i = 0; i<10; i++){
        printf("%d ", arquivo[i]);
    }
    printf("\n\n");
}

void procurarChave(int *arquivo){
    int chave, cont = 0, ind[10];
    
    printf("\ninsira a chave a ser procurada: ");
    scanf("%d", &chave);
    
    for(int i = 0; i<10; i++){
        if(chave == arquivo[i]){
            ind[cont] = i;
            cont++;
        }
    }
    
    if(cont >1)
        printf("\nForam encontradas %d chaves\nNos indices: ", cont);
    else
        printf("\nFoi encontrada %d chave\nNo indice: ", cont);
    
    for(int i = 0; i<cont; i++){
            printf("%d ", ind[i]);
    }
    printf("\n\n");
}

void main() {
    int opc, arquivo[10];
    
    do{
        printf("0 - Criar Arquivo\n");
        printf("1 - Imprimir o Arquivo\n");
        printf("2 - Procurar uma chave\n");
        printf("3 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opc);
        
        switch(opc){
            case 0: 
                criarArquivo(&arquivo[0]);
                break;
            case 1: 
                imprimirArquivo(&arquivo[0]);
                break;
            case 2: 
                procurarChave(&arquivo[0]);
                break;
            case 3:
                break;
            default: 
                printf("Insira um valor valido!");
                break;
        }
    }while(opc !=3);
    printf("Programa Finalizado!");
}