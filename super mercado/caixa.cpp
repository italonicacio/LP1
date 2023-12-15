#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>


#include "estoque.h"
#include "produto.h"
#include "caixa.h"
#include "venda.h"
#include "persistencia_supermercado.h"

using namespace std;

void criar_venda(estoque *e,caixa *c)
{
    venda v;
    int op;

    v.idVenda = c->vendas.size() +1;

    system("CLS");
    printf("---------------------------------------\n");
    printf("\t\tCAIXA\n");
    printf("---------------------------------------\n");


    do
    {


        printf("Quais atividades voce deseja fazer:\n");
        printf("\t1. Adicionar produto na venda\n");
        printf("\t2. Listar os produtos cadastrados no estoque\n");
        printf("\t3. Calcular a conta da venda\n");
        printf("\t4. Fechar Venda\n");
        scanf("%d", &op);


        switch(op)
        {
            case 1:

                adicionar_produto(e, &v);
                break;
            case 2:

                listar_produto(e);
                break;
            case 3:

                calcular_conta(c, &v);

                break;
            case 4:
                salvar_caixa(c);
                op = 0;
                break;


        }
    } while(op != 0);




}



void adicionar_produto(estoque *e, venda *v)
{
    int quantidade, cond = 0;
    int codigoProduto;
    int aux;
    do
    {

        if(e->produtos.size() == 0)
        {
            printf("Nao existe produtos no sistema!\n");
            getch();
            cond = 1;
        }else
        {
            printf("Qual o Codigo do produto: ");
            scanf("%d", &codigoProduto);

            for(int i = 0; i < e->produtos.size(); ++i)
            {


                produto p = e->produtos[i];

                if(codigoProduto == p.codigo)
                {

                    printf("Qual a quantidade do produto: ");
                    scanf("%d", &quantidade);
                    printf("\n");



                    if((p.quantidade - quantidade)>=0)
                    {


                        p.quantidade -= quantidade;
                        e->produtos[i] = p;

                        p.quantidade = quantidade;
                        v->produtos.push_back(p);
                        cond = 1;


                    }else
                    {

                        printf("\n_______________________________\n");
                        printf("essa quantidade nao e valida!\n");
                        printf("_______________________________\n");

                    }



                }


            }
        }


    }while(cond == 0);

}



void calcular_conta(caixa *c,venda *v)
{
    double conta = 0;


    if(v->produtos.size() == 0)
    {

        printf("nao a produtos nessa venda!!!\n");


    }else{

        printf("\n----------------------------------------\n");
        printf("Produto da venda:\n");
        printf("id da Venda: %d\n", v->idVenda);
        for(int i = 0; i < v->produtos.size(); ++i)
        {
            produto p = v->produtos[i];


            conta = conta + (p.valor * p.quantidade);
            printf("%s  \tR$ %.2lf X %d\n", p.nome, p.valor, p.quantidade);

        }



        printf("\nValor a pagar: R$ %.2lf\n", conta);
        printf("\n----------------------------------------\n");
        v->valor = conta;

        c->vendas.push_back(*v);

    }

}


void fechar_caixa(caixa *c)
{
    double balanco = 0;
    for(int i = 0; i < c->vendas.size(); ++i)
    {
        venda vv = c->vendas[i];

        balanco += vv.valor;
    }
    c->balanco = balanco;
    printf("\n----------------------------------------\n");
    printf("Balanco: R$ %.3lf", c->balanco);
    printf("\n----------------------------------------\n");

    salvar_caixa(c);
}


void abrir_venda(int idvenda, estoque *e,caixa *c)
{
    int op, cond = 0;


    if(c->vendas.size() == 0 || idvenda > c->vendas.size() )
    {

        printf("ID invalido ou nao existe vendas no sistema!");
        getch();


    }else
    {


        do
        {

            for(int i = 0; i < c->vendas.size(); ++i)
            {
                venda v =  c->vendas[i];

                if(v.idVenda == idvenda)
                {

                    system("CLS");
                    printf("---------------------------------------\n");
                    printf("\t\tCAIXA\n");
                    printf("---------------------------------------\n");

                    printf("Quais atividades voce deseja fazer:\n");
                    printf("\t1. Adicionar produto na venda\n");
                    printf("\t2. Listar os produtos cadastrados no estoque\n");
                    printf("\t3. Calcular a conta da venda\n");
                    printf("\t4. Fechar Venda\n");
                    scanf("%d", &op);


                    switch(op)
                    {
                        case 1:

                            adicionar_produto(e, &v);
                            getch();
                            break;
                        case 2:
                            listar_produto(e);
                            getch();
                            break;
                        case 3:

                            calcular_conta(c, &v);
                            getch();
                            break;
                        case 4:
                            c->vendas[i] = v;
                            cond = 1;
                            getch();
                            break;


                    }

                }
            }
        } while(cond == 0);



    }





}


