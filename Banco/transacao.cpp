#include <stdio.h>
#include "transacao.h"

void print_extrato(transacao *t)
{
    if(t->tipo == DEBITO)
    {
        printf("\tD: -(%lf)\n", t->valor);
    }

    if(t->tipo == CREDITO)
    {
        printf("\tC: +(%lf)\n", t->valor);
    }
}
