#include "permuta_PCV.h"
#include <stdio.h>
#include <stdlib.h>
#include "HC.h"
#include "grafo.h"
#include <time.h>

/*
* O objetivo do programa é criar um rota com os 20% melhores vizinhos dos vertices
* e depois fazer a permuta dos vertices da rota para encontrar uma distancia total menor
*/


using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    grafo g; //grafo que vai armazenar na memoria as distancias em uma matriz e o tamanho dela
    ler_grafo_arquivo("pcv50.txt", &g); //função que ler o arquivo que vai copiar a matriz do arquivo para o grafo

    //variavel v do tipo rota aonde vai armazenar o vetor de vertices que a função vai retornar
    // e a rota v vai ser ultilizado como parametro de comparação com a rota r
    // que toda vez que a rota r for menor que a v, delete v e torna v = r
    rota *v = vizinho_aleatorio(&g);

    //variavel auxiliar que vai ser usado no momento da permuta do vertices
    rota *h;


    puts("Calculando as rotas:");
    printf("::: ");
    for(int i = 0; i < g.n; ++i)
        printf("%d ", v->v[i]);
    printf("aval = %d \n\n", v->aval);

    for(int k = 0; k < 10000; ++k)
    {

        //rota r que toda vez que o k for incrementado ele vai criar uma nova rota aleatoria
        rota *r = vizinho_aleatorio(&g);



        while(true)
        {



            h = r;
            //a funcao vai fazer a rota r permutar os vertices e a cada permutação
            //verificar se a distancia total foi alterada pra melhor ou não
            // ela retorna uma rota melhor que a anterior
            //ela é uma função força bruta ainda
            r = permuta_vertice(&g, r);


            if(h->aval > r->aval)
            {
                delete h;

            }else{
                delete r;

                r = h;
                break;
            }
        }

        //testa se a rota r é menor que a v
        // se for melhor vai atribuir r a v
        //e vai mostrar ela na tela

        if(v->aval > r->aval)
        {
            printf("::: ");
            delete v;
            v = r;

            for(int i = 0; i < g.n; ++i)
                printf("%d ", v->v[i]);
            printf("aval = %d \n\n", v->aval);
        }
    }

	return 0;
}
