/* Uma palíndrome é um texto (ou palavra) que pode ser lido da esquerda para a direita ou da direita para a esquerda, produzindo o mesmo resultado (ou o mesmo texto). 
Por exemplo: "arara", "amor e roma", "ele", "1234554321". 

a) Considere que um texto está armazenado em uma lista duplamente encadeada, na qual cada nodo contém um caractere. 
Implemente uma função (em C, C#, C++, Java, Python) que verifique se o texto armazenado é uma palíndrome ou não, retornando 0 se o texto não for palíndrome e 1 se for palíndrome.

b) Defina um header (cabeçalho) para a lista que armazena a quantidade de caracteres do texto (e opcionalmente) a quantidade de palavras do texto. 
Considere outras operações que poderiam ser executadas sobre o texto para definir o conteúdo do header.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
 char letra;
 struct Lista *prox, *ant;
}Lista;

typedef struct Header{
    Lista *inicio;
    Lista *fim;
    int tamanho;
    int palavras;
}Header;

void inseresequencial(Header *h, char letra)
{
   Lista *novo = (Lista*) malloc(sizeof(Lista));
   novo->letra = letra;
   novo->prox = NULL;
   novo->ant = NULL;

   if(h->inicio == NULL)
   {
      h->inicio = novo;
      (h->inicio)->prox = novo;
      (h->inicio)->ant = novo;
      h->fim = novo;
      h->tamanho++;
      return;
   }

   Lista *temp = h->inicio;
   while(temp->prox != h->inicio)
   {
      temp = temp->prox;
   }
   temp->prox = novo;
   novo->prox = h->inicio;
   novo->ant = temp;
   (h->inicio)->ant = novo;
   h->fim = novo;
   h->tamanho++;
}

void mostraLista(Header *h)
{
   Lista *temp = h->inicio;
   do 
   {
      printf("endereco: %p\tanterior: %p\tvalor: %c\tproximo: %p\t\n", temp,temp->ant, temp->letra, temp->prox);
      temp = temp->prox;
   }while(temp != (h->fim)->prox);
   printf("\n\n");
}

void mostraListaInversa(Header *h)
{
   Lista *temp = h->fim;
   do 
   {
      printf("endereco: %p\tanterior: %p\tvalor: %c\tproximo: %p\t\n", temp,temp->ant, temp->letra, temp->prox);
      temp = temp->ant;
   }while(temp != (h->inicio)->ant);
   printf("\n\n");
}


int ehpalindrome(Header *h)
{
   Header *temp = h;
   int i ;

   if(h->inicio == NULL) return 0;
   if(h->tamanho < 2) return 0;
   
   for(i=0; i<h->tamanho; i++)
   {
      if((temp->inicio)->letra != (temp->fim)->letra)
      {
         return 0;
      }

      temp->inicio = (temp->inicio)->prox;
      temp->fim = (temp->fim)->ant;
   }

   return 1;
}

void verificaPalindrome(int x)
{
   if (!x)
   {
      printf("Nao eh palindromo!\n");
      return;
   }

   printf("Eh palindromo!\n");
   return;
}

void montastring(Header *h)
{
   char string[50];
   int i;
   
   do
   {
      printf("Digite uma palavra: ");
      gets(string);
   } while (string[0] == '\0');

   printf("String: %s\n", string);

   for(i = 0; string[i] != '\0'; i++)
   {
      inseresequencial(h, string[i]);

      if (string[i] == ' ')
      {
         h->palavras++;
      }
   }
}

int main()
{
   Header h;
   h.inicio = NULL;
   h.fim = NULL;
   h.tamanho = 0;
   h.palavras = 1;

   montastring(&h);
   mostraListaInversa(&h);
   mostraLista(&h);

   printf("Tamanho: %d\n", h.tamanho);
   printf("Palavras: %d\n", h.palavras);

   verificaPalindrome(ehpalindrome(&h));

   //remomeletra(&h, 1);



   free(h.inicio);
   free(h.fim);
}