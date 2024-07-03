#ifndef LLSE_H
#define LLSE_H
// Inclusão de Biblioteca
#include <stdlib.h>
#include <stdio.h>
// Estrutura de dados No - LLSE
typedef struct{
    int dado;
    struct No *proximo;
}No;
// Estrutura de dados LLSE
typedef struct{
    No *inicio;
    int quantidadeDeElementos;
}LLSE;
/********************************************************
 * Funcoes para a Lista Linear Simplesmente Encadeada
 * *****************************************************/
// Inicializar a estrutura de dados NO
void incializarNo(No * const ptNo, int elemento){
    ptNo->dado = elemento;
    ptNo->proximo = NULL;
}
// Inicializar a estrutura de dados LLSE
void inicializarLLSE(LLSE * const ptLLSE){
    ptLLSE->inicio = NULL;
    ptLLSE->quantidadeDeElementos = 0;
}
// Verificar se a LLSE esta vazia
int verificarLLSEVazia(LLSE const * const lista){
    return (lista->quantidadeDeElementos == 0);
}
// Inserir Nos no inicio LLSE
void inserirInicioLLSE(LLSE * const lista, int elemento){
    No *ptAux = (No*) malloc(sizeof(No));
    incializarNo(ptAux,elemento);
    ptAux->proximo = lista->inicio;
    lista->inicio = ptAux;
    lista->quantidadeDeElementos++;
}
// Acessar Inicio Nos no inicio LLSE
int acessarInicioLLSE(LLSE const * const lista){
    if(verificarLLSEVazia(lista)){
        printf("\n LISTA ESTA VAZIA\n");
        return 0;
    }
    return lista->inicio->dado;
}
// Retirar Inicio Nos no inicio LLSE
int retirarInicioLLSE(LLSE * const lista){
    if(verificarLLSEVazia(lista)){
        printf("\n LISTA ESTA VAZIA\n");
        return 0;
    }
    int valor = lista->inicio->dado;
    No *ptAux = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->quantidadeDeElementos--;
    free(ptAux);
    return valor;
}

// Inserir Nos no fim LLSE
void inserirFimLLSE(LLSE * const lista, int elemento){
    No *ptAux = (No*) malloc(sizeof(No));
    incializarNo(ptAux,elemento);
    if(verificarLLSEVazia(lista)){
        lista->inicio = ptAux;
        lista->quantidadeDeElementos++;
        return;
    }
       No *ptAux2 = lista->inicio;
       while(ptAux2->proximo != NULL){
        ptAux2=ptAux2->proximo;
       }

        ptAux2->proximo=ptAux;
        lista->quantidadeDeElementos++;

}

// Acessar Nos no inicio da LLSE
int acessarFimLLSE(LLSE const * const lista)
{
    if(verificarLLSEVazia(lista)){
        printf("\n LISTA ESTA VAZIA\n");
        return 0;
    }
    No *ptAux = lista->inicio;
    while(ptAux->proximo != NULL)
    {
        ptAux = ptAux->proximo;
    }
    return ptAux->dado;
}

// Retirar Nos no fim da LLSE
void retirarFimLLSE(LLSE * const lista)
{
    if(verificarLLSEVazia(lista)){
        printf("\n LISTA ESTA VAZIA\n");
        exit(0);
    }
    No *ptAtual = lista->inicio;
    No *ptAnterior = lista->inicio;
    while(ptAtual->proximo != NULL)
    {
        ptAnterior = ptAtual;
        ptAtual = ptAtual->proximo;
    }
    lista->quantidadeDeElementos--;

    if(lista->quantidadeDeElementos == 0)
    {
        free(lista->inicio);
        lista->inicio = 0;
        return;
    }
    free(ptAtual);
    ptAnterior->proximo = NULL;
    return;
}

void inserirOrdenadoLLSE(LLSE * const lista, int elemento)
{
    No *ptAux = (No*) malloc(sizeof(No));
    incializarNo(ptAux,elemento);
    if(verificarLLSEVazia(lista)){
        lista->inicio = ptAux;
        lista->quantidadeDeElementos++;
        return;
    }

    if(ptAux->dado <= lista->inicio->dado)
    {
        ptAux->proximo = lista->inicio;
        lista->inicio = ptAux;
        lista->quantidadeDeElementos++;
        return;
    }
    No *ptAnterior = lista->inicio;
    No *ptAtual = lista->inicio;
    while(ptAux->dado > ptAtual->dado && ptAtual->proximo != NULL)
    {
        ptAnterior = ptAtual;
        ptAtual = ptAtual->proximo;
    }

    if(ptAux->dado > ptAtual->dado)
    {
        ptAtual->proximo = ptAux;
        lista->quantidadeDeElementos++;
        return;
    }

    ptAnterior->proximo = ptAux;
    ptAux->proximo = ptAtual;
    lista->quantidadeDeElementos++;
}

// Liberar Nos da  LLSE
void liberarNosLLSE(LLSE * const lista){
    if(verificarLLSEVazia(lista)){
        printf("\n LISTA ESTA VAZIA\n");
        return;
    }
    while(!verificarLLSEVazia(lista)){
        retirarInicioLLSE(lista);
    }
}
#endif // LLSE_H
