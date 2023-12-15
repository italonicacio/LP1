
#include "aluno.h"

void calcula_media(aluno *a){
	printf("Media = %f\n", a->media );
	
	a->media = (a->nota1 + a->nota2 + a->nota3)/3;
	
	printf("Media = %f\n", a->media );




}