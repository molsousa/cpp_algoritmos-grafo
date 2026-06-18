#ifndef ALGORITMOS_GRAFOS_H_INCLUDED
#define ALGORITMOS_GRAFOS_H_INCLUDED

/// Definição de tipo para peso.
typedef int tipoPeso;
/// Definição de tipo para vértice.
typedef int tipoVertice;
/// Definição de tipo para tempo.
typedef int tipoTempo;

/// Definição de tipo enumerado para cores dos vértices.
typedef enum {preto, branco, cinza} tipoCor;
/// Definição de tipo enumerado para verificar se grafo é orientado ou não orientado.
typedef enum {orientado, n_orientado} tipoGrafo;

/// Definição de constante para número máximo de vértices.
const int MAX_NUM_VERTICES {100};
/// Definição de constante para número máximo de arestas.
const int MAX_NUM_ARESTAS {4500};

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

    /**
     * @brief Função membro para obter número atual de arestas de um grafo.
     * @return Número atual de arestas.
     */
    int get_num_aresta() const;

    /**
     * @brief Função membro para alterar o número atual de arestas de um grafo.
     * @param num_arestas: valor inteiro representando o número de arestas.
     */
    void set_num_aresta(int);

    /**
     * @brief Função membro para inserir nova aresta no grafo.
     * @param v1: vértice origem.
     * @param v2: vértice destino.
     * @param peso: peso da aresta.
     * @param tipo: tipo de grafo.
     */
    void insere_aresta(tipoVertice, tipoVertice, tipoPeso, tipoGrafo);

    /**
     * @brief Função membro para verificar se uma aresta existe.
     * @param v1: vértice origem.
     * @param v2: vértice destino.
     *
     */
    bool existe_aresta(tipoVertice, tipoVertice) const;

    /**
     * @brief Função membro para verificar dentro de um vértice a lista de vértices adjacentes.
     * @param v: vértice origem.
     * @return True se a lista estiver vazia.
     */
    bool lista_adjacentes_vazia(tipoVertice) const;

    /**
     * @brief Função membro para consultar o primeiro vértice na lista de adjacentes.
     * @param v: vértice origem.
     * @return Retorna o primeiro vértice descoberto.
     */
    tipoVertice primeiro_lista_adjacencia(tipoVertice) const;

    /**
     * @brief Função membro para consultar o próximo vértice adjacente na lista de adjacentes.
     * @param v: vértice origem.
     * @param peso: variável referenciada para peso da aresta.
     * @param prox: variável refereciada para percorrer vértices adjacentes.
     * @param fim_lista: variável referenciada para marcar o final da lista de adjacentes.
     * @return Retorna o próximo vértice adjacente.
     */
    tipoVertice prox_adjacencia(tipoVertice, tipoPeso&, int&, bool&) const;

    /**
     * @brief Função membro para remover aresta.
     * @param v1: vértice origem.
     * @param v2: vértice destino.
     * @return Retorna o peso removido.
     */
    tipoPeso retira_aresta(tipoVertice, tipoVertice);

    /**
     * @brief Função membro para imprimir grafo em forma de matriz.
     */
    void imprime_grafo();

    /**
     * @brief Função membro para aplicar DFS (busca em profundidade).
     */
    void busca_profundidade();

    /**
     * @brief Função membro para aplicar BFS (busca em largura).
     */
    void busca_largura();

    /**
     * @brief Função membro para criar um grafo transposto.
     * @return Novo grafo transposto.
     */
    grafo* grafo_transposto();

    /**
     * @brief Função membro para aplicar algoritmo Prim
     * @param raiz: vértice origem.
     */
    void prim(tipoVertice&);
};

#endif
