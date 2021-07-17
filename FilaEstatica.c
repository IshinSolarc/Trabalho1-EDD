#include "FilaEstatica.h"

fila * criarFila()
{
    fila * NovaFila = malloc(sizeof(fila));
    NovaFila->fim = 0;
    NovaFila->inicio = 0;
    return NovaFila;
}

int vaziaFila(fila* Fila)
{
    if(Fila->fim == Fila->inicio)
        return 1;
    return 0;
}

void pushFila(fila* Fila, char* x)
{
    char *string = strdup(x);
    Fila->info[Fila->fim] = string;
    Fila->fim = (Fila->fim + 1) % FILA_MAX;
}

char* popFila(fila* Fila)
{
    if(vaziaFila(Fila))
        return '\0';
    char* x = Fila->info[Fila->inicio];
    Fila->inicio = (Fila->inicio + 1) % FILA_MAX;
    return x;
}