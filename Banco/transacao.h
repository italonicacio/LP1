#ifndef TRANSACAO
#define TRANSACAO

#define DEBITO 0
#define CREDITO 1

struct transacao
{
    int tipo;
    double valor;
};

void print_extrato(transacao *t);

#endif
