#include "PilhaEstatica.h"

pilha * criarPilha()
{
    pilha * NovaPilha = (pilha*)malloc(sizeof(pilha));
    NovaPilha->topo = -1;
    return NovaPilha;
}

int vaziaPilha(pilha* Pilha)
{
    if(Pilha->topo == -1)
        return 1;
    return 0;
}

void pushPilha(pilha* Pilha, int x)
{
    Pilha->topo = (Pilha->topo) +1;
    Pilha->info[Pilha->topo] = x;
}

int popPilha(pilha* Pilha)
{
    if(vaziaPilha(Pilha))
        return 2147483647;
    int x = Pilha->info[Pilha->topo];
    Pilha->topo--;
    return x;
}