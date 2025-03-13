#include <stdio.h>

#define t 10

typedef struct
{
    int num;
    char nome[20];   
}NOME;

void add_nome_inicio(NOME *v, int tam)
{
    int i;
    
    if(v[0].num == 0)
    {
        printf("Digite o numero: ");
        scanf("%d",&v[0].num);
        printf("Digite o nome: ");
        scanf("%s",v[0].nome);
    }
    else
    {
        for(i=tam;i>=0;i--)
        {
            v[i] = v[i-1];

        }
        printf("Digite o numero: ");
        scanf("%d",&v[0].num);
        printf("Digite o nome: ");
        scanf("%s",v[0].nome);
    }
}

void inverte_lista(NOME *v,int tam)
{
    int i,j;
    NOME aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=0;j<tam-1-i;j++)
        {
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
    
}

void insere_ordenado(NOME *v, int tam)
{
    int i,j;
    NOME aux;

    printf("Digite o numero: ");
    scanf("%d",&aux.num);
    printf("Digite o nome: ");
    scanf("%s",aux.nome);

    for(i=0;i<tam;i++)
    {
      if(v[i].num >= aux.num)
      {
          for(j=tam;j>i;j--)
          {
              v[j] = v[j-1];
          }
          v[i] = aux;
          return;
      }
    }
}

void insere_recursivo(NOME *v, int tam,int pos)
{
    if(pos == tam) return;

    if(v[pos].num == 0)
    {
        printf("Digite o numero: ");
        scanf("%d",&v[pos].num);
        printf("Digite o nome: ");
        scanf("%s",v[pos].nome);   
    }

    pos++;
    insere_recursivo(v,tam,pos);

}

void clear_vet(NOME *v, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        v[i].num = i;
        v[i].nome[0] = '\0';
    }
}

void mostra_vet(NOME *v, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Numero: %d\n",v[i].num);
        printf("Nome: %s\n",v[i].nome);
    }
}


int main()
{
    NOME v[t];
    int op;

    clear_vet(v,t);

    do
    {
        printf("Escolha uma opcao: \n");
        printf("1 - Adicionar no inicio\n");
        printf("2 - Inverter a lista\n");
        printf("3 - Inserir ordenado\n");
        printf("4 - Inserir recursivo\n");
        printf("5 - Limpar vetor\n");
        printf("6 - Sair\n");
        scanf("%d",&op);


        switch (op)
        {
        case 1:
            add_nome_inicio(v,t); //funciona
            break;
        case 2:
            inverte_lista(v,t); //funciona
            break;
        case 3:
            insere_ordenado(v,t); //funciona
            break;
        case 4:
            insere_recursivo(v,t,0); //funciona
            break;
        case 5: 
            clear_vet(v,t); //funciona
            break;
        }
        if(op != 6) mostra_vet(v,t); //funciona
    } while (op!=6);

}