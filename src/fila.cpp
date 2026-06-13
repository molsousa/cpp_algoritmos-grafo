#include <iostream>
#include "../include/fila.hpp"

fila::lista::lista(tipoItem item)
{
    this->item = item;
    this->prox = nullptr;
}

fila::fila()
{
    this->inicio = nullptr;
    this->fim = nullptr;
}

bool fila::vazia()
{
    return (inicio == nullptr);
}

void fila::enqueue(tipoItem item)
{
    lista* novo = new lista(item);

    if(vazia()){
        inicio = novo;
    }
    else{
        fim->prox = novo;
    }
    fim = novo;
}

tipoItem fila::dequeue()
{
    tipoItem item;

    if(!vazia()){
        lista* aux = inicio;

        if(inicio == fim){
            inicio = nullptr;
        }
        else{
            inicio = inicio->prox;
        }
        item = aux->item;
        delete aux;
    }

    return item;
}

void fila::imprimir_fila()
{
    // debug
    for(lista* aux{inicio}; aux != nullptr; aux = aux->prox){
        std::cout << "|" << aux->item.v << "|->";
    }
    std::cout << "NULL\n";
}
