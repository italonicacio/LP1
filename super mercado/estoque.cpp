#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estoque.h"
#include "produto.h"
#include "persistencia_supermercado.h"

using namespace std;

produto recuperar_produto(int codigoProduto, estoque *e)
{
    for(int i = 0; i < e->produtos.size(); ++i)
    {
        produto p = e->produtos[i];

        if(p.codigo == codigoProduto){
            return p;
        }

    }
}

void cadastrar_produto(estoque *e)
{
    produto p;

    p.nome = new char[100];

    char* auxNome = new char[100];


    printf("Qual o nome do produto? ");
    scanf("%s", auxNome);
    strcpy(p.nome, auxNome );

    p.id = e->produtos.size() + 1;

    printf("Qual o codigo do produto? ");
    scanf("%d", &p.codigo);

    printf("Qual o valor do produto? R$");
    scanf("%lf", &p.valor);

    printf("Qual a quantidade do produto? ");
    scanf("%d", &p.quantidade);

     e->produtos.push_back(p);
     salvar_estoque(e);

}

void listar_produto(estoque *e)
{
    printf("Produtos no estoque:\n");

    if(e->produtos.size() != 0)
    {
        for(int i = 0; i < e->produtos.size(); ++i)
        {
            produto p = e->produtos[i];

            //listar os produtos
            printf("Nome: %s\n", p.nome);
            printf("Id: %d\n", p.id);
            printf("Codigo: %d\n", p.codigo);
            printf("Valor: %3.lf\n", p.valor);
            printf("Quantidade: %d\n", p.quantidade);

            printf("\n");

        }
    }else{
            printf("nao a produtos no estoque!!!\n");
    }

}
