#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>

//Estrutura dos dados da pilha
typedef struct
{
    int tamanho;
    int fim;
    int inicio;
    int quantidadeElementos;
    int *vetor;
} FilaVetor;

//Mostrar os dados da Struct
void mostrarDados(FilaVetor const * const fila)
{
    printf("\n*********Dados da Fila*********\n");
    printf("Tamanho: %d\n", fila->tamanho);
    printf("Fim: %d\n", fila->fim);
    printf("Inicio: %d\n", fila->inicio);
    printf("Quantidade de Elementos: %d\n\n", fila->quantidadeElementos);
}

//Criar e inicializar a fila
void criarFila(int tamanho, FilaVetor * const fila)
{
    if(tamanho <= 0)
    {
        printf("O tamanho não pode ser <= 0");
        return;
    }
    fila->fim = -1;
    fila->inicio = -1;
    fila->quantidadeElementos = 0;
    fila->vetor = malloc(tamanho * sizeof(int));
    if(fila->vetor == NULL)
    {
        printf("Erro de criação da fila");
        fila->tamanho = 0;
    }
    fila->tamanho = tamanho;
}

//Liberar o espaço de memória da fila
void liberarFila(FilaVetor * const fila)
{
    free(fila->vetor);

}

//Verificar se a fila esta cheia
int verificarFilaCheia(FilaVetor const * const fila)
{
    return (fila->quantidadeElementos == fila->tamanho);
}

//Verificar se a fila esta vazia
int verificarFilaVazia(FilaVetor const * const fila)
{
    return (fila->quantidadeElementos == fila->tamanho);
}

//Acessar um elemento na fila
int acessarFila(FilaVetor const * const fila)
{
    if(verificarFilaVazia(fila))
    {
        printf("A fila esta vazia\n");
        exit(0);
    }
    return *(fila->vetor + fila->inicio);
}

// Enfileirar elemento na fila
void enfileirar(int elemento, FilaVetor *const fila)
{
    if(verificarFilaCheia(fila))
    {
        printf("A fila esta cheia\n");
        exit(0);
    }
    fila->fim++;
    if(fila->fim == fila->tamanho) fila->fim = 0;
    if(verificarFilaVazia(fila)) fila->inicio++;
    *(fila->vetor + fila->fim) = elemento;
    fila->quantidadeElementos++;

}

//Desenfileirar elemento da fila
void desenfileirar(FilaVetor *const fila)
{
    if(verificarFilaVazia(fila))
    {
        printf("A fila esta vazia\n");
        exit(0);
    }
    fila->inicio++;
    if(fila->inicio == fila->tamanho) fila->inicio = 0;
    fila->quantidadeElementos--;
    if(fila->inicio > fila->fim)
    {
        fila->quantidadeElementos = 0;
        fila->inicio = -1;
    }
}



#endif // FILA_H
