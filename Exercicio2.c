#include <stdio.h>
#include <stdlib.h>

struct elemento {
 int info;
 struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

void insere_inicio(int valor)
{
    Elemento *novo;
    Elemento *aux = inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = 5;
    novo->prox = NULL;
    inicio = novo;

    if(inicio != NULL) novo -> prox = inicio;
    inicio = novo;


    while (aux != NULL)
    {
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
    
}

int main()
{
    inicio = NULL;
}