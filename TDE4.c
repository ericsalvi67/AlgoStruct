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
void posOrdemD(TNoA* a){
  if (a!= NULL){
    posOrdemD(a->dir);
    posOrdemD(a->esq);
    printf("%d ",a->info);
  }
}

void centralD(TNoA* a){
  if (a!= NULL){
    centralD(a->dir);
    printf("%d ",a->info);
    centralD(a->esq);
  }
}

void preOrdemD(TNoA* a){
  if (a!= NULL){
    printf("%d ",a->info);
    preOrdemD(a->dir);
    preOrdemD(a->esq);
    }
}

 // --------------------------------------------------------------------------------
 //GERAIS
void folhas(TNoA* a){
    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            printf("%d ", a->info);
        }
        folhas(a->esq);
        folhas(a->dir);
    }
}

void somaFolhas(TNoA* a, int* soma){
    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            soma = soma + a->info;
        }
        folhas(a->esq);
        folhas(a->dir);
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

void criaArvore(TNoA *raiz) 
{
    int valor;
    TNoA *aux;

    printf("Digite o valor do NO: ");
    scanf("%d", &valor);

    if (raiz == NULL)
        raiz = criaNo(valor);
    else {
        aux = raiz;
        while(aux != NULL)
        {
            if (valor < aux->info) {
                if (aux->esq == NULL) {
                    aux->esq = criaNo(valor);
                    return;
                } else {
                    aux = aux->esq;
                }
            } else {
                if (aux->dir == NULL) {
                    aux->dir = criaNo(valor);
                    return;
                } else {
                    aux = aux->dir;
                }
            }
        }
    }

    raiz = aux;
}

int main(void) 
{
    TNoA *raiz;
    int* soma;

    criaArvore(raiz);
    printf("Arvore criada com sucesso!\n");
    criaArvore(raiz);
    criaArvore(raiz);

    preOrdemE(raiz);
    printf("\n");
    centralE(raiz);
    printf("\n");
    posOrdemE(raiz);
    printf("\n");
    folhas(raiz);
    somaFolhas(raiz, soma);
    printf("\nSoma das folhas: %d\n", soma);
    free(raiz);
};