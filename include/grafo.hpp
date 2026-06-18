#ifndef ALGORITMOS_GRAFOS_H_INCLUDED
#define ALGORITMOS_GRAFOS_H_INCLUDED

/// Definição de tipoPeso
typedef int tipoPeso;
/// Definição de tipoVertice
typedef int tipoVertice;
/// Definição de tipoTempo
typedef int tipoTempo;

/// Definição de constante para número máximo de vértices.
const int MAX_NUM_VERTICES {100};
/// Definição de constante para número máximo de arestas.
const int MAX_NUM_ARESTAS {4500};

/// Definição de tipo enumerado para cores dos vértices.
typedef enum {preto, branco, cinza} tipoCor;

/**
 * @brief
 * Classe para criação de um grafo.
 * Pode ser direcionado ou não direcionado.
 * Para essa representação foi utilizada matriz.
 */
class grafo
{
private:
    tipoPeso mat[MAX_NUM_VERTICES][MAX_NUM_VERTICES];
    int num_vertices;
    int num_arestas;

    /**
     * @brief Função membro auxiliar para aplicar o algoritmo dfs.
     * @param u: vertice u.
     * @param cor: vetor de cores.
     * @param antecessor: vetor de vértices antecessores.
     * @param tempo: variável referenciada de tempo.
     * @param d: vetor para tempo de descoberta de um vértice.
     * @param t: vetor para tempo de termino de um vértice.
     */
    void visita_dfs(tipoVertice, tipoCor[], int[], tipoTempo&, tipoTempo[], tipoTempo[]);

    /**
     * @brief Função membro auxiliar para aplicar o algoritmo bfs.
     * @param u: vértice u.
     * @param dist: vetor de distancia.
     * @param cor: vetor de cores.
     * @param antecessor: vetor de vértices antecessores.
     */
    void visita_bfs(tipoVertice, int[], tipoCor[], int[]);

public:
    /**
     * @brief
     * Construtor para criação de um grafo.
     * Inicializa o número de vértices com o tamanho máximo.
     * Inicializa a matriz com 0.
     */
    grafo();

    /**
     * @brief
     * Construtor para criação de um grafo.
     * Inicializa o número de vértices com o número de vértices passado como parâmetro.
     * Inicializa a matriz com 0.
     * @param num_vertices: número máximo de vértices
     * @overload
     */
    grafo(tipoVertice);

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

    void busca_largura();

    grafo* grafo_transposto();

};

#endif
