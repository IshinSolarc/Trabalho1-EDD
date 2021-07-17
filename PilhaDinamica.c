#include "PilhaDinamica.h"

pilha * criarPilha()
{
    pilha * NovaPilha = (pilha*) malloc(sizeof(pilha));
    NovaPilha->topo = NULL;
    return NovaPilha;
}

int vaziaPilha(pilha* Pilha)
{
    if(Pilha->topo == NULL)
        return 1;
    
    return 0;
}

void pushPilha(pilha* Pilha, int x)
{
    nodo * NovoNodo = (nodo*) malloc(sizeof(nodo));
    NovoNodo->info = x;
    NovoNodo->prox = Pilha->topo;
    Pilha->topo = NovoNodo; 
}

int popPilha(pilha* Pilha)
{
    if(vaziaPilha(Pilha))
        return 2147483647;
    int x = Pilha->topo->info;
    nodo * aux = Pilha->topo->prox;
    free(Pilha->topo);
    Pilha->topo = aux;
    return x;
}