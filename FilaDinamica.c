#include "FilaDinamica.h"

fila * criarFila()
{
    fila * NovaFila = (fila*)malloc(sizeof(fila));
    NovaFila->fim = NULL;
    NovaFila->inicio = NULL;
    return NovaFila;
}

int vaziaFila(fila * Fila)
{
    if(Fila->inicio == NULL)
        return 1;
    return 0;
}

void pushFila(fila *Fila, char* x)
{
    nodo1 * NovoElemento = (nodo1*)malloc(sizeof(nodo1));
    char *string;
    string = strdup(x);
    NovoElemento->info = string;
    NovoElemento->prox = NULL;
    if(Fila->fim != NULL)
        Fila->fim->prox = NovoElemento;

    Fila->fim = NovoElemento;

    if(Fila->inicio == NULL)
        Fila->inicio = NovoElemento;
}

char* popFila(fila*Fila)
{
    if(vaziaFila(Fila))
        return '\0';
    nodo1 * aux = Fila->inicio->prox;
    char *x = Fila->inicio->info;

    if(Fila->inicio == Fila->fim)
        Fila->fim == NULL;
        
    free(Fila->inicio);
    Fila->inicio = aux;
    return x;
}
