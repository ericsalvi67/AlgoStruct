#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* esq;
    struct no* dir;
} No;

No* novoNo(int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}
 // --------------------------------------------------------------------------------
 //ESQUERDA
void posOrdemE(No* a){
  if (a!= NULL){
      posOrdemE(a->esq);
      posOrdemE(a->dir);
      printf("%d ",a->valor);
  }
}

void centralE(No* a){
  if (a!= NULL){
      centralE(a->esq);
      printf("%d ",a->valor);
      centralE(a->dir);
  }
}

void preOrdemE(No* a){
  if (a!= NULL){
      printf("%d ",a->valor);
      preOrdemE(a->esq);
      preOrdemE(a->dir);
  }
}
 // --------------------------------------------------------------------------------
 //DIREITA

 void posOrdemD(No* a){
  if (a!= NULL){
      posOrdemD(a->dir);
      posOrdemD(a->esq);
      printf("%d ",a->valor);
  }
}

void centralD(No* a){
  if (a!= NULL){
      centralD(a->dir);
      printf("%d ",a->valor);
      centralD(a->esq);
  }
}

void preOrdemD(No* a){
  if (a!= NULL){
      printf("%d ",a->valor);
      preOrdemD(a->dir);
      preOrdemD(a->esq);
  }
}
// --------------------------------------------------------------------------------

void insereFolha(No** raiz, int valor){

    if (!*raiz){
        *raiz = novoNo(valor);
        return;
    }
    
    No* aux = *raiz;
    No* pai = NULL;

    while (aux != NULL){
        pai = aux;
        if (valor == aux->valor) {
            printf("Valor ja existe na arvore.\n");
            return;
        }
        if (valor < aux->valor){
            aux = aux->esq;
        }
        else{
            aux = aux->dir;
        }
    }

    if (valor < pai->valor){
        pai->esq = novoNo(valor);
    }
    else{
        pai->dir = novoNo(valor);
    }
}

No* removeFolha(No* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esq = removeFolha(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = removeFolha(raiz->dir, valor);
    } else {
        // Nó encontrado
        if (raiz->esq == NULL && raiz->dir == NULL) {
            // Folha
            free(raiz);
            return NULL;
        } else if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        } else {
            // Dois filhos
            No* sucessor = raiz->dir;
            while (sucessor->esq != NULL) {
                sucessor = sucessor->esq;
            }
            raiz->valor = sucessor->valor;
            raiz->dir = removeFolha(raiz->dir, sucessor->valor);
        }
    }

    return raiz;
}


int pesquisaFolha(No* raiz, int valor) {
    if (raiz != NULL) {
        if(raiz->valor == valor) {
            return 1;
        }
        pesquisaFolha(raiz->esq,valor);
        pesquisaFolha(raiz->dir,valor);
    }
}
// --------------------------------------------------------------------------------
//GERAIS
void folha(No* a){
    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            printf("%d ", a->valor);
        }
        folha(a->dir);
        folha(a->esq);
    }
}

int somaFolhas(No* a) {
    if (a == NULL) return 0;

    if (a->esq == NULL && a->dir == NULL) {
        return a->valor;
    }

    return somaFolhas(a->esq) + somaFolhas(a->dir);
}


// --------------------------------------------------------------------------------
void menu(No** raiz) {
    int opcao;
    int valor;
    char tipo;
    int soma;

    do
    {
        printf("Menu de Opcoes:\n");
        printf("1. Inserir Folha\n");
        printf("2. Remove folha\n");
        printf("3. Pesquisa folha\n");
        printf("4. Pre-ordem\n");
        printf("5. Central\n");
        printf("6. Pos-ordem\n");
        printf("7. Mostra Pre/Central/Pos\n");
        printf("8. Mostra folhas decrescente\n");
        printf("9. Soma das folhas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                insereFolha(raiz, valor);
                break;
            }
            case 2:
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &valor);
                *raiz = removeFolha(*raiz, valor);
                break;
            case 3:
                printf("\nDigite um valor a ser encontrado: ");
                scanf("%d", &valor);
                if(pesquisaFolha(*raiz, valor)) {
                    printf("Valor %d encontrado na arvore.", valor);
                } else {
                    printf("Valor %d nao encontrado na arvore.", valor);
                }
                break;
            case 4:
                printf("\nPre-ordem (E/D): ");
                scanf(" %c", &tipo);
                if(tipo == 'E' || tipo == 'e') {
                    printf("Pre-ordem (Esquerda): ");
                    preOrdemE(*raiz);
                } else if(tipo == 'D' || tipo == 'd') {
                    printf("Pre-ordem (Direita): ");
                    preOrdemD(*raiz);
                } else {
                    printf("Tipo invalido!\n");
                }
                break;
            case 5:
                printf("\nCentral (E/D): ");
                scanf(" %c", &tipo);
                if(tipo == 'E' || tipo == 'e') {
                    printf("Central (Esquerda): ");
                    centralE(*raiz);
                } else if(tipo == 'D' || tipo == 'd') {
                    printf("Central (Direita): ");
                    centralD(*raiz);
                } else {
                    printf("Tipo invalido!\n");
                }
                break;
            case 6:
                printf("\nPos-ordem (E/D): ");
                scanf(" %c", &tipo);
                if(tipo == 'E' || tipo == 'e') {
                    printf("Pos-ordem (Esquerda): ");
                    posOrdemE(*raiz);
                } else if(tipo == 'D' || tipo == 'd') {
                    printf("Pos-ordem (Direita): ");
                    posOrdemD(*raiz);
                } else {
                    printf("Tipo invalido!\n");
                }
                break;
            case 7:
                printf("\nMostra arvore:\n");
                printf("Pre-ordem (Esquerda): ");
                preOrdemE(*raiz);
                printf("\nCentral (Esquerda): ");
                centralE(*raiz);
                printf("\nPos-ordem (Esquerda): ");
                posOrdemE(*raiz);
                printf("\nPre-ordem (Direita): ");
                preOrdemD(*raiz);
                printf("\nCentral (Direita): ");
                centralD(*raiz);
                printf("\nPos-ordem (Direita): ");
                posOrdemD(*raiz);
                break;
            case 8:
                printf("\nFolhas decrescente: ");
                folha(*raiz);
                break;
            case 9:
                printf("\nSoma das folhas: ");
                folha(*raiz);
                soma = somaFolhas(*raiz);
                printf("\nSoma: %d\n", soma);
                break;
            case 0:
                exit(0);
            default:
                printf("\nOpcao invalida!\n");
        }
        printf("\n\n");
    } while (opcao != 0);
}

void dBinsert(No** arvore) {

    insereFolha(arvore, 20);
    insereFolha(arvore, 30);
    insereFolha(arvore, 10);
    insereFolha(arvore, 40);
    insereFolha(arvore, 22);
    insereFolha(arvore, 27);
    insereFolha(arvore, 40);
    insereFolha(arvore, 45);
    insereFolha(arvore, 21);
    insereFolha(arvore, 30);
    insereFolha(arvore, 48);
    insereFolha(arvore, 20);

}

int main(){

    No* arvore = NULL;

    dBinsert(&arvore);
    menu(&arvore);

    return 0;
}