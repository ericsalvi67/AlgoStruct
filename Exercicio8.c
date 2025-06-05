#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noA{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

void posOrdem(TNoA* a){
  if (a!= NULL){
      posOrdem(a->esq);
      posOrdem(a->dir);
      printf("%c ",a->info);
  }
}

void central(TNoA* a){
  if (a!= NULL){
      central(a->esq);
      printf("%c ",a->info);
      central(a->dir);
  }
}

void preOrdem(TNoA* a){
  if (a!= NULL){
      printf("%c ",a->info);
      preOrdem(a->esq);
      preOrdem(a->dir);
  }
}

void folha(TNoA* a){
    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            printf("%c ", a->info);
        }
        folha(a->esq);
        folha(a->dir);
    }
}


TNoA *criaNo(char ch) {
  TNoA *novo;
  novo = (TNoA *) malloc(sizeof(TNoA));
  novo->info = ch;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->esq->esq = criaNo('D');
    raiz->esq->dir = criaNo('E');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('F');
    raiz->dir->esq->dir = criaNo('G');

    preOrdem(raiz);
    printf("\n");
    central(raiz);
    printf("\n");
    posOrdem(raiz);
    printf("\n");
    folha(raiz);
    free(raiz);
};