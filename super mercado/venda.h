#ifndef VENDA_H
#define VENDA_H


#include <vector>
#include "produto.h"


using namespace std;

struct venda
{
    int idVenda;
    double valor;
    vector<produto> produtos;
};



#endif // VENDA_H

