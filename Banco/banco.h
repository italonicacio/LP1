#ifndef BANCO_H
#define BANCO_H


#include "conta.h"
#include <vector>

using namespace std;

struct banco
{
    char * nome;

    vector<conta> contas;
};

void criar_conta(banco *b, char *nomeCliente, char *senha, float depositoInicial);

conta recupera_conta(banco *b, char *nome);

#endif
