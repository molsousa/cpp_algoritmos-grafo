#ifndef ALGORITMOS_GRAFOS_H_INCLUDED
#define ALGORITMOS_GRAFOS_H_INCLUDED

typedef int tipoPeso;
typedef int tipoVertice;
typedef int tipoTempo;

const int MAX_NUM_VERTICES {100};
const int MAX_NUM_ARESTAS {4500};

typedef enum {preto, branco, cinza} tipoCor;

class grafo
{
private:
    tipoPeso mat[MAX_NUM_VERTICES][MAX_NUM_VERTICES];
    int num_vertices;
    int num_arestas;

    void visita_dfs(tipoVertice, tipoCor[], int[], tipoTempo&, tipoTempo[], tipoTempo[]);

public:
    grafo();

    grafo(tipoVertice num_vertices);

    int get_num_aresta() const;

    void set_num_aresta(int);

    void insere_aresta(tipoVertice, tipoVertice, tipoPeso);

    bool existe_aresta(tipoVertice, tipoVertice);

    bool lista_adjacentes_vazia(tipoVertice);

    tipoVertice primeiro_lista_adjacencia(tipoVertice) const;

    tipoVertice prox_adjacencia(tipoVertice, tipoPeso&, int&, bool&) const;

    tipoPeso retira_aresta(tipoVertice, tipoVertice);

    void imprime_grafo();

    void busca_profundidade();
};

#endif
