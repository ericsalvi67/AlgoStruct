#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
 int valor;
 struct Lista *prox, *ant;
}Lista;

typedef struct Header{
    Lista *inicio;
    Lista *fim;
    int tamanho;
}Header;

void escreveListas(Lista *inicio){

   Lista *temp = inicio;
   do 
   {
       printf("endereco: %p \n\nanterior: %p \nvalor: %d \nproximo: %p\n\n\n", temp,temp->ant, temp->valor, temp->prox);
       temp = temp->prox;
   }while(temp != inicio);

   printf("\n\n");
}

void insereEricSalvi(Lista **inicio, int valor)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if((*inicio) == NULL)
    {
        *inicio = novo;
        (*inicio)->prox = novo;
        (*inicio)->ant = novo;
        return;
    }
 
    Lista *temp = *inicio;

    while(temp->prox != *inicio)
    {
        temp = temp->prox;
    }

    temp->prox = novo;
    novo->prox = *inicio;
    novo->ant = temp;


}

void escrevenormal(Lista *inicio){

   Lista *temp = inicio;
   do 
   {
       printf("valor: %d \n", temp->valor);
       temp = temp->prox;
   }while(temp != inicio);

   printf("\n\n");
}


void linha()
{
    printf("--------------------------------------------\n");
}

int main()
{
    Lista *inicio = NULL;
    Lista *fim = NULL;

    insereEricSalvi(&inicio, &fim, 1);
    escreveListas(inicio);
    linha();
    insereEricSalvi(&inicio, &fim, 2);
    escreveListas(inicio);
    linha();
    insereEricSalvi(&inicio, &fim, 3);
    escreveListas(inicio);
    linha();
    escrevenormal(inicio);

    free(inicio);
    return 0;
}