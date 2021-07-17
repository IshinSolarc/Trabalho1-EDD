#ifndef FILAESTATICA_H
#define FILAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILA_MAX 100

typedef struct fila
{
    char *info[FILA_MAX];
    int inicio;
    int fim;
} fila;

fila * criarFila();

int vaziaFila(fila* Fila);

void pushFila(fila* Fila, char* x);

char* popFila(fila* Fila);

#endif