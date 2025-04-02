#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
 int info;
 struct elemento *prox;
}Elemento;

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

void invert_list(Elemento **inicio)
{
    Elemento *aux = *inicio;
    Elemento *temp = NULL;
    *inicio = (*inicio)->prox;
    aux->prox = NULL;

    while (inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->prox;
        temp->prox = aux;
        aux = temp;
    }
    *inicio = aux;
    
}

void lst_imprime_rec (Elemento* lst)
{
    //recursividade com exibicao normal
    // if ( !lst == NULL ) 
    // {
    //     printf("info: %d\n",lst->info);
    //     lst_imprime_rec(lst->prox);
        
    // }

    //recursividade com exibicao inversa
    if ( !lst == NULL ) 
    {
        lst_imprime_rec(lst->prox);
        printf("info: %d\n",lst->info);
    }
}


int main()
{
    Elemento *inicio = NULL;
    inicio = insert_sorted(&inicio,1);
    inicio = insert_sorted(&inicio,2);
    inicio = insert_sorted(&inicio,3);
    //show_list(&inicio);
    // invert_list(&inicio);
    // show_list(inicio);
    lst_imprime_rec(inicio);

    free(inicio);
    return 0;
}