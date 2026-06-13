#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "grafo.hpp"

typedef struct{
    tipoVertice v;
}tipoItem;

class fila
{
private:
    class lista
    {
    public:
        tipoItem item;
        lista* prox;

        lista(tipoItem);
    };

    lista* inicio;
    lista* fim;

public:
    fila();

    bool vazia();

    void enqueue(tipoItem);

    tipoItem dequeue();

    void imprimir_fila();
};

#endif
