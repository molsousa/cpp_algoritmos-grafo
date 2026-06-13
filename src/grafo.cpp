#include <iostream>
#include <format>
#include <string>
#include "../include/grafo.hpp"

grafo::grafo()
{
    for(int i{}; i < MAX_NUM_VERTICES; i++){
        for(int j{}; j < MAX_NUM_VERTICES; j++){
            this->mat[i][j] = 0;
        }
    }

    this->num_vertices = MAX_NUM_VERTICES;
    this->num_arestas = 0;
}

grafo::grafo(tipoVertice num_vertices)
{
    for(int i{}; i < MAX_NUM_VERTICES; i++){
        for(int j{}; j < MAX_NUM_VERTICES; j++){
            this->mat[i][j] = 0;
        }
    }

    this->num_vertices = num_vertices;
    this->num_arestas = 0;
}

int grafo::get_num_aresta() const
{
    return this->num_arestas;
}

void grafo::set_num_aresta(int num_arestas)
{
    this->num_arestas = num_arestas;
}

void grafo::insere_aresta(tipoVertice v1, tipoVertice v2, tipoPeso peso)
{
    this->mat[v1][v2] = peso;

    this->num_arestas++;
}

bool grafo::existe_aresta(tipoVertice v1, tipoVertice v2)
{
    return (this->mat[v1][v2] > 0);
}

bool grafo::lista_adjacentes_vazia(tipoVertice v)
{
    int aux {0};
    bool lista_vazia {true};

    while(aux < this->num_vertices && lista_vazia){
        if(this->mat[v][aux] > 0){
            lista_vazia = false;
        }
        else{
            ++aux;
        }
    }

    return lista_vazia;
}

tipoVertice grafo::primeiro_lista_adjacencia(tipoVertice v) const
{
    int aux {0};
    bool lista_vazia {true};

    while(aux < this->num_vertices && lista_vazia){
        if(this->mat[v][aux] > 0){
            lista_vazia = false;
        }
        else{
            ++aux;
        }
    }

    if(aux == this->num_vertices){
        std::cout << "Lista adjacencia vazia\n";
        return -1;
    }

    return aux;
}

tipoVertice grafo::prox_adjacencia(tipoVertice v,
                                   tipoPeso& peso,
                                   int& prox,
                                   bool& fim_lista) const
{
    tipoVertice adj = prox;
    peso = this->mat[v][prox];
    ++prox;

    while(prox < this->num_vertices && (this->mat[v][prox] == 0)){
        ++prox;
    }

    if(prox == this->num_vertices)
        fim_lista = true;

    return adj;
}

tipoPeso grafo::retira_aresta(tipoVertice v1, tipoVertice v2)
{
    tipoPeso peso {};

    if(mat[v1][v2] != 0){
        peso = mat[v1][v2];
        mat[v1][v2] = 0;
        this->num_arestas--;
    }
    else{
        std::cout << "Aresta não existe!\n";
    }

    return peso;
}

void grafo::imprime_grafo()
{
    std::cout << "    ";

    for(int i{}; i < this->num_vertices; i++){
        std::cout << i << "   ";
    }

    std::cout << "\n";

    for(int i{}; i < this->num_vertices; i++){
        std::cout << std::format("{:d}", i);

        for(int j{}; j < this->num_vertices; j++){
            std::cout << std::format("{:4d}", this->mat[i][j]);
        }

        std::cout << "\n";
    }
}

void grafo::busca_profundidade()
{
    tipoCor cor[MAX_NUM_VERTICES];
    int antecessor[MAX_NUM_VERTICES];
    tipoVertice u;
    tipoTempo tempo {};
    tipoTempo d[MAX_NUM_VERTICES], t[MAX_NUM_VERTICES];

    for(u = 0; u < this->num_vertices; u++){
        cor[u] = branco;
        antecessor[u] = -1;
    }

    for(u = 0; u < this->num_vertices; u++){
        if(cor[u] == branco){
            visita_dfs(u, cor, antecessor, tempo, d, t);
        }
    }
}

void grafo::visita_dfs(tipoVertice u,
                       tipoCor cor[],
                       int antecessor[],
                       tipoTempo& tempo,
                       tipoTempo d[],
                       tipoTempo t[])
{

    tipoVertice v;
    bool fim_lista;
    tipoPeso peso;
    int aux;

    cor[u] = cinza;
    tempo++;
    d[u] = tempo;

    std::cout << std::format("Visita: {:2d}; Tempo descoberta: {:2d}; Cinza\n", u, d[u]);

    if(!lista_adjacentes_vazia(u)){
        aux = primeiro_lista_adjacencia(u);

        fim_lista = false;

        while(!fim_lista){
            v = prox_adjacencia(u, peso, aux, fim_lista);

            if(cor[v] == branco){
                antecessor[v] = u;
                visita_dfs(v, cor, antecessor, tempo, d, t);
            }
        }
    }

    cor[u] = preto;
    tempo++;
    t[u] = tempo;

    std::cout << std::format("Visita: {:2d}; Tempo termino: {:5d}; Preto\n", u, t[u]);
}
