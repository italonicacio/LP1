#ifndef GRAFO_H
#define GRAFO_H

#include<vector>
#include "rota.h"

using namespace std;

struct grafo
{
    vector< vector <int> > D;
    int n;
};


void ler_grafo_arquivo(char *nome_arquivo, grafo *g);

void print_grafo(grafo *g);

int avalia_rota(grafo *g, rota *sol);

struct vertice
{
    int id;
    int dist;
};

bool compare_vertice(vertice &v1, vertice &v2);

#endif // GRAFO_H

