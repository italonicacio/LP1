#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "campo.h"
#include "teclado.h"

int main()
{
	JQ c;
	int comando;
	printf("DIGITE QUALQUER TECLA PARA COMEÇAR O JOGO!!!\n");
	printf("DIGITE ESC PARA SAIR DO JOGO!!!\n");



	/*Testando o espaço requirido para o inicio do jogo*/
	if(getch() == 32) {

		/*Alocar dinamicamente o vetor*/
		aloca_campo(&c);
		/*Imprimir o campo*/
		imprime_campo(&c);

		while(1)
		{
			/*aqui ira peg ar o comando e executar o comando e atualizar o campo*/
			comando  = pegar_comando();
			if(comando != ESC && c.jogadas != 40){
				movimento_campo(&c, comando);

			}else{
				break;
			}
		}
	}

	/*desaloca o vetor*/
	printf("Obrigado por jogar!!!\n");
	desaloca(&c);

	return 0;
}
