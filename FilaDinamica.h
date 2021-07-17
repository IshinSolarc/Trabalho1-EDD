#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo1
{
    char *info;
    struct nodo1 * prox;  
} nodo1;

typedef struct fila
{
    nodo1 * inicio;
    nodo1 * fim;
} fila;

fila * criarFila();

int vaziaFila(fila * Fila);

void pushFila(fila *Fila, char* x);

char* popFila(fila*Fila);

#endif