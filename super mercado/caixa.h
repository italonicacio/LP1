#ifndef CAIXA_H
#define CAIXA_H

#include <vector>
#include "venda.h"
using namespace std;

struct caixa
{
  double balanco;
  vector<venda> vendas;

};


void criar_venda(estoque *e,caixa *c);

void adicionar_produto(estoque *e,venda *v);



void calcular_conta(caixa *c,venda *v);

void fechar_caixa(caixa *c);

void abrir_venda(int idVenda, estoque *e,caixa *c);


#endif // CAIXA_H
