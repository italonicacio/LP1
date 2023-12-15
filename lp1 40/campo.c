#include <stdio.h>
#include <stdlib.h>
#include "campo.h"
#include "teclado.h"
#include <time.h>

void aloca_campo(JQ *c){
	int i,j;
	int n = 5;
	srand(time(NULL));
	c->n = n;

	c->jogadas = 0;
	c->pontos = 0;

	c->campo = (int**)malloc (c->n * sizeof(int*));

	for(i = 0; i < c->n; i++)
	{
		c->campo[i] = (int*)malloc (c->n * sizeof(int));

	}


	for(i = 0; i < c->n; i++)
	{
		for (j = 0; j < c->n; j++)
		{
			c->campo[i][j] = 0;
		}
	}

	/*primeiro numero aleatorio*/
	i = rand() % 5;
	j = rand() % 5;


	c->campo[i][j] = 5;

	/*segundo numero*/
	do{

		i = rand() % 5;
		j = rand() % 5;



	}while(c->campo[i][j] != 0);

	c->campo[i][j] = 5;
}


void imprime_campo(JQ *c){

	int i,j;

	system("CLS");
	for(i = 0; i < c->n; i++)
	{
		printf(" ---- ---- ---- ---- ----\n" );
		for (j = 0; j < c->n; j++)
		{
			if (c->campo[i][j] == 0)
			{
				if(j == 0){
					printf("|");
				}
				printf("    ", c->campo[i][j]);
				printf("|" );

			}else if(c->campo[i][j] == 5)
			{

				if(j == 0){
					printf("|");
				}
				printf(" 0%d ", c->campo[i][j]);
				printf("|" );

			}else{
				if(j == 0){
					printf("|");
				}
				printf(" %d ", c->campo[i][j]);
				printf("|" );

			}
		}
		printf("\n");
	}
	printf(" ---- ---- ---- ---- ----\n" );
	printf("\nPontos: %d\n", c->pontos);
	printf("\nJogadas: %d\n", c->jogadas);
	do{

		i = rand() % 5;
		j = rand() % 5;

	}while(c->campo[i][j] != 0);

	c->campo[i][j] = 5;
}


void desaloca(JQ *c){

	free(c->campo);
}



void movimento_campo(JQ *c, int comando ){
	int i,j,k;
	int auxLinha, auxColuna;

	if( comando == CIMA || comando == BAIXO || comando == ESQUERDA || comando == DIREITA )
		c->jogadas += 1;

		switch(comando)
		{
			case CIMA:
				for(i = 0; i < c->n; ++i)
				{
					for (j = 0; j < c->n; ++j)
					{

						if(c->campo[i][j] != 0)
						{
							auxLinha = j;
							while (auxLinha > 0)
							{

								auxLinha--;

								if (c->campo[auxLinha][i] == 0) {

									c->campo[auxLinha][i] = c->campo[auxLinha+1][i];

									c->campo[auxLinha+1][i] = 0;


								}else if (c->campo[auxLinha][i] == c->campo[auxLinha + 1][i])
								{

									c->campo[auxLinha][i] = c->campo[auxLinha][i] + c->campo[auxLinha + 1][i];

									c->campo[auxLinha + 1][i] = 0;

									if(c->campo[auxLinha][i] == 40)
									{

											c->pontos = c->pontos + 100;

											c->campo[auxLinha][i] = 0;

									}

								}else {

									break;
								}


							}
						}

					}
				}

			break;

			case BAIXO:

				for(i = 0; i < c->n; ++i)
				{
					for (j = c->n -1; j >= 0; --j)
					{
						if(c->campo[j][i] != 0)
						{
							auxLinha = j;
							while(auxLinha < c->n -1)
							{
								auxLinha ++;

								if(c->campo[auxLinha][i] == 0)
								{
									c->campo[auxLinha][i] = c->campo[auxLinha -1][i];
									c->campo[auxLinha -1][i] = 0;
								}else if(c->campo[auxLinha][i] == c->campo[auxLinha-1][i]){
									c->campo[auxLinha][i] = c->campo[auxLinha][i] + c->campo[auxLinha - 1][i];
									c->campo[auxLinha - 1][i] = 0;

									if(c->campo[auxLinha][i] == 40)
									{
										c->pontos += 100;
										c->campo[auxLinha][i] = 0;
									}

								}else{
									break;
								}
							}
						}

					}
				}


			break;

			case ESQUERDA:
				for(i = 0; i < c->n; ++i)
				{
					for (j = 0; j < c->n; ++j)
					{
						if(c->campo[i][j] != 0)
						{
							auxColuna = j;

							while(auxColuna > 0)
							{
								auxColuna --;

								if(c->campo[i][auxColuna] == 0)
								{
									c->campo[i][auxColuna] = c->campo[i][auxColuna + 1];
									c->campo[i][auxColuna + 1] = 0;
								}else if(c->campo[i][auxColuna] == c->campo[i][auxColuna + 1]){
									c->campo[i][auxColuna] = c->campo[i][auxColuna] + c->campo[i][auxColuna +1];
									c->campo[i][auxColuna + 1] = 0;

									if(c->campo[i][auxColuna] == 40)
									{
										c->pontos += 100;
										c->campo[i][auxColuna] = 0;
									}

								}else{
									break;
								}
							}
						}

					}
				}

			break;

			case DIREITA:

				for(i = 0; i < c->n; ++i)
				{
					for (j = c->n -1; j >= 0; --j)
					{
						if(c->campo[i][j] != 0)
						{
							auxColuna = j;

							while(auxColuna < c->n-1)
							{
								auxColuna ++;

								if(c->campo[i][auxColuna] == 0)
								{
									c->campo[i][auxColuna] = c->campo[i][auxColuna - 1];
									c->campo[i][auxColuna -1 ] = 0;

								}else if(c->campo[i][auxColuna] == c->campo[i][auxColuna - 1]){
									c->campo[i][auxColuna] = c->campo[i][auxColuna] + c->campo[i][auxColuna -1];
									c->campo[i][auxColuna - 1] = 0;

									if(c->campo[i][auxColuna] == 40)
									{
										c->pontos += 100;
										c->campo[i][auxColuna] = 0;
									}

								}else{
									break;
								}
							}
						}

					}
				}


			break;

			case DESCONHECIDO:
							return;


		}






	imprime_campo(c);
}

