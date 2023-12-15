#ifndef HC_h
#define HC_h

#include "grafo.h"


rota *construcao_vizinho_mais_proximo(grafo *g);

rota *pega_vizinho_reatribuicao(grafo *g, rota *sol);

rota *vizinho_aleatorio(grafo *g);

rota *permuta_vertice(grafo *g, rota *r);

#endif // HC
