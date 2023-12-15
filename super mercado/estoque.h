#ifndef ESTOQUE_H
#define ESTOQUE_H


#include "produto.h"
#include <vector>

using namespace std;

struct estoque
{
    vector<produto> produtos;
};

produto recuperar_produto(int idproduto, estoque *e);

void cadastrar_produto(estoque *e);

void listar_produto(estoque *e);

#endif // ESTOQUE_H
