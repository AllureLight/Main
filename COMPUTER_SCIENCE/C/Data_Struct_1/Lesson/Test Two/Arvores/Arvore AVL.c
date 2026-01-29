#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    int fatBal;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore* criarArvoreVazia(){
    return NULL;
}

int estaVazia(Arvore *arv){
    return(arv==NULL);
}

void rotacaoLR(Arvore** l){
    Arvore* temp;
    int fat = (*l)->fatBal;
    temp = (*l);
    (*l) = temp->dir;
    temp->dir = (*l)->esq;
    (*l)->esq = temp;
    if(fat == 2){
        if((*l)->fatBal == 1){
            (*l)->fatBal = 0;
            temp->fatBal = 0;
        }
        else{
            (*l)->fatBal = -1;
            temp->fatBal = 1;
        }
    }
    else{
        if((*l)->fatBal == 0){
            (*l)->fatBal = -1;
            temp->fatBal = 0;
        }
        else{
            (*l)->fatBal = 0;
            temp->fatBal = 0;
        }
    }
}

void rotacaoRR(Arvore** l){
    Arvore* temp;
    int fat = (*l)->fatBal;
    temp = (*l);
    (*l) = temp->esq;
    temp->esq = (*l)->dir;
    (*l)->dir = temp;
    if(fat == -2){
        if((*l)->fatBal == -1){
            (*l)->fatBal = 0;
            temp->fatBal = 0;
        }
        else{
            (*l)->fatBal = 1;
            temp->fatBal = -1;
        }
    }
    else{
        if((*l)->fatBal == 0){
            (*l)->fatBal = 1;
            temp->fatBal = 0;
        }
        else{
            (*l)->fatBal = 0;
            temp->fatBal = 0;
        }
    }
}// dar uma olhada

int insere (Arvore** l,int c){
    Arvore* novo;
    int cresceu, retorno;
    if((*l)==NULL)/*mesma coisa que ver se ta vazia*/{
        novo = (Arvore*)malloc(sizeof(Arvore));
        novo->info = c;
        novo->esq = novo->dir = NULL;
        novo->fatBal = 0;
        (*l) = novo;
        retorno = 1; 
    }
    else if(c<(*l)->info){
        cresceu = insere(&(*l)->esq, c);
        retorno = 0;
        if(cresceu){
            (*l)->fatBal--;
            if((*l)->fatBal == -2){
                if((*l)->esq->fatBal == -1){
                    rotacaoRR(&(*l));
                }
                else{
                    rotacaoLR(&(*l)->esq);
                    rotacaoRR(&(*l));
                }
            }
            else{
                if((*l)->fatBal != 0){
                    retorno = 1;
                }
            }
        }   
    }
    else{
        cresceu = (&(*l)->dir, c);
        retorno = 0;
        if(cresceu){
            (*l)->fatBal++;
            if(&(*l)->fatBal == 2){
                if((*l)->dir->fatBal == 1){
                rotacaoLR(&(*l));
                }
                else{
                    rotacaoRR(&(*l)->dir);
                    rotacaoLR(&(*l));
                }
            }
            else{
                if((*l)->fatBal != 0){
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

int antecessor(Arvore** l, int* cand){
    Arvore* temp;
    int retorno, diminuiu;
    if((*l)->dir == NULL){
        *cand = (*l)->info;
        temp = (*l);
        (*l)=(*l)->esq;
        free(temp);
        retorno = 1;
    }
    else{
        diminuiu = antecessor(&(*l)->dir, cand);
        if(diminuiu){
            (*l)->fatBal--;
            if((*l)->fatBal == -2){
                if((*l)->esq->fatBal == -1){
                    rotacaoRR(&(*l));
                }
                else{
                    rotacaoLR(&(*l)->esq);
                    rotacaoRR(&(*l));
                }
                retorno = 1;
            }
            else{
                if((*l)->fatBal == 0){
                    retorno = 1;
                }
                else
                    retorno = 0;
            }
        }
    }
    return retorno;
}

remover(Arvore** l, int c){
    int retorno, diminuiu;
    if((*l)!=NULL){
        if(c==(*l)->info){
            if((*l)->esq!=NULL)
            diminuiu = antecessor(&(*l)->esq, &(*l)->info);
            if(diminuiu){
                (*l)->fatBal++;
                if(&(*l)->fatBal == 2){
                    if((*l)->dir->fatBal == 1){
                        rotacaoLR(&(*l));
                    }
                    else{
                        rotacaoRR(&(*l)->dir);
                        rotacaoLR(&(*l));
                    }
                    retorno = 1;
                }
                else{
                    if((*l)->fatBal == 0)
                        retorno = 1;
                    else
                        retorno = 0;
                }
            }
        }
        else{
            Arvore* temp = (*l);
            (*l) = (*l)->dir;
            free(temp);
            retorno = 1;
        }
    }
    else if(c < (*l)->info){
        diminuiu = remover(&(*l)->esq, c);
        if(diminuiu){
            (*l)->fatBal++;
            if(&(*l)->fatBal == 2){
                if((*l)->dir->fatBal == 1){
                    rotacaoLR(&(*l));
                }
                else{
                    rotacaoRR(&(*l)->dir);
                    rotacaoLR(&(*l));
                }
                retorno = 1;
            }
            else{
                if((*l)->fatBal == 0)
                    retorno = 1;
                else
                    retorno = 0;
            }
        }
    }
    else{
        diminuiu = remover(&(*l)->dir, c);
        if(diminuiu){
            (*l)->fatBal--;
            if(&(*l)->fatBal == -2){
                if((*l)->dir->fatBal == -1){
                    rotacaoRR(&(*l));
                }
                else{
                    rotacaoLR(&(*l)->esq);
                    rotacaoRR(&(*l));
                }
                retorno = 1;
            }
            else{
                if((*l)->fatBal == 0)
                    retorno = 1;
                else
                    retorno = 0;
            }
        }
    }
    return retorno;
}

int main(){

}