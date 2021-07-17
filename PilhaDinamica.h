#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int info;
    struct nodo * prox; 
} nodo;

typedef struct pilha
{
    nodo * topo;
} pilha;

pilha* criarPilha();

int vaziaPilha(pilha* Pilha);

void pushPilha(pilha* Pilha,int x);

int popPilha(pilha* Pilha);

#endif