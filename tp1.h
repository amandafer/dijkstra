#define MAXNUMVERTICES  10000
//#define MAXNUMARESTAS   45000
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX

typedef int TipoValorVertice;

typedef int TipoPeso;

typedef struct TipoGrafo {
  TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
  int  NumVertices;
  int  NumArestas;
} TipoGrafo;

typedef TipoValorVertice TipoApontador;
typedef int TipoIndice;
typedef struct TipoItem {
  TipoPeso Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXNUMVERTICES + 1];

TipoApontador Aux;
int  i, NArestas;
short FimListaAdj;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
TipoIndice n;  /*Tamanho do heap*/
TipoValorVertice Raiz;

// Funcao que le o arquivo de entrada
int **readInputMatrix(FILE* inputFile, int *numCities, int **matrizVolPedidos, TipoGrafo *Graph);

// Funcao que me da instancia
void instancia(FILE* inputFile, int *instancia);

// Funcao que aloca memoria as matrizes
int **memAlloc(int row, int column);

// Funcao que libera memoria das matrizes
void freeMemory(int **matrix, int y);

// Funcao que multiplica matrizes
int multMatrix(int **matrixA, int **matrixB, int *numCities);
