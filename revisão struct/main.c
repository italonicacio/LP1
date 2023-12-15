#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.c"



int main()
{	
	vetor v;
	int i, pos;
	char *filename = "couting.txt";
	srand(time(NULL));

	/* se colocar "couting.txt" direto tbm funciona.*/
	lerarquivo(&v, filename);
	/*
	aloca_vetor(&v, 10000);
	preencher_aleatorio_vetor(&v);
	*/
	insertion_sort(&v);
	

	for(i = 0; i < v.tamanho; i++){
		
		printf("%d\n", v.dados[i] );
	}

	/*busca binaria*/

	pos = busca(&v, 2988);
	
	printf("POSICAO DO ELEMENTO %d NO VETOR EH %d \n",2988, pos );







	desaloca(&v);

	

	return 0;
}