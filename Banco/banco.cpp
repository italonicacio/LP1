
#include "banco.h"
#include <string.h>
#include "persistencia_banco.h"

void criar_conta(banco *b, char *nomeCliente, char *senha, float depositoInicial)
{
    conta c;
    c.saldo = 0;
    c.nome = new char[strlen(nomeCliente) + 1];
    strcpy(c.nome, nomeCliente);

    c.senha = new char[strlen(senha) + 1];
    strcpy(c.senha, senha);

    depositar(&c, depositoInicial);

    b->contas.push_back(c);

    salva_banco(b);
}

conta recupera_conta(banco *b, char *nome)
{
    for(int i = 0; i < b->contas.size(); ++i)
    {
        conta c = b->contas[i];
        if(strcmp(c.nome, nome) == 0)
            return c;
    }

    conta cNULL;
    cNULL.nome = NULL;
    cNULL.senha = NULL;
    return cNULL;

}


