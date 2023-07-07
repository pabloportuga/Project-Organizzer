#include <iostream>
#include "../include/Quadro.h"
using namespace std;


int main(){
	Quadro quadro;

	quadro.adicionarColuna("A fazer");

	string titulo = "Teste Título";
	string descricao = "Teste";
	string nomeColuna = "A fazer";

	quadro.adicionarCartao(titulo, descricao, nomeColuna);

	cout << "Quadro:" << std::endl;
    quadro.mostrarQuadro();

	return 0;
}