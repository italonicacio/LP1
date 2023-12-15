#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int avalia_rota(grafo *g, rota *sol)
{
    sol->aval = 0;
    for(int i = 0; i < g->n-1; ++i)
    {
        int v = sol->v[i];
        int u = sol->v[i+1];
        sol->aval += g->D[v][u];
    }
    sol->aval += g->D[sol->v[g->n-1]][sol->v[0]];

    return sol->aval;
}

void ler_grafo_arquivo(char *nome_arquivo, grafo *g)
{
    FILE *f = fopen(nome_arquivo, "r");

    //ler a rodem do grafo
    fscanf(f, "%d", &g->n);

    //Alocando a matriz
    g->D = vector< vector <int> >(g->n, vector<int>(g->n) );

    //Lendo a matriz do arquivo
    for(int i = 0; i < g->n; ++i)
    {
        for(int j = 0; j < g->n; ++j)
        {
            fscanf(f, "%d", &g->D[i][j]);
        }
    }

    fclose(f);
}

void print_grafo(grafo *g)
{
    printf("Dimensao: %d\n", g->n);

    for(int i = 0; i < g->n; ++i)
    {
        for(int j = 0; j < g->n; ++j)
        {
            printf("%d\t", g->D[i][j]);
        }
        printf("\n");
    }
}

bool compare_vertice(vertice &v1, vertice &v2)
{
    return (v1.dist < v2.dist);
}
