#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <vector>

#include "estoque.h"
#include "caixa.h"
#include "persistencia_supermercado.h"


using namespace std;

int main()
{

        estoque e;
        caixa c;

        ler_estoque(&e);
        ler_caixa(&c);

        int op,idVenda, cond = 0;

        printf("---------------------------------------\n");
        printf("\t    Super Mercado\n");
        printf("---------------------------------------\n");

        printf("Aperte qualquer tecla para continuar...");
        getch();

        while(cond == 0)
        {

                system("CLS");
                printf("---------------------------------------\n");
                printf("\t    Super Mercado\n");
                printf("---------------------------------------\n");

                printf("Quais atividades voce deseja fazer:\n");
                printf("\t1. Cadastrar produtos\n");
                printf("\t2. Criar venda\n");
                printf("\t3. Abrir venda\n");
                printf("\t4. Listar os produtos cadastrados no estoque\n");
                printf("\t5. Fechar caixa\n");

                scanf("%d", &op);


                switch(op)
                {
                        case 1:
                                system("CLS");
                                printf("---------------------------------------\n");
                                printf("\t\tESTOQUE\n");
                                printf("---------------------------------------\n");
                                cadastrar_produto(&e);

                                break;
                        case 2:
                                system("CLS");
                                criar_venda(&e, &c);

                                break;

                        case 3:
                                printf("Digite o id da venda: ");
                                scanf("%d", &idVenda);
                                abrir_venda(idVenda, &e,&c);
                                break;
                        case 4:
                                system("CLS");
                                printf("---- ESTOQUE ----\n");
                                listar_produto(&e);

                                getch();

                                break;
                        case 5:
                                fechar_caixa(&c);

                                salvar_estoque(&e);

                                cond = 1;


                                break;

                }

        }

        return 0;
}
