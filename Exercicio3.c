#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
 int info;
 struct elemento *prox;
}Elemento;

Elemento * insert_firstOnly(Elemento *inicio, int valor)
{
    Elemento *novo;
    
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;
    inicio = novo;

    return inicio;
}

Elemento* insert_first(Elemento **inicio, int valor)
{   
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = *inicio;
    *inicio = novo;

    return *inicio;
}

void insert_last(Elemento *inicio, int valor)
{
    Elemento *novo, *aux=inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;
    while (aux->prox!= NULL){
        aux = aux->prox;
    }
    aux->prox = novo;


    return inicio;
}


Elemento *  insert_sorted(Elemento **inicio, int valor)
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

    return *inicio;
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
    Elemento *inicio = NULL;
    inicio =insert_sorted(&inicio,5);
    show_list(&inicio);
    inicio =insert_sorted(&inicio,3);
    inicio =insert_sorted(&inicio,7);
    inicio =insert_sorted(&inicio,1);
    show_list(&inicio);

    inicio = insert_first(&inicio,5);

    free(inicio);
    return 0;
}
