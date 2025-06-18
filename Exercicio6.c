#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    float nota;
    struct fila *prox;
}Fila;

typedef struct lista {
 int nro;
  Fila *inicio, *fim;
  struct lista *prox;
}Lista;

void insereinicio(Lista **inicio,int n)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->nro = n;
    novo->prox = NULL;
    novo->inicio = NULL;
    novo->fim = NULL;

    if(*inicio == NULL)
    {
        *inicio = novo;
        return;
    }
    novo->prox = *inicio;
    *inicio = novo;
    return;

}

void escreveLista(Lista *inicio)
{
    Lista *temp = inicio;
    printf("\nLista:\n");
    while(temp != NULL)
    {
        printf("Endereco: %p Valor: %d Proximo: %p\n", temp, temp->nro, temp->prox);
        temp = temp->prox;
    }
    printf("-----------------------------------------------\n");
}

void escreveFila(Fila *inicio)
{
    Fila *temp = inicio;
    printf("\nFila:\n");
    while(temp != NULL)
    {
        printf("Endereco: %p Valor: %.2f Proximo: %p\n", temp, temp->nota, temp->prox);
        temp = temp->prox;
    }
    printf("-----------------------------------------------\n");
}

void enfileira(Lista **nodo, float n)
{
    Fila *aux;
    Fila *novo = (Fila*) malloc(sizeof(Fila));
    novo->nota = n;
    novo->prox = NULL;

    if((*nodo)->fim == NULL) // enfileira o primeiro e unico
    {
        (*nodo)->fim = novo;
        (*nodo)->inicio = novo;
        return;
    }  
    aux = (*nodo)->fim;
    aux->prox = novo;
    (*nodo)->fim = novo;
    return;
}

float desenfileira(Lista **nodo){
    Fila *aux;
    aux=(*nodo)->inicio;
    (*nodo)->inicio=aux->prox;
    free(aux);
    }

void desenfileira(Fila **nodo) /// nao funciona (testar)
{
    Fila *temp = *nodo;

    if(temp == NULL)
    {
        printf("Fila vazia\n");
        return;
    }

    while (temp->prox != NULL)
    {
        temp = temp->prox;
    }

    free(temp);    
    return;
}

int main()
{
    Lista *inicio = NULL;
    Lista *aux;

    insereinicio(&inicio, 1);
    insereinicio(&inicio, 2);
    insereinicio(&inicio, 3);
    escreveLista(inicio);
    //enfileira fila 1 
    aux = inicio; // Initialize aux to the start of the list
    while (aux != NULL && aux->nro != 1) // Add a NULL check to avoid segmentation fault
    {
        aux = aux->prox;
    }
    enfileira(&aux, 8.5);
    enfileira(&aux, 9.5);
    enfileira(&aux, 10.0);
    escreveFila(aux->inicio);
    desenfileira(&aux->inicio);
    escreveFila(aux->inicio);


    
}