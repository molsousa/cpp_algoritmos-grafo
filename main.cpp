#include <iostream>
#include "include/grafo.hpp"
#include "include/fila.hpp"

int main()
{
    grafo* g;
    tipoVertice v1, v2, adj;
    tipoVertice num_vertices;
    tipoPeso peso;
    int num_arestas;
    bool fim_lista;

    fila* f = new fila();
    tipoItem item;

    std::cout << "Numero de vertices: ";
    std::cin >> num_vertices;

    std::cout << "Numero de arestas: ";
    std::cin >> num_arestas;

    g = new grafo(num_vertices);

    for(int i{}; i < num_arestas; i++){
        std::cout << "Insere v1---v2---peso: ";
        std::cin >> v1 >> v2 >> peso;

        g->insere_aresta(v1, v2, peso);
    }

    g->imprime_grafo();

    g->busca_profundidade();

    return 0;
}
