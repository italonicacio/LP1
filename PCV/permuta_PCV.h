#ifndef PERMUTA_H
#define PERMUTA_H

#include "grafo.h"
#include "rota.h"

void troca(int vetor[], int i, int j);

rota *permuta_PCV(int vetor[], int inf, int sup, grafo *g, rota **melhorRota);

#endif // PERMUTA_H
