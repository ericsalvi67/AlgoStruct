//Implementar a operação de inversão de uma lista encadeada simples (inverter sem criar uma segunda lista).

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
 int info;
 struct elemento *prox;
}Elemento;

Elemento* insert_first(Elemento **inicio, int valor)
{   

    if((*inicio)->prox != *inicio)
    {
        *inicio = (Elemento*) malloc(sizeof(Elemento));
        (*inicio)->info = valor;
        (*inicio)->prox = *inicio;
    }
    else 
    {
        Elemento *novo;
        novo = (Elemento*) malloc(sizeof(Elemento));
        novo->info = valor;
        novo->prox = *inicio;
        *inicio = novo;
    }
    
    return *inicio;
}


void escreveListas(Elemento *inicio){

   Elemento *temp = inicio;
   do 
   {
       printf("endereco: %p valor: %d proximo: %p\n\n\n", temp, temp->info, temp->prox);
       temp = temp->prox;
   }while(temp != inicio);

   printf("\n\n");
}

int main()
{
    Elemento *inicio = NULL;

    inicio = insert_first(&inicio, 5);
    inicio = insert_first(&inicio, 7);
    inicio = insert_first(&inicio, 3);
    inicio = insert_first(&inicio, 16);
    inicio = insert_first(&inicio, 4);
    inicio = insert_first(&inicio, 9);
    inicio = insert_first(&inicio, 1);
    escreveListas(inicio);

    free(inicio);
    return 0;   

}