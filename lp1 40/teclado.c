#include <stdio.h>
#include <conio.h>
#include "teclado.h"

int pegar_comando(){
	int comando;
	comando = getch();
	switch(comando)
	{
		case 72:
			return CIMA;
			
		case 75:
			return ESQUERDA;
			
		case 80:
			return BAIXO;
			
		case 77:
			return DIREITA;
		
		case 27: 
			return ESC;
		
		default:
			return DESCONHECIDO;	
		
	}
}

