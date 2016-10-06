// Da o caminho mais curto de um vertice a todos os outros e retorna a distancia de cada um
int **Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz, int *num_cidades, int *soma);

/* TAD de Grafos */
// Cria um Grafo Vazio
void FGVazio(TipoGrafo *Grafo);

// Insere uma aresta no grafo
void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

// Imprime o grafo
void ImprimeGrafo(TipoGrafo *Grafo);

// Retorna uma lista vazia
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);

// Retorna o primeiro da lista adj
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);

// Retorna adj apontado para o proximo
void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj);

// Imprime o grafo
void ImprimeGrafo(TipoGrafo *Grafo);

// 
void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);

// Constroi um vertice
void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

//
TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

//
void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A, TipoPeso *P,  TipoValorVertice *Pos);
