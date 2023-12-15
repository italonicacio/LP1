#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include <vector>



#include "persistencia_supermercado.h"

void salvar_estoque(estoque *e)
{
    FILE *f;
    f =  fopen("estoque.txt", "w");

    fprintf(f, "%d\n", e->produtos.size());

    for(int i = 0; i < e->produtos.size(); ++i)
    {

        produto p = e->produtos[i];

        fprintf(f, "%s\n", p.nome);
        fprintf(f, "%d\n", p.id);
        fprintf(f, "%d\n", p.codigo);
        fprintf(f, "%lf\n", p.valor);
        fprintf(f, "%d\n", p.quantidade);

    }

    fclose(f);
}


void salvar_caixa(caixa *c)
{
    FILE *f;
    f =  fopen("caixa.txt", "w");

    fprintf(f, "%lf\n", c->balanco);
    fprintf(f, "%d\n", c->vendas.size());

    for(int i = 0; i < c->vendas.size(); ++i)
    {
        venda v = c->vendas[i];

        fprintf(f, "%d\n", v.produtos.size() );
        fprintf(f, "%d\n", v.idVenda);
        fprintf(f, "%lf\n", v.valor);

        for(int j = 0; j < v.produtos.size() ; ++j)
        {

            produto p = v.produtos[j];

            fprintf(f, "%s\n", p.nome);
            fprintf(f, "%d\n", p.id);
            fprintf(f, "%d\n", p.codigo);
            fprintf(f, "%lf\n", p.valor);
            fprintf(f, "%d\n", p.quantidade);

        }

    }

    fclose(f);
}


void ler_estoque(estoque *e)
{
    FILE *f;
    f = fopen("estoque.txt", "r");
    if(f == NULL)
    {
        return;
    }
    int numEstoque;

    fscanf(f, "%d", &numEstoque);


    for(int i = 0; i < numEstoque; ++i)
    {

        produto p;
        p.nome = new char[100];

        fscanf(f, "%s", p.nome);
        fscanf(f, "%d", &p.id);
        fscanf(f, "%d", &p.codigo);
        fscanf(f, "%lf", &p.valor);
        fscanf(f, "%d", &p.quantidade);

        e->produtos.push_back(p);

    }


    fclose(f);

}


void ler_caixa(caixa *c)
{
    FILE *f;
    f = fopen("caixa.txt", "r");

    if(f == NULL)
    {
        return;
    }
    int numVendas;
    int numProdutos;


    fscanf(f, "%lf", &c->balanco);
    fscanf(f, "%d", &numVendas);


    for(int i = 0; i < numVendas; ++i)
    {
        venda v;

        fscanf(f, "%d", &numProdutos);
        fscanf(f, "%d", &v.idVenda);
        fscanf(f, "%lf", &v.valor);

        for(int j = 0; j < numProdutos; ++j)
        {

            produto p;

            p.nome = new char[100];

            fscanf(f, "%s", p.nome);
            fscanf(f, "%d", &p.id);
            fscanf(f, "%d", &p.codigo);
            fscanf(f, "%lf", &p.valor);
            fscanf(f, "%d", &p.quantidade);

            v.produtos.push_back(p);


        }
        c->vendas.push_back(v);
    }



    fclose(f);
}



