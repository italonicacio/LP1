typedef struct vetor
{
	int tamanho;
	int *dados;

}vetor;

void aloca_vetor(vetor *v, int tam);

void preencher_aleatorio_vetor(vetor *v);

void insertion_sort(vetor *v);

void desaloca(vetor *v);

void lerarquivo(vetor *v, char *nomearquivo);

int busca(vetor *v, int elem);

int busca_recursiva(vetor *v, int elem, int ini, int pos);