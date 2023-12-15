#include "vetor.h"
#include <stdlib.h>

void aloca_vetor(vetor *v, int tam){
	v->tamanho = tam;
	v->dados = (int*) malloc(v->tamanho * sizeof(int));
}

void preencher_aleatorio_vetor(vetor *v){
	int i;
	for(i = 0; i < v->tamanho; i++){
		v->dados[i] = rand() % 1000;
		
	}
}

void insertion_sort(vetor *v){
	int i;
	
	for(i=1; i < v->tamanho; i++){
		int pivo = v->dados[i];
		int j = i-1;

		while(pivo < v->dados[j] && (j >= 0))
		{
			v->dados[j+1] = v->dados[j];
			--j;
		}
		v->dados[j+1] = pivo;

	}

}

void desaloca(vetor *v){

	free(v->dados);

}

void lerarquivo(vetor *v, char *filename){
	int n, i;

	FILE *f = fopen(filename, "r");
	fscanf(f, "%d", &n);
	

	aloca_vetor(v, n);

	for(i = 0; i< v->tamanho; i++){
		fscanf(f, "%d", &v->dados[i]);

	}

	fclose(f);

}

int busca(vetor *v, int elem){
	int i, j, m;
	i = 0;
	j = v->tamanho - 1;
	
	while(i <= j)
	{
		m = (int)(j+i)/2;

		if(v->dados[m] == elem)
		{
			return m;
		}else{ 
			if(v->dados[m] < elem)
			{
				i = m + 1;	
			}else
			{
				j = m - 1;
			}

		}
	
	}
	return -1;

}

int busca_recursiva(vetor *v, int elem, int ini, int pos){

	int meio = (pos + ini) / 2;
	if(ini <= pos)
	{
		
		if(v->dados[meio]  == elem){
			
			return meio;

		}else{
			if(v->dados > elem){
				
				return busca_recursiva(v, elem, ini, (meio -1));

			}else{
				
				return busca_recursiva(v, elem, (meio + 1), pos);	

			}
		}
	}
	return -1;
}