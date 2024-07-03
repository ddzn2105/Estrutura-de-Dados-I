#ifndef LLDE_H
#define LLDE_H
//  Inclusão de Biblioteca
#include <stdlib.h>
#include <stdio.h>
/*************************************************************
 * Estruturas de Dados da Lista Linear Duplamente Encadeada
 * **********************************************************/
//  Estrutura de dados No - LLDE
typedef struct{
    struct No *anterior;
    int dado;
    struct No *proximo;

}No;
// Estrutura de dados LLDE
typedef struct{
    No *inicio;
    No *fim;
    int quantidadeDeElementos;
}LLDE;
/********************************************************
 * Funcoes para a Lista Linear Duplamente Encadeada
 * *****************************************************/
// Inicializar a estrutura de dados NO
void inicializarNo(No * const ptNo, int elemento){
    ptNo->anterior = NULL;
    ptNo->dado = elemento;
    ptNo->proximo = NULL;
}
// Inicializar a estrutura de dados LLDE
void inicializarLLDE(LLDE * const ptLLDE){
    ptLLDE->inicio = NULL;
    ptLLDE->fim = NULL;
    ptLLDE->quantidadeDeElementos = 0;
}
// Verificar se a LLDE esta vazia
int verificarLLDEVazia(LLDE const * const lista){
    return (lista->quantidadeDeElementos == 0);
}

// Inserir Nos no inicio LLDE
void inserirInicioLLDE(LLDE * const lista, int elemento){
    No *ptAux = (No*) malloc(sizeof(No));
    inicializarNo(ptAux,elemento);
    if(verificarLLDEVazia(lista)){
        lista->inicio = lista->fim = ptAux;
        lista->quantidadeDeElementos++;
        return;
    }
    ptAux->proximo=lista->inicio;
    lista->inicio->anterior = ptAux;
    lista->inicio = ptAux;
    lista->quantidadeDeElementos++;
    return;
}
// Acessar Inicio Nos no inicio LLDE
int acessarInicioLLDE(LLDE const * const lista){
    if(verificarLLDEVazia(lista)){
        printf("\nLista está vazia!\n");
        return 0;
    }
    return lista->inicio->dado;
}
// Retirar Inicio Nos no inicio LLDE
void retirarInicioLLDE(LLDE * const lista){
    if(verificarLLDEVazia(lista)){
        printf("\nLista está vazia!\n");
        return;
    }
    No *ptAux;
    if(lista->quantidadeDeElementos==1){
        ptAux= lista->inicio;
        lista->inicio=lista->fim=NULL;
        lista->quantidadeDeElementos=0;
        free(ptAux);
        return;
    }

    ptAux=lista->inicio;
    lista->inicio=ptAux->proximo;
    lista->inicio->anterior= NULL;
    lista->quantidadeDeElementos--;
    free(ptAux);
    return;
}

void inserirFimLLDE(LLDE * const lista, int elemento){
    No *ptAux = (No*) malloc(sizeof(No));
    inicializarNo(ptAux,elemento);
    if(verificarLLDEVazia(lista)){
        lista->inicio=lista->fim=ptAux;
        lista->quantidadeDeElementos++;
        return;
    }
    lista->fim->proximo=ptAux;
    ptAux->anterior=lista->fim;
    lista->fim=ptAux;
    lista->quantidadeDeElementos++;
}

void retirarFimLLDE(LLDE * const lista){
    if(verificarLLDEVazia(lista)){
        printf("\nLista está vazia!\n");
        return;
    }
    No *ptAux;
    ptAux=lista->fim;

    if(lista->quantidadeDeElementos==1){
        lista->inicio=lista->fim=NULL;
        lista->quantidadeDeElementos--;
        free(ptAux);
        return;
    }

    lista->fim=ptAux->anterior;
    lista->fim->proximo = NULL;
    lista->quantidadeDeElementos--;
    free(ptAux);

}

int acessarFimLLDE(LLDE * const lista){
    if(verificarLLDEVazia(lista)){
        printf("\nLista está vazia!\n");
        return 0;
    }
    return lista->fim->dado;
}

void inserirPosicao(LLDE * const lista, int valor, int posicao){
    if(posicao<0 || posicao>lista->quantidadeDeElementos){
        printf("Posicao fora do intervalo valido!");
        return;
    }

    if(posicao==0){
        inserirInicioLLDE(lista, valor);
        return;
    }

    if(posicao==lista->quantidadeDeElementos-1){
        inserirFimLLDE(lista, valor);
        return;
    }

    No *ptAux = lista->inicio;
    int cont=0;
    while(cont<posicao){
        ptAux=ptAux->proximo;
        cont++;
    }

    No *pNovo;
    pNovo->proximo=ptAux;
    pNovo->anterior=ptAux->anterior;
    ptAux->anterior->proximo=pNovo;
    ptAux->anterior = pNovo;
    lista->quantidadeDeElementos++;

}

int acessarPosicao(LLDE * const lista, int posicao){
    if(posicao < 0 || posicao>=lista->quantidadeDeElementos){
        printf("Posicao fora do intervalo valido!");
        return -1;
    }

    if(verificarLLDEVazia(lista)){
        printf("Lista está vazia!");
        return -1;
    }

    No *ptAux = lista->inicio;
    int cont = 0;
    while(cont<posicao){
        ptAux=ptAux->proximo;
        cont++;
    }
    return ptAux->dado;
}

void retirarPosicao(LLDE * const lista, int posicao){
    if(posicao < 0 || posicao>=lista->quantidadeDeElementos){
        printf("Posicao fora do intervalo valido!");
        return;
    }

    if(verificarLLDEVazia(lista)){
        printf("Lista está vazia!");
        return;
    }

    if(posicao==0){
        retirarInicioLLDE(lista);
        return;
    }

    if(posicao==lista->quantidadeDeElementos-1){
        retirarFimLLDE(lista);
        return;
    }

    No *ptAux=lista->inicio;
    int cont = 0;
    while(cont<posicao){
        ptAux=ptAux->proximo;
        cont++;
    }

    *(ptAux->anterior)->proximo=ptAux->proximo;
    ptAux->proximo->anterior=ptAux->anterior;
    free(ptAux);
}

// Liberar Nos da  LLDE
void liberarNosLLDE(LLDE * const lista){
    if(verificarLLSEVazia(lista)){
            printf("\n LISTA ESTA VAZIA\n");
            return;
        }
        while(!verificarLLSEVazia(lista)){
            retirarInicioLLSE(lista);
        }
}


#endif // LLDE_H
