#include <stdio.h>
#include "produto.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int cod;
	
	
	while(true){
			system("CLS");
			printf("Cadastrar produtos\n");
			printf("Digite o codigo do novo produto (<0 jpara finalizar cadastro)\n");
			scanf("%d", &cod);
		if(cod >= 0)
		{
			
			
			
			produto p;
			p.codigo = cod;
			
			printf("\nDigite o nome do produto:\n");
			char n[100];
			scanf("%s", n);	
			
			p.nome = new char[strlen(n) + 1];
			strcpy(p.nome, n);
			
			float pr;
			printf("Digite o preco do produto:\n");
			scanf("%f", &pr);
			p.preco = pr;
			
			cadastrar_produto(p);
			
		
		}else{
			break;
		}
		
	}
		print_produtos();
		
		getchar();
		//
		system("CLS");
		printf("Digite o codigo do Produto desejado:\n");
		scanf("%d", cod);
		
		produto p = consultar_preco(cod);
		
		printf("\nProduto %d: \n");
		printf("\tCodigo: %d\n",  p.codigo);
		printf("\tNome: %s\n",  p.nome);
		printf("\tPreco: %.2f\n",  p.preco);
		
		
	return 0;
}
