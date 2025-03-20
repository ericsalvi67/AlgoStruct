#include <stdio.h>
#include <stdlib.h>


typedef struct elemento {
 int info;
 struct elemento *prox;
}Elemento;

void insert_firstOnly(Elemento **inicio, int valor)
{
    Elemento *novo;
    *inicio = NULL;
    
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;
    inicio = novo;
}

Elemento* insert_first(Elemento **inicio, int valor)
{   
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = *inicio;
    *inicio = novo;
}

void insert_last(Elemento **inicio, int valor)
{
    Elemento *novo, *aux=*inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;
    while (aux->prox!= NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}


void  insert_sorted(Elemento **inicio, int valor)
{
    Elemento *novo, *aux = *inicio, *ant = NULL;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    while (aux != NULL && aux->info < valor)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (ant == NULL)
    {
        novo->prox = *inicio;
        *inicio = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

void show_list(Elemento *inicio)
{
    Elemento *aux = inicio;
    while (aux != NULL)
    {
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
}


int main()
{
    Elemento *inicio; 
    inicio = NULL;
    insert_sorted(&inicio, 5);
    show_list(&inicio);
    insert_sorted(&inicio, 3);
    insert_sorted(&inicio, 7);
    insert_sorted(&inicio, 1);

    inicio = insert_first(inicio, 5);

    free(inicio);
    return 0;
}
