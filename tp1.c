#include<stdio.h>
#include<stdlib.h>
#include "tp1.h"
#include "graph.h"

// Funcao que le o arquivo de entrada
int **readInputMatrix(FILE* inputFile, int *numCities, int **matrizVolPedidos, TipoGrafo *Graph) {
    if (inputFile == NULL) {
        printf("Nao foi possivel ler o arquivo!\n");
        return NULL;
    } else {
        int **adjMatrix;
        int i, j;
        fscanf(inputFile, "%d", &*numCities);
        // Forma um grafo que tem como vertices as cidades, vazio e nenhuma aresta
        Graph->NumVertices = *numCities;
        Graph->NumArestas = 0;
        FGVazio(&*Graph);
        adjMatrix = memAlloc(*numCities, *numCities);
        
        // Le a matriz adj no arquivo e insere as arestas no grafo criado
        for (i = 0; i < *numCities; i++) {
            for (j = 0; j < *numCities; j++) {
                fscanf(inputFile, "%d", &adjMatrix[i][j]);
                InsereAresta(&i, &j, &adjMatrix[i][j], Graph);
                
                if (adjMatrix[i][j] != 0) {
                    Graph->NumArestas++;
                }
            }
        }
        Graph->NumArestas = (Graph->NumArestas)/2;
        //ImprimeGrafo(Graph);
        int y;
        matrizVolPedidos = memAlloc(1, *numCities);

        // Le o numero de pedidos de cada cidade para o cenario 2
        for (y = 0; y < *numCities; y++) {
            fscanf(inputFile, "%d", &matrizVolPedidos[0][y]);
        }
        freeMemory(adjMatrix, *numCities);
        return matrizVolPedidos;
    }
}

//Funcao que me da instancia e numero de cidades
void instancia(FILE* inputFile, int *instancia) {
    fscanf(inputFile, "%d", &*instancia);
}

// Funcao que aloca memoria as matrizes
int **memAlloc(int row, int column) {
    int **matrix;
    int count;
    matrix = (int **)malloc(row*sizeof(int*));
    
    for (count = 0 ; count < row ; count++) {
        matrix[count] = malloc(column*sizeof(int));
    }
    
    if (matrix == NULL) {
        printf("ERRO: Not enough memory.");
        return NULL;
    } else
        return matrix;
}

//Funcao que multiplica matrizes
int multMatrix(int **matrixA, int **matrixB, int *numCities) {
    int k;
    int aux = 0;
    /* As matrizes a serem multiplicadas sempre serao os pedidos e distancia de cada cidade a outra,
       portando a linha da matriz A e a coluna da matriz B sempre serao 0 */
    for (k = 0; k < *numCities; k++) {
        aux += matrixA[0][k]*matrixB[k][0];
    }
    return aux;
}

// Funcao que libera a memoria das matrizes
void freeMemory(int **matrix, int y) {
    int i;
    
    for (i = 0; i < y; i++) 
	    free(matrix[i]);
    
    free(matrix);
    matrix = NULL;
}
