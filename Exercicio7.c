#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10


void retorna_vetor(int vetor[], int n)
{
    int i = 0;
    int valor;

    printf("Gerando vetor...\n");
    do
    {
        valor = rand() % 10*i;

        if (i == 0)
        {
            vetor[i] = valor;
            i++;
        }
        else if(valor > vetor[i-1])
        {
            vetor[i] = valor;
            i++;
        }
    }while (i < n);
    printf("Vetor gerado com sucesso!\n");
}

void mostra_vetor(int vetor[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int PesquisaBinaria (int vet[], int chave, int Tam)
{
    int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
    int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
    int meio;
    int i = 1;
    
    while (inf <= sup)
    {
        meio = (inf + sup)/2;
        if (chave == vet[meio])
        {
            printf("Numero de iteracoes: %d\n", i);
            return vet[meio];
        }
        if (chave < vet[meio])
            sup = meio-1;
        else
            inf = meio+1;
    i++;
    }

    printf("Numero de iteracoes: %d\n", i);
    return -1;   // não encontrado
}



int main()
{
    srand(time(NULL));
    int v[N];
    int valor;

    retorna_vetor(v, N);
    mostra_vetor(v, N);


    printf("Digite o valor a ser pesquisado: ");
    scanf("%d", &valor);

    int resultado = PesquisaBinaria(v, valor, N);
    printf("Resultado: %d\n", resultado);
}