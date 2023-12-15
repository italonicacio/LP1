#include <vector>

using namespace std;

struct produto{
	int codigo;
	char *nome;
	float preco;
};



void cadastrar_produto(produto p);

void print_produtos();

produto consultar_preco(int cod);
