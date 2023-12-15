#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

vector<produto> produtos;

void cadastrar_produto(produto p){
	produtos.push_back(p);
}

void print_produtos(){
	
	for(int i = 0; i < produtos.size(); ++i)
	{
		system("CLS");
		produto p = produtos[i];
		printf("\nProduto %d: \n", i+1);
		printf("\tCodigo: %d\n",  p.codigo);
		printf("\tNome: %s\n",  p.nome);
		printf("\tPreco: %.2f\n",  p.preco);
	}
}

produto consultar_preco(int cod){
	
	for(int i = 0; i < produtos.size(); ++i)
	{
		produto p = produtos[i];
		
		if(p.codigo == cod)
		{
			return p;
		}
		
		produto pNULL;
		
		pNULL.codigo = -1;
		return pNULL; 
	}
	
	
}
