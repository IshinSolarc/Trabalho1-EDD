#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PilhaDinamica.c"
#include "FilaDinamica.c"

#define MAX_PROGRAMAS 10

int main()
{
    int numero_de_programas = 0;
    scanf("%d", &numero_de_programas);
    
    if(numero_de_programas > MAX_PROGRAMAS)
    {
        printf("Limite de programas excedido");
        exit(987);
    }

    pilha *Pilha[MAX_PROGRAMAS] = {NULL};
    fila *Fila[MAX_PROGRAMAS] = {NULL};
    bool Fim_Programa[MAX_PROGRAMAS] = {false}; //Bool que define fim do programa

    //Cria Pilhas e Filas
    for (int i = 0; i < numero_de_programas; i++)
    {
        Pilha[i] = criarPilha();
        Fila[i] = criarFila();
    }

    //Le elementos para a fila
    for (int i = 0; i < numero_de_programas; i++)
    {
        int numero_de_elementos;
        scanf("%d", &numero_de_elementos);
        for (int j = 0; j < numero_de_elementos; j++)
        {
            char elemento[11];
            scanf("%s", &elemento);
            pushFila(Fila[i], elemento);
        }
    }

    //Trabalho e operacoes na pilha
    int operacoes = 1;
    while (operacoes)
    {
        operacoes = 0;
        for (int i = 0; i < numero_de_programas; i++)
        {
            if (!Fim_Programa[i])
            {
                char *retPopFila = popFila(Fila[i]);
                //se Pop da Fila for operador
                if (retPopFila[0] == '+' || retPopFila[0] == '-' || retPopFila[0] == '*' || retPopFila[0] == '/')
                {
                    int x = popPilha(Pilha[i]); // X = primeiro pop
                    int y = popPilha(Pilha[i]); // Y = Segundo pop
                    int res;
                    if (x == 2147483647  || y == 2147483647) // Valor de erro caso tenha tido pop em pilha vazia(max int)
                    {
                        printf("programa %d: erro, fim\n", i + 1);
                        Fim_Programa[i] = true;
                    }
                    else
                    {
                        switch (retPopFila[0])
                        {
                        case '+':
                            res = y + x;
                            printf("programa %d: desempilha %d, desempilha %d, empilha %d", i + 1, x, y, res);
                            pushPilha(Pilha[i], res);
                            operacoes++;
                            break;
                        case '-':
                            res = y - x;
                            printf("programa %d: desempilha %d, desempilha %d, empilha %d", i + 1, x, y, res);
                            pushPilha(Pilha[i], res);
                            operacoes++;
                            break;
                        case '*':
                            res = y * x;
                            printf("programa %d: desempilha %d, desempilha %d, empilha %d", i + 1, x, y, res);
                            pushPilha(Pilha[i], res);
                            operacoes++;
                            break;
                        case '/':
                            if (x == 0)
                            {
                                printf("programa %d: erro, fim\n", i + 1);
                                Fim_Programa[i] = true;
                            }
                              else
                            {
                                res = y / x;
                                printf("programa %d: desempilha %d, desempilha %d, empilha %d", i + 1, x, y, res);
                                pushPilha(Pilha[i], res);
                                operacoes++;
                            }
                        }
                        if (vaziaFila(Fila[i]) && !Fim_Programa[i])
                        {
                            printf(", fim\n");
                            Fim_Programa[i] = true;
                        }
                        else
                            printf("\n");
                    }
                }
                else //se Pop da Fila for numero
                {
                    int x;
                    sscanf(retPopFila, "%d", &x);
                    pushPilha(Pilha[i], x);
                    operacoes++;
                    printf("programa %d: empilha %d\n", i + 1, x);
                }
                free(retPopFila); //Libera as strings alocadas
            }
        }
    }

    //Limpa filas e pilhas caso erro tenha ocorrido e desaloca as alocações de string para a fila
    for (int i = 0; i < numero_de_programas; i++)
    {
        while (!vaziaFila(Fila[i]))
        {
            char *x = popFila(Fila[i]);
            free(x);
        }
        while (!vaziaPilha(Pilha[i]))
        {
            popPilha(Pilha[i]);
        }
    }

    return 1;
}