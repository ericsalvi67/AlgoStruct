#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noA{
    int info;
    struct noA *esq;
    struct noA *dir;
} TNoA;


 // --------------------------------------------------------------------------------
 //ESQUERDA
void posOrdemE(TNoA* a){
  if (a!= NULL){
      posOrdemE(a->esq);
      posOrdemE(a->dir);
      printf("%d ",a->info);
  }
}

void centralE(TNoA* a){
  if (a!= NULL){
      centralE(a->esq);
      printf("%d ",a->info);
      centralE(a->dir);
  }
}

void preOrdemE(TNoA* a){
  if (a!= NULL){
      printf("%d ",a->info);
      preOrdemE(a->esq);
      preOrdemE(a->dir);
  }
}
 // --------------------------------------------------------------------------------
 //DIREITA

 // --------------------------------------------------------------------------------
 //GERAIS
void folha(TNoA* a){
    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            printf("%d ", a->info);
        }
        folha(a->esq);
        folha(a->dir);
    }
}
TNoA *criaNo(int d) {
  TNoA *novo;
  novo = (TNoA *) malloc(sizeof(TNoA));
  novo->info = d;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo(1);
    raiz->esq = criaNo(3);
    raiz->esq->esq = criaNo(4);
    raiz->esq->dir = criaNo(5);
    raiz->dir = criaNo(6);
    raiz->dir->esq = criaNo(7);
    raiz->dir->esq->dir = criaNo(2);

    preOrdemE(raiz);
    printf("\n");
    centralE(raiz);
    printf("\n");
    posOrdemE(raiz);
    printf("\n");
    folha(raiz);
    free(raiz);
};