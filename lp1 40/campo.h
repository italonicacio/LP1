typedef struct campo
{
	int **campo;
	int n;
	int pontos;
	int jogadas;


}JQ;

void aloca_campo(JQ *c);

void imprime_campo(JQ *c);

void desaloca(JQ *c);

void movimento_campo(JQ *c, int comando);

void repeticao(JQ *c, int i, int j);
