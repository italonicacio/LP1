#include "conta.h"
#include <stdio.h>

void depositar(conta *c, double valor)
{
    transacao t;
    t.tipo = CREDITO;
    t.valor = valor;

    c->transacoes.push_back(t);
    c->saldo += valor;
}



void sacar(conta *c, double valor)
{
    if(c->saldo >= valor)
    {
        transacao t;
        t.tipo = DEBITO;
        t.valor = valor;

        c->transacoes.push_back(t);
        c->saldo -= valor;
    }else
        printf("Saldo insuficiente!");
}

void emitir_extrato(conta *c)
{
    printf("Conta Corrente\nCliente: %s\n", c->nome);

    printf("Operacoes:\n");
    for(int i = 0; i < c->transacoes.size(); ++i)
    {
        transacao t = c->transacoes[i];
        print_extrato(&t);
    }
    printf("Saldo Final: %lf\n", c->saldo);
}

void desaloca_conta(conta *c)
{
    if(c->nome != NULL)
        delete c->nome;
    if(c->senha != NULL)
        delete c->senha;
}
