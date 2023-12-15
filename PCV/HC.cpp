#include "HC.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <math.h>


using namespace std;

rota *pega_vizinho_reatribuicao(grafo *g, rota *sol)
{
    rota *melhorVizinho = NULL;

    for(int i = 1; i < g->n; ++i)
    {
        for(int j = i + 1; j < g->n; ++j)
        {
            //Fazendo a copia de sol
            rota *rotaVizinho = new rota();
            rotaVizinho->v = new int[g->n];
            for(int k = 0; k < g->n; ++k)
                rotaVizinho->v[k] = sol->v[k];
            //Fim copia rota
            int aux = rotaVizinho->v[i];
            rotaVizinho->v[i] = rotaVizinho->v[j];
            rotaVizinho->v[j] = aux;

            avalia_rota(g, rotaVizinho);
            if(melhorVizinho == NULL)
            {
                melhorVizinho = rotaVizinho;
            }else{
                if(melhorVizinho->aval > rotaVizinho->aval)
                {
                    delete melhorVizinho;
                    melhorVizinho = rotaVizinho;
                }else
                    delete rotaVizinho;
            }
        }
    }
    return melhorVizinho;
}


rota *construcao_vizinho_mais_proximo(grafo *g)
{
    int *r = new int[g->n];
    vector<bool> ehVisitado(g->n, false);


    //Colocando o vertice zero no inicio da rota.
    r[0] = 0;
    ehVisitado[0] = true;

    //Criando a rota
    int verticeAtual = 0;
    for(int i = 1; i < g->n-1; ++i)
    {
            int melhor_vizinho = -1;
            int menor_distancia = INT_MAX;
            //Procura o vizinho mais proximo de verticeAtual
            for(int j = 0; j < g->n; ++j)
            {
                if((g->D[verticeAtual][j] > 0) && (ehVisitado[j] == false))
                {
                    if(menor_distancia > g->D[verticeAtual][j])
                    {
                        menor_distancia = g->D[verticeAtual][j];
                        melhor_vizinho = j;
                    }
                }
            }
            //Adiciona o melhor_vizinho na rota
            r[i] = melhor_vizinho;
            ehVisitado[melhor_vizinho] = true;
    }

    rota *sol = new rota();
    sol->v = r;
    avalia_rota(g, sol);

    return sol;
}

rota *vizinho_aleatorio(grafo *g)
{


    //vetor que vai servir de base para montar a rota aleatoria
    int *r = new int[g->n];
    int vertice_atual = 0;

    vector<bool> ehVisitado(g->n, false);

    // colocando 0 no inicio da rota
    r[0] = 0;
    ehVisitado[0] = true;


    // Visita de forma aleatória um dos 20%
    // melhores vizinhos de cada vértice
    for(int v = 1; v < g->n; ++v)
    {
        vector<vertice> vertices;

        for(int i = 0; i < g->n; ++i)
        {

            //teste para ver se vertice atual diferente de i
            //e se o ehvisitado na posição i ja foi visitado
            if(vertice_atual != i && ehVisitado[i] != true)
            {
                //vertice vet que vai ser armzenado em vet
                // como um vizinho do vertice atual
                vertice vet;
                vet.id = i;
                vet.dist = g->D[vertice_atual][i];
                vertices.push_back(vet);
            }
        }
        //ordenada do menor para o maior com base na distancia
        sort(vertices.begin(), vertices.end(), compare_vertice);



        int pos = 0;

        if(vertices.size() > 1)
        {
            // pos vai receber um valor que é referente a uma posição
            //dos 20% melhores vizinhos do vertice v
            pos = rand() % (int)ceil(vertices.size() * 0.4);
        }

        //vai armazenar na posição v um dos 20% melhores vizinhos
        // ehVisitado na posição do id do vertice vai ser igual a true
        r[v] = vertices[pos].id;
        ehVisitado[vertices[pos].id] = true;
        vertice_atual = vertices[pos].id;



    }


    // é criando um vizinho_aleatorio para poder retorna-lo
    rota *vizinho_aleatorio = new rota();
    vizinho_aleatorio->v = r;

    vizinho_aleatorio->aval = avalia_rota(g, vizinho_aleatorio);




    //vai avaliar a distancia total da rota vizinho_aleatorio


    return vizinho_aleatorio;
}

rota *permuta_vertice(grafo *g,rota *r)
{
    //rota melhor_permuta, que vai ser sempre atribuido a melhor permutação a cada iteração
    rota *melhor_permuta = new rota();
    melhor_permuta->v = new int[g->n];
    melhor_permuta->aval = INT_MAX;


    rota *vizinho_permuta = new rota();
    vizinho_permuta->v = new int[g->n];

    for(int i = 1; i < g->n-1; ++i)
    {
        //a cada interação de i copia a rota r para vizinho_permuta
        //pois vai vizinho_permuta vai ter seus vertices alterados entre si



        for(int j = i+1; j < g->n; ++j)
        {
            for(int l = 0; l < g->n; ++l)
                vizinho_permuta->v[l] = r->v[l];

            if( (j-i) == 1)
            {

                int aux = vizinho_permuta->v[j];
                vizinho_permuta->v[j] = vizinho_permuta->v[i];
                vizinho_permuta->v[i] = aux;



            }else{

                for(int k = 0; k < (j-i)/2 ; ++k)
                {


                    int aux = vizinho_permuta->v[j-k];
                    vizinho_permuta->v[j-k] = vizinho_permuta->v[i+k];
                    vizinho_permuta->v[i+k] = aux;

                }
            }



            //avalia a rota para ver o tamanho dela com base na distancia
            vizinho_permuta->aval = avalia_rota(g, vizinho_permuta);

            //testa se a rota vizinho_permuta é menor que melhor_vizinho
            // e se for menor atribui vizinho_permuta a melhor vizinho
            if(melhor_permuta->aval > vizinho_permuta->aval)
            {
                for(int i = 0; i < g->n; ++i)
                    melhor_permuta->v[i] = vizinho_permuta->v[i];
                melhor_permuta->aval = vizinho_permuta->aval;
            }
        }
    }

    delete vizinho_permuta;

    return melhor_permuta;

}
