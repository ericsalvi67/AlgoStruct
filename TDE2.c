#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lib_name{
    char name[20];
    struct lib_name *prox;
}NAMES;

NAMES * insert_sorted(NAMES **actual, char *value)
{
    NAMES *new, *aux = *actual, *prev = NULL;
    
    new = (NAMES*) malloc(sizeof(NAMES));
    
    strcpy(new->name,value);
    
    while (aux != NULL && strcmp(aux->name,value))
    {
        prev = aux;
        aux = aux->prox;
    }
    if (prev == NULL)
    {
        new->prox = *actual;
        *actual = new;
    }
    else
    {
        new->prox = prev->prox;
        prev->prox = new;
    }
    
    return *actual;
}


void show_list(NAMES *actual)
{
    NAMES *aux = actual;
    while (aux != NULL)
    {
        printf("%s\n",aux->name);
        aux = aux->prox;
    }
}


int main()
{
    NAMES *actual = NULL;
    
    actual = insert_sorted(&actual,"Joao");
    actual = insert_sorted(&actual,"Paulo");
    show_list(actual);
    actual = insert_sorted(&actual,"Eric");
    show_list(actual);
    
    return  0;
}
