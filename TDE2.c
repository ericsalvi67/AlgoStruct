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
    
    while (aux != NULL && strcmp(aux->name,value) < 0)
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
    printf("------------------------------------------------------------------\n");
    while (aux != NULL)
    {
        printf("%s\n",aux->name);
        aux = aux->prox;
    }
}

NAMES * remove_names(NAMES *actual, char position)
{
    NAMES *aux = actual, *prev = NULL;
    int i=1;

    while (aux != NULL && i != position)
    {
        prev = aux;
        aux = aux->prox;
        i++;
    }
    
    if(position == 1)
    {
        actual = aux->prox;
        free(aux);
    }
    else if(aux->prox == NULL)
    {
        prev->prox = NULL;
        free(aux);
    }
    else
    {
        prev->prox = aux->prox;
        free(aux);
    }

    return actual;
}


int main()
{
    NAMES *actual = NULL;
    
    actual = insert_sorted(&actual,"Joao");
    actual = insert_sorted(&actual,"Paulo");
    show_list(actual);
    actual = insert_sorted(&actual,"Eric");
    actual = insert_sorted(&actual,"Ana");
    show_list(actual);
    actual = remove_names(actual,4);
    show_list(actual);
    
    
    return  0;
}
