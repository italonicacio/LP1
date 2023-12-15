#include <stdio.h>
#include "permuta_PCV.h"

using namespace std;

void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

rota *permuta_PCV(int vetor[], int inf, int sup, grafo *g, rota **melhorRota)
{
	if(inf == sup)
	{
	    rota *sol = new rota();
	    sol->v = vetor;
	    int dist = avalia_rota(g, sol);
	    //Atualizando melhor rota
        if(*melhorRota == NULL)
        {
            *melhorRota = sol;
        }else
        {
            //printf("M: %d, S: %d\n", melhorRota->aval, sol->aval);
            if((*melhorRota)->aval > sol->aval)
            {
                printf("Melhor rota: %d\n", sol->aval);
                delete *melhorRota;
                *melhorRota = sol;
            }else
                delete sol;
        }
	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{
			troca(vetor, inf, i);
			permuta_PCV(vetor, inf + 1, sup, g, melhorRota);
			troca(vetor, inf, i); // backtracking
		}
	}
}

