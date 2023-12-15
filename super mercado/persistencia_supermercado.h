#ifndef PERSISTENCIA_SUPERMERCADO_H
#define PERSISTENCIA_SUPERMERCADO_H


#include "estoque.h"
#include "caixa.h"


using namespace std;

void salvar_estoque(estoque *e);


void salvar_caixa(caixa *c);


void ler_estoque(estoque *e);

void ler_caixa(caixa *c);


#endif // PERSISTENCIA_SUPERMERCADO_H
