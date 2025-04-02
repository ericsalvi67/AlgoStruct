#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
 int valor;
 struct Lista *prox;
}Lista;

void escreveListas(Lista *inicio){

   Lista *temp = inicio;
   do 
   {
       printf("endereco: %p valor: %d proximo: %p\n\n", temp, temp->valor, temp->prox);
       temp = temp->prox;
   }while(temp != inicio);

   printf("\n\n");
}

void insereEricSalvi(Lista **inicio, int valor)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->valor = valor;
    novo->prox = NULL;

    if((*inicio) == NULL)
    {
        *inicio = novo;
        (*inicio)->prox = novo;
        return;
    }
 
    Lista *temp = *inicio;

    while(temp->prox != *inicio)
    {
        temp = temp->prox;
    }

    temp->prox = novo;
    novo->prox = *inicio;

}

int main()
{
    Lista *inicio = NULL;
    insereEricSalvi(&inicio,1);
    insereEricSalvi(&inicio,2);
    insereEricSalvi(&inicio,3);
    escreveListas(inicio);

    free(inicio);
    return 0;
}