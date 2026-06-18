#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "grafo.hpp"

/**
 * @brief
 * Estrutura para armazenar tipo de item em lista
 */
typedef struct{
    tipoVertice v;
    tipoPeso peso;
}tipoItem;

/**
 * @brief
 * Classe para criação de uma fila dinâmica.
 * Essencial para determinados algoritmos em grafo
 */
class fila
{
private:
    /**
     * @brief
     * Classe para criação de lista encadeada.
     * Permite manipulação e inserção de elementos na fila.
     */
    class lista
    {
    public:
        tipoItem item;
        lista* prox;

        /**
         * @brief
         * Construtor para a criação de um elemento da lista.
         * Inicializa o nó atual com um item e o próximo com nulo.
         */
        lista(tipoItem);
    };

    lista* inicio;
    lista* fim;

public:
    /**
     * @brief
     * Construtor para criação de fila dinâmica.
     * Inicializa começo e fim da fila com nulo.
     */
    fila();

    /**
     * @brief Função membro para verificar se uma fila é vazia.
     * @return true caso esteja vazia.
     */
    bool vazia();

    /**
     * @brief Função membro para inserir elemento na fila.
     * @param Item a ser inserido.
     */
    void enqueue(tipoItem);

    /**
     * @brief Função membro para remover item do inicio da fila.
     * @return Item removido da fila.
     */
    tipoItem dequeue();

    /**
     * @brief Função membro para imprimir fila.
     */
    void imprimir_fila();
};

#endif
