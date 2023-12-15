#include <stdio.h>
#include <stdlib.h>

#include "persistencia_banco.h"


void salva_banco(banco *b)
{
    FILE *f;
    f = fopen("banco.txt", "w");

    fprintf(f, "%s\n", b->nome);
    fprintf(f, "%d\n", b->contas.size() );

    for(int i = 0; i < b->contas.size(); ++i)
    {
        conta c = b->contas[i];
        fprintf(f, "%s\n", c.nome);
        fprintf(f, "%s\n", c.senha);
        fprintf(f, "%lf\n", c.saldo);
        fprintf(f, "%d\n", c.transacoes.size());

        for(int j = 0; j < c.transacoes.size(); ++j)
        {
            transacao t = c.transacoes[j];
            fprintf(f, "%d\n", t.tipo);
            fprintf(f, "%lf\n", t.valor);

        }

    }

    fclose(f);
}

void ler_banco(banco *b)
{
   	FILE *f;
    f = fopen("banco.txt", "r");
    b->nome = new char[100];

    fscanf(f, "%s", b->nome);

    int numContas;
    fscanf(f, "%d", &numContas );

    for(int i = 0; i < numContas; ++i)
    {
        conta c;
        c.nome = new char[100];
        c.senha = new char[100];

        fscanf(f, "%s\n", c.nome);
        fscanf(f, "%s\n", c.senha);
        fscanf(f, "%lf\n", &c.saldo);

        int numTransacoes;
        fscanf(f, "%d", &numTransacoes );

        for(int j = 0; j < numTransacoes; ++j)
        {
            transacao t;
            fscanf(f, "%d", &t.tipo);
            fscanf(f, "%lf", &t.valor);
            c.transacoes.push_back(t);


        }
        b->contas.push_back(c);
    }

    fclose(f);
}
