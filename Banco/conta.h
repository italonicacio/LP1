#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include "transacao.h"

using namespace std;

struct conta
{
        char *nome;
        char *senha;
        vector<transacao> transacoes;
        double saldo;
};

void depositar(conta *c, double valor);
void sacar(conta *c, double valor);

void emitir_extrato(conta *c);

void desaloca_conta(conta *c);

#endif
