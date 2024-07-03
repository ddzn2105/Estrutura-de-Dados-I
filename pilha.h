#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>
// Estrutura de dados Pilhavetor
typedef struct{
    int tamanho;    // Tamanho da pilha
    int *arrayPilha; // Vetor da pilha
    int topo;   // Controlador de acesso
}PilhaVetor;

// Função que printa na tela os dados da pilha
void dadosDaPilha(PilhaVetor const * const pilha){
    printf("\n*******************\n");
    printf("    DADOS DA PILHA  \n");
    printf("Tamanho: %d\n",pilha->tamanho);
    printf("Topo: %d\n", pilha->topo);
    printf("\n*******************\n");
}


// Função que cria e inicializa a pilha usando array
void criarPilhaVetor(int tamanho, PilhaVetor *const pilha){
    if(tamanho <= 0){
        printf("ERRO DE CRIAÇÃO DA PILHA - Tamanho não pode ser igual ou menor que 0");
        return;
    }
    pilha->topo = -1;
    pilha->arrayPilha = malloc(tamanho * sizeof(int));
    if(pilha->arrayPilha == NULL){
        printf("ERRO DE CRIAÇÃO DA PILHA");
        pilha->tamanho = 0;
    }
    pilha->tamanho = tamanho;
}

// Função que libera o espaço de memória usado pela pilha
void liberarPilhaVetor(PilhaVetor * const pilha){
    free(pilha->arrayPilha);
    pilha->arrayPilha = 0;
    pilha->tamanho = 0;
    pilha->topo = -1;
}

// Função que verifica se a pilha esta vazia
int verificarPilhaVazia(PilhaVetor const * const pilha){
    if(pilha->topo == -1) return 1;
    return 0;
}

// Função que verifica se a pilha esta cheia
int verificarPilhaCheia(PilhaVetor const * const pilha){
    if(pilha->topo == pilha->tamanho-1) return 1;
    return 0;
}

// Função que acessa elemento da pilha
int acessar(PilhaVetor const * const pilha){
    if(verificarPilhaVazia(pilha)){
        printf("\nA pilha está vazia\n");
        return -1;
    }
    return *(pilha->arrayPilha+pilha->topo);
    //return pilha->arrayPilha[pilha->topo];
}

// Função para incluir um elemento na pilha
void empilhar(int elemento, PilhaVetor * const pilha){
    if(verificarPilhaCheia(pilha)) {
        printf("\nA pilha está cheia!\n");
        return;
    }
    pilha->topo++; *(pilha->arrayPilha+pilha->topo) = elemento;
    //pilha->arrayPilha[pilha->topo] = elemento;
}

void desempilhar(PilhaVetor * const pilha){
    if(verificarPilhaVazia(pilha)){
        printf("\nA pilha esta vazia\n");
        return;
    }
    pilha->topo--;
}


#endif // PILHA_H
