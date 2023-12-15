#include <stdio.h>
#include <string.h>
#include "banco.h"
#include "persistencia_banco.h"


int main()
{
    banco b;
    ler_banco(&b);
    if(b.nome == NULL)
    {
        b.nome = new char[100];
        strcpy(b.nome, "Banco do Brasil");
    }



    while(true)
    {
        printf("\nOperacoes Bancarias\n");
        printf("1. Criar Conta\n");
        printf("2. Acessar Conta\n");
        printf("3. Sair\n");

        int op;
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                char nome[100], senha[100];
                printf("Informe seus dados necessarios para criar a conta\n");
                printf("Digite seu nome: \n");
                scanf("%s", nome);
                printf("Digite sua senha: \n");
                scanf("%s", senha);
                double saldoInicial;
                printf("Digite seu saldo inicial: \n");
                scanf("%lf", &saldoInicial);
                criar_conta(&b, nome, senha, saldoInicial);
                break;

            case 3:
                return 1;

            case 2:
                printf("Digite seu nome para acessar a conta:\n");
                scanf("%s", nome);

                conta c = recupera_conta(&b, nome);

                bool sairMenu = false;
                while(true)
                {
                    if(sairMenu)
                        break;
                    printf("\nOperações na Conta\n");
                    printf("1. Emitir Extrato\n");
                    printf("2. Depositar\n");
                    printf("3. Sacar\n");
                    printf("4. Sair da Conta\n");

                    int opConta;
                    scanf("%d", &opConta);

                    switch(opConta)
                    {
                        case 1:
                            emitir_extrato(&c);
                            break;
                        case 2:
                            double valor;
                            printf("Digite o valor a ser depositado:\n");
                            scanf("%lf", &valor);
                            depositar(&c, valor);
                            break;
                        case 3:
                            printf("Digite o valor a ser sacado:\n");
                            scanf("%lf", &valor);
                             sacar(&c, valor);
                            break;
                        case 4:
                            sairMenu = true;
                            break;
                    }

                }


                break;

        }


    }







    return 0;
}
