#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct pilha
{
    int info[100];
    int topo;
}pilha;

pilha * criarPilha();

int vaziaPilha(pilha* Pilha);

void pushPilha(pilha* Pilha, int x);

int popPilha(pilha* Pilha);


#endif