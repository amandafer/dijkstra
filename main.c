#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "graph.h"

int main(int argc, char *argv[]) {
    char *file = argv[1];
    FILE* pEntrada = fopen(file, "r");
    FILE* pSaida = fopen(argv[2],"w");
    int inst, a;

    instancia(pEntrada, &inst);
    
    // Faz os 3 cenarios para cada instancia do problema
    for (a = 0; a < inst; a++) {
        int **matriz_volpedidos, **matriz_distancia;

        int raiz_temp, soma_temp, max_temp, raiz, raiz2, raiz3, num_cidades, i;
        float soma = 0;
        int aux_temp = 0;
        int min_temp = 0;
        //TipoGrafo Graph;
        matriz_volpedidos = readInputMatrix(pEntrada, &num_cidades, matriz_volpedidos, &Grafo);
        // Para cada vertice pega a soma das distancias, soma com os pedidos e a maior distancia do caminho de Dijkstra
        
        for (raiz_temp = 0; raiz_temp < num_cidades; raiz_temp++) {
            matriz_distancia = Dijkstra(&Grafo, &raiz_temp, &num_cidades, &soma_temp);

            // Cenario 1
            if (soma == 0 || (soma_temp < soma)) {
                soma = soma_temp;
                raiz = raiz_temp;
            }

            // Cenario 2
            int aux;
            // Multiplico o numero de pedidos pelas distancias de cada vertice
            aux = multMatrix(matriz_volpedidos, matriz_distancia, &num_cidades);
            
            if (aux_temp == 0 || (aux_temp > aux)) {
                aux_temp = aux;
                raiz2 = raiz_temp;
            }

            // Cenario 3
            int max = 0;
            for (i = 0; i < num_cidades; i++) {
                // Procura a distancia maxima do caminho minimo do vertice
                max_temp = matriz_distancia[i][0];
                
                if (max == 0 || (max_temp > max)) {
                    max = max_temp;
                }
            }
            
            // Guarda a distancia minima dentre as maximas distancias
            if(min_temp == 0 || min_temp > max) {
                min_temp = max;
                raiz3 = raiz_temp;
            }
	        freeMemory(matriz_distancia, num_cidades);
        }
        // Percentual do prejuizo
        soma_temp = 0;
	    int **matriz_aux;
        matriz_aux = Dijkstra(&Grafo, &raiz3, &num_cidades, &soma_temp);
        float prejuizo = ((100*soma_temp)/soma) - 100;
        // Escreve os resultados no arquivo de saida
        fprintf(pSaida, "%d %d %d %.2f\n", raiz + 1, raiz2 + 1, raiz3 + 1, prejuizo);
        // Libera a memoria das matrizes ultizada
	    freeMemory(matriz_aux, num_cidades);
        freeMemory(matriz_volpedidos, 1);
    }

    fclose(pEntrada);
    fclose(pSaida);
    return 0;
}
